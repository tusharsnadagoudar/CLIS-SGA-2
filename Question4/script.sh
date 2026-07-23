#!/bin/bash

# Create a sample log file
cat > application.log << EOF
INFO: Server started
INFO: User logged in
ERROR: Database connection failed
WARNING: High memory usage
ERROR: Disk space is low
EOF

# Show the latest log entries
echo "===== LATEST LOG ENTRIES ====="
tail -n 5 application.log 2>/dev/null

# Extract ERROR messages and save them in a report
tail -n 5 application.log 2>/dev/null | grep "ERROR" > error_report.txt

echo
echo "===== ERROR REPORT ====="
cat error_report.txt

# Simulate a newly added log entry
echo "ERROR: New connection timeout" >> application.log

# Process the newly added entry
tail -n 1 application.log 2>/dev/null | grep "ERROR" >> error_report.txt

echo
echo "===== UPDATED ERROR REPORT ====="
cat error_report.txt
