/*
Problem 2: Student Attendance Management System (Singly Linked List)

Operations:
1. Register a new student.
2. Display all student records.
3. Search a student using Roll Number.
4. Delete a student record.
5. Update the attendance percentage.
6. Display the total number of registered students.
7. Exit.
*/
#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int Roll_No;
    char Student_Name[100];
    char Department[100];
    float Attendance;
    struct Student *next;
};
int main()
{
    int n, choice, roll, count, i;
    struct Student *head = NULL, *temp = NULL, *newstudent = NULL, *ptr = NULL;
    printf("Enter number of students: ");
    scanf("%d", &n);
    // Create initial list
    for(i = 0; i < n; i++)
    {
        newstudent = (struct Student *)malloc(sizeof(struct Student));
        if(newstudent == NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }
        printf("\nEnter Roll Number: ");
        scanf("%d", &newstudent->Roll_No);
        printf("Enter Student Name: ");
        scanf("%s", newstudent->Student_Name);
        printf("Enter Department: ");
        scanf("%s", newstudent->Department);
        printf("Enter Attendance Percentage: ");
        scanf("%f", &newstudent->Attendance);
        newstudent->next = NULL;
        if(head == NULL)
        {
            head = newstudent;
            temp = newstudent;
        }
        else
        {
            temp->next = newstudent;
            temp = newstudent;
        }
    }
    while(1)
    {
        printf("\n----- MENU -----\n");
        printf("1. Register a new student\n");
        printf("2. Display all student records\n");
        printf("3. Search student using Roll Number\n");
        printf("4. Delete a student record\n");
        printf("5. Update attendance percentage\n");
        printf("6. Display total number of students\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            // Register a new student
            case 1:
                newstudent = (struct Student *)malloc(sizeof(struct Student));
                if(newstudent == NULL)
                {
                    printf("Memory allocation failed\n");
                    return 1;
                }
                printf("Enter Roll Number: ");
                scanf("%d", &newstudent->Roll_No);
                printf("Enter Student Name: ");
                scanf("%s", newstudent->Student_Name);
                printf("Enter Department: ");
                scanf("%s", newstudent->Department);
                printf("Enter Attendance Percentage: ");
                scanf("%f", &newstudent->Attendance);
                newstudent->next = NULL;
                if(head == NULL)
                {
                    head = newstudent;
                }
                else
                {
                    temp = head;
                    while(temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    temp->next = newstudent;
                }
                printf("Student Registered Successfully.\n");
                break;
            // Display all student records
            case 2:
                if(head == NULL)
                {
                    printf("No records found.\n");
                }
                else
                {
                    temp = head;

                    printf("\nStudent Records:\n");

                    while(temp != NULL)
                    {
                        printf("Roll Number : %d | Student Name : %s |Department : %s |Attendance : %.2f %% \n", temp->Roll_No,temp->Student_Name,temp->Department,temp->Attendance);
                        printf("\n");
                        temp = temp->next;
                    }
                }
                break;
            // Search student by Roll Number
            case 3:
                printf("Enter Roll Number to search: ");
                scanf("%d", &roll);
                temp = head;
                while(temp != NULL)
                {
                    if(temp->Roll_No == roll)
                    {
                        printf("Student Found.\n");
                        printf("Roll Number : %d\n", temp->Roll_No);
                        printf("Student Name : %s\n", temp->Student_Name);
                        printf("Department : %s\n", temp->Department);
                        printf("Attendance : %.2f %%\n", temp->Attendance);
                        break;
                    }
                    temp = temp->next;
                }
                if(temp == NULL)
                {
                    printf("Student not found.\n");
                }
                break;
            // Delete a student record
            case 4:
                printf("Enter Roll Number to delete: ");
                scanf("%d", &roll);
                if(head == NULL)
                {
                    printf("List is empty.\n");
                }
                else if(head->Roll_No == roll)
                {
                    ptr = head;
                    head = head->next;
                    free(ptr);
                    printf("Student record deleted.\n");
                }
                else
                {
                    temp = head;
                    while(temp->next != NULL && temp->next->Roll_No != roll)
                    {
                        temp = temp->next;
                    }
                    if(temp->next == NULL)
                    {
                        printf("Student not found.\n");
                    }
                    else
                    {
                        ptr = temp->next;
                        temp->next = ptr->next;
                        free(ptr);
                        printf("Student record deleted.\n");
                    }
                }
                break;
            // Update attendance percentage
            case 5:
                printf("Enter Roll Number: ");
                scanf("%d", &roll);
                temp = head;
                while(temp != NULL)
                {
                    if(temp->Roll_No == roll)
                    {
                        printf("Current Attendance = %.2f %%\n", temp->Attendance);
                        printf("Enter new Attendance Percentage: ");
                        scanf("%f", &temp->Attendance);
                        printf("Attendance Updated Successfully.\n");
                        break;
                    }
                    temp = temp->next;
                }
                if(temp == NULL)
                {
                    printf("Student not found.\n");
                }
                break;
            // Count total students
            case 6:
                count = 0;
                temp = head;
                while(temp != NULL)
                {
                    count++;
                    temp = temp->next;
                }
                printf("Total number of students = %d\n", count);
                break;
            // Exit
            case 7:
                // Free allocated memory
                temp = head;
                while(temp != NULL)
                {
                    ptr = temp;
                    temp = temp->next;
                    free(ptr);
                }
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid Choice.\n");
        }
    }
    return 0;
}