# Challenge 01 – Student Marks Calculator

## Problem Statement

Write a C program to accept the marks obtained by a student in five subjects and calculate the total marks, average marks, and overall percentage. Each subject is treated as being out of 100 marks, giving a maximum total of 500 marks.

## Algorithm

1. Start.
2. Declare variables for the five subject marks, total, average, and percentage.
3. Read the marks for each of the five subjects.
4. Add the five marks to calculate the total.
5. Divide the total by 5 to calculate the average.
6. Divide the total by 500 and multiply by 100 to calculate the percentage.
7. Display the total, average, and percentage.
8. Stop.

## Input Description

The program reads five numeric mark values from standard input. The values represent subjects 1 through 5, with each subject out of 100 marks.

## Output Description

The program displays the total marks, average marks, and percentage. Each result is printed with two digits after the decimal point.

## Example Input/Output

Example input:

```text
78
85
92
66
79
```

Example output:

```text
Enter marks for subject 1: Enter marks for subject 2: Enter marks for subject 3: Enter marks for subject 4: Enter marks for subject 5: Total Marks = 400.00
Average Marks = 80.00
Percentage = 80.00%
```

## Program Explanation

The program stores the five marks in floating-point variables so decimal marks are supported. It adds the marks for the total, calculates the average from that total, and calculates the percentage using 500 as the maximum total. The results are then printed with two decimal places.
