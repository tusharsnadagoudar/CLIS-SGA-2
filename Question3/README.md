# Question 3 - Employee Record File Management Using System Calls

## Objective

The aim of this task is to create and manage employee records in a file using C system calls, update a specific employee record, and retrieve the updated record.

## Approach

I used a C program to store employee records in a file named `employees.dat`.

- Three employee records are initially written to the file using `write()`.
- `lseek()` is used to directly access the second employee record.
- Employee ID 2 (Priya) is updated with a salary of 45000.
- `read()` is used to retrieve the updated employee record.
- The file is closed using `close()` after all operations are completed.

## Result

The program was tested successfully.

The program showed that:

- Employee records were written successfully.
- Employee ID 2 was updated successfully.
- The updated record was retrieved correctly.
- Retrieved employee: ID 2, Priya, Salary 45000.00.

The employee record file operations worked as expected.
