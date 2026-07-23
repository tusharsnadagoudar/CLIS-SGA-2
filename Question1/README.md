# Question 1 - Automated Backup and Duplicate Detection

## Objective
The aim of this task is to create a Bash script that processes student submission files, detects duplicate files, backs up only unique files, and generates a summary report.

## Approach
I used a Bash script to process each file in the submissions directory.

- `sha256sum` is used to calculate a hash for every submission.
- An associative array stores the hashes that have already been found.
- If the same hash appears again, the file is treated as a duplicate and is not copied.
- Unique files are copied into the backup directory.
- Errors are redirected to `errors.log`.
- At the end, the script displays the total files processed, duplicate files found, and unique files backed up.

## Result
The test was performed using 3 submission files. Two files contained unique content, while one file was intentionally made identical to another.

The script correctly detected:

- Total files processed: 3
- Duplicate files: 1
- Unique files backed up: 2
- No errors occurred during execution.

The backup directory contained only the two unique files.
