Final Submission.
Team members:
Abdullah Mahdi
Molly Clark
Amir Dedeic

Roles:
Abdullah Mahdi - Source code such as the insulinPump and simulation .h and .cpp files. Implementing the logic behind each button press and each timestep.
Molly Clark - Creating the UI and appropriately naming variables as well as writing some MainWindow code to add functionality to the buttons.
Amir Dedeic - Linking the source code and UI in MainWindow as well as revising code to ensure quality.

Organization of the submission:
"comp3004-Final" includes all the files needed to set up the qt/c++ project
"Documentation" includes all folders containing multiple sequence diagrams, state machine diagrams, traceability matrix, and UML Class Diagram

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
