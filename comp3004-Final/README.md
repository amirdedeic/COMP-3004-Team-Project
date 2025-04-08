# Insulin Pump Simulator Test Suite

This test suite contains simplified applications to help identify the source of the segmentation fault in the main application.

## Test Components

1. **Basic Qt Application (test_basic.pro)**
   - Contains only basic QWidgets
   - No custom classes
   - No database connections
   - No QDateTime usage

2. **QDateTime Test (test_datetime.pro)**
   - Basic Qt application with QDateTime usage
   - Tests if QDateTime is causing issues

3. **Database Test (test_database.pro)**
   - Includes QDateTime and database connection
   - Tests if the SQLite connection is causing issues

## Running the Tests

### On Windows
Run the batch script:
```
run_tests.bat
```

### On Linux/Mac
Run the shell script:
```
chmod +x run_tests.sh
./run_tests.sh
```

## Analyzing Results

If any test crashes with a segmentation fault, that indicates which component is likely causing the issue in the main application:

- If Test 1 fails: The issue is with the basic Qt setup or main window initialization
- If Test 2 fails: The issue is likely related to QDateTime usage
- If Test 3 fails: The issue is likely related to database connections

If all tests pass but the main application still fails, the issue is likely related to:
1. Custom classes or inheritance
2. Signal/slot connections
3. More complex interactions between components
4. Memory management issues

## Next Steps

After identifying which component is problematic, create a more specific test that gradually adds complexity until the issue is reproduced. 