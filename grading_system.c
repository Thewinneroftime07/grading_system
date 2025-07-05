#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

// Define the student struct
struct Student {
    char name[MAX_NAME_LEN];
    float math, physics, cs;
};

// Calculate average of the student
float average(struct Student s) {
    return (s.math + s.physics + s.cs) / 3.0f;
}

// Convert average to Albanian grade scale (5–10)
int grade(struct Student s) {
    float avg = average(s);
    if (avg >= 90) return 10;
    else if (avg >= 80) return 9;
    else if (avg >= 70) return 8;
    else if (avg >= 60) return 7;
    else if (avg >= 50) return 6;
    else if (avg >= 40) return 5;
    else return 4;
}

// Save student record to file
void saveStudent(struct Student s) {
    FILE *f = fopen("notat.txt", "a"); //`a` mode to append to the file, not overwrite, if it doesn't exist, it will be created
    if (f == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(f, "%s %.2f %.2f %.2f\n", s.name, s.math, s.physics, s.cs);
    fclose(f);
}

// Display all saved students
void viewStudents() {
    FILE *f = fopen("nota.txt", "r");
    if (f == NULL) {
        printf("No saved student records found.\n");
        return;
    }

    struct Student s;
    printf("\nSaved Student Records:\n");
    printf("%-15s %-8s %-8s %-8s %-8s %-10s\n", "Name", "Math", "Physics", "CS", "Avg", "Grade");

    while (fscanf(f, "%s %f %f %f", s.name, &s.math, &s.physics, &s.cs) == 4) {
        float avg = average(s);
        int g = grade(s);
        printf("%-15s %-8.2f %-8.2f %-8.2f %-8.2f %-10d\n", s.name, s.math, s.physics, s.cs, avg, g);
    }

    fclose(f);
}

// Main menu
int main() {
    int choice;

    while (1) {
        printf("\n🎓 Student Grade Management (Albanian Grading System)\n");
        printf("1. Add student\n");
        printf("2. View students\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            struct Student s;
            printf("Enter student name (no spaces): ");
            scanf("%s", s.name);
            printf("Enter Math score: ");
            scanf("%f", &s.math);
            printf("Enter Physics score: ");
            scanf("%f", &s.physics);
            printf("Enter Computer Science score: ");
            scanf("%f", &s.cs);

            saveStudent(s);
            printf("Student saved successfully.\n");

        } else if (choice == 2) {
            viewStudents();

        } else if (choice == 3) {
            printf("Exiting program.\n");
            break;

        } else {
            printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}