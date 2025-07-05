#  Student Grade Management System (C)

This is a simple command-line application written in C for managing student grades using the **Albanian grading scale** (4–10). It allows users to enter student names and their scores in Math, Physics, and Computer Science. The program calculates the average, converts it into a grade, and saves all records to a text file.

---

## Features

- Add a new student with 3 subject scores
- Automatically calculate average and convert to Albanian grade
- Save records to a file (`notat.txt`)
- View all saved student records in a table
- Menu-based interface (easy to use)

---

## Grading Scale (Albanian System)

| Average (%) | Grade |
|-------------|-------|
| 90–100      | 10    |
| 80–89       | 9     |
| 70–79       | 8     |
| 60–69       | 7     |
| 50–59       | 6     |
| 40–49       | 5     |
| Below 40    | 4     |

---

## Requirements

- C compiler (GCC or any standard C compiler)

---

## How to Compile & Run

```bash
gcc grading_system.c -o grade-manager
./grade-manager

