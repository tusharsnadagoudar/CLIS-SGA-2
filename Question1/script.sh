#!/bin/bash

# Create sample submission and backup directories
mkdir -p submissions backup

# Create sample student submissions
echo "Assignment submitted by Student A" > submissions/studentA.txt
echo "Assignment submitted by Student B" > submissions/studentB.txt

# Create an intentional duplicate for testing
cp submissions/studentA.txt submissions/studentC.txt

# Initialize report and error files
> report.txt
> errors.log

TOTAL=0
DUPLICATES=0
BACKED_UP=0

declare -A hashes

# Process every submission
for file in submissions/*; do
    if [ -f "$file" ]; then
        TOTAL=$((TOTAL + 1))

        hash=$(sha256sum "$file" 2>>errors.log | awk '{print $1}')

        if [ -n "${hashes[$hash]}" ]; then
            echo "Duplicate: $file matches ${hashes[$hash]}" >> report.txt
            DUPLICATES=$((DUPLICATES + 1))
        else
            hashes[$hash]="$file"
            cp "$file" backup/ 2>>errors.log
            BACKED_UP=$((BACKED_UP + 1))
        fi
    fi
done

# Generate summary report
{
echo "Total files processed: $TOTAL"
echo "Duplicate files: $DUPLICATES"
echo "Unique files backed up: $BACKED_UP"
} >> report.txt

echo "===== PROCESSING REPORT ====="
cat report.txt

echo
echo "===== BACKED UP FILES ====="
ls -l backup

echo
echo "===== ERROR LOG ====="
if [ -s errors.log ]; then
    cat errors.log
else
    echo "No errors occurred."
fi
