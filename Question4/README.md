# Question 4 - Log Monitoring and Error Reporting Using Shell Script

## Objective

The aim of this task is to create a shell script that processes an application log file, displays the latest log entries, extracts ERROR messages into a report, and updates the report when a new error is added.

## Approach

I used a Bash shell script to create and process a sample log file named `application.log`.

- A sample log file is created containing INFO, ERROR, and WARNING entries.
- `tail -n 5` is used to display the latest five log entries.
- `grep "ERROR"` is used to extract ERROR messages.
- The extracted errors are stored in `error_report.txt`.
- A new error entry, `ERROR: New connection timeout`, is added to the log file.
- The newly added error is extracted and appended to the error report.

## Result

The script was executed successfully.

The program showed that:

- The latest five log entries were displayed successfully.
- The initial error report contained `ERROR: Database connection failed` and `ERROR: Disk space is low`.
- A new error entry was added to the application log.
- The updated error report also contained `ERROR: New connection timeout`.

The log monitoring and error reporting operations worked as expected.
