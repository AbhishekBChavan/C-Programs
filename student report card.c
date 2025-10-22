#include <stdio.h>
#include <string.h>

// Define a structure for student details
struct Student {
    char name[70];
    int rollNumber;
    int marks[7]; // Assuming 7 subjects
    int totalMarks;
    float percentage;
    char grade;
};

// Function to calculate total marks, percentage, and grade
void calculateResults(struct Student *s) {
    s->totalMarks = 0;
    for (int i = 0; i <7; i++) {
        s->totalMarks += s->marks[i];
    }
    s->percentage = (s->totalMarks / 500.0) * 100; // Assuming each subject is out of 100
    
    if (s->percentage >= 90) {
        s->grade = 'A';
    } else if (s->percentage >= 80) {
        s->grade = 'B';
    } else if (s->percentage >= 70) {
        s->grade = 'C';
    } else if (s->percentage >= 60) {
        s->grade = 'D';
    } else {
        s->grade = 'F';
    }
}

// Function to display the report card
void displayReportCard(struct Student s) {
    printf("\n--- Student Report Card ---\n");
    printf("Name: %s\n", s.name);
    printf("Roll Number: %d\n", s.rollNumber);
    printf("Marks in Subjects:\n");
    printf("Subject 1: %d\n", s.marks[0]);
    printf("Subject 2: %d\n", s.marks[1]);
    printf("Subject 3: %d\n", s.marks[2]);
    printf("Subject 4: %d\n", s.marks[3]);
    printf("Subject 5: %d\n", s.marks[4]);
    printf("Subject 6: %d\n", s.marks[5]);
    printf("Subject 7: %d\n", s.marks[6]);
    printf("Total Marks: %d/500\n", s.totalMarks);
    printf("Percentage: %.2f%%\n", s.percentage);
    printf("Grade: %c\n", s.grade);
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    struct Student students[n];
    
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]s", students[i].name); // To read full name with spaces
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Enter marks for 7 subjects (out of 100 each):\n");
        for (int j = 0; j < 7; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &students[i].marks[j]);
        }
        calculateResults(&students[i]);
    }
    
    // Display report cards for all students
    for (int i = 0; i < n; i++) {
        displayReportCard(students[i]);
    }
    
    return 0;
}
