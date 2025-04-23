# Debugging Guide for Insulin Pump Simulator Segmentation Faults

This guide provides a systematic approach to identify and fix the segmentation fault in your application.

## Initial Analysis

Based on testing, we've determined that simple Qt applications with QDateTime and database operations work correctly, suggesting the issue is likely in:

1. Custom class implementation
2. Signal/slot connections
3. Memory management
4. UI thread interactions

## Step 1: Build with Debug Symbols

First, ensure your application is built with debug symbols:

1. Open your .pro file
2. Add the following:
   ```
   CONFIG += debug
   ```
3. Rebuild the application

## Step 2: Run with Debugger

To catch the exact location of the segmentation fault:

1. **Using Qt Creator:**
   - Open your project in Qt Creator
   - Set a breakpoint at the start of main()
   - Click "Start Debugging" button
   - Step through execution until crash occurs

2. **Using Visual Studio:**
   - Open project in Visual Studio
   - Set breakpoint at main()
   - Press F5 to start debugging
   - When crash occurs, check call stack

## Step 3: Common Issues to Check

If debugger shows the crash location, use this checklist to identify the cause:

### UI Operations
- **Accessing UI from non-UI thread:** Ensure all UI updates happen in the main thread
- **Deleted UI elements:** Check if you're accessing a widget after it's been deleted

### Signal/Slot Issues
- **Incorrect connection syntax:** Ensure you're using the proper Qt 5/6 connection syntax
- **Disconnected signals:** Verify objects are still alive when signals are emitted
- **Add QObject::connect checking:**
  ```cpp
  bool success = QObject::connect(sender, &Sender::signal, receiver, &Receiver::slot);
  qDebug() << "Connection successful:" << success;
  ```

### QDateTime Issues
- **Thread safety:** QDateTime operations in multiple threads should be synchronized
- **Format strings:** Check for invalid format strings in QDateTime::toString() calls

### Database Issues
- **Connection lifetime:** Ensure db connections remain open when being accessed
- **Query preparation:** Verify all prepared statements are valid before execution
- **Add error reporting:**
  ```cpp
  QSqlQuery query;
  if (!query.exec("YOUR SQL")) {
      qDebug() << "SQL Error:" << query.lastError().text();
  }
  ```

## Step 4: Memory Management

If using manual memory management:
- **Double deletion:** Check if any object is being deleted more than once
- **Use-after-free:** Ensure no object is accessed after deletion
- **Dangling pointers:** Set pointers to nullptr after deletion

Recommend:
1. Use smart pointers where possible
2. Use Q_OBJECT's parent-child system for automatic cleanup
3. Be careful with lambdas capturing UI objects by reference

## Step 5: Systematic Elimination

If you still can't identify the issue:

1. Create a "stepped" version of your app:
   - Start with minimal functionality (just the window)
   - Add one feature at a time (first profiles, then simulation, etc.)
   - When it crashes, you've found the problematic feature

2. Simplify the problematic feature:
   - Comment out code section by section
   - When the app stops crashing, you've found the problem

## Step 6: Common Fixes

- **Smart pointers:**
  ```cpp
  // Replace
  MyClass* obj = new MyClass();
  // With
  std::unique_ptr<MyClass> obj = std::make_unique<MyClass>();
  ```

- **Move QDateTimes to the main thread:**
  ```cpp
  // Thread-safe alternative to direct QDateTime
  QString getTimestamp() {
      QMetaObject::invokeMethod(QCoreApplication::instance(), [&]() {
          return QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
      }, Qt::BlockingQueuedConnection);
  }
  ```

- **Verify connections:**
  ```cpp
  // Add this after each connect call to verify success
  if (!success) {
      qDebug() << "Failed to connect signal to slot";
  }
  ```

## Step 7: Compile with MSVC Instead of MinGW

Sometimes compiler differences matter:
1. Open project with MSVC compiler in Qt Creator
2. Build and test
3. Compare behavior 