/*Problem 3: Hospital Patient Registration System (Singly Linked List)
Problem Statement
A hospital registers patients as they arrive. Each patient's information includes:
Patient ID
Patient Name
Age
Disease
Develop a C program using a Singly Linked List to:
Register a new patient.
Display all registered patients.
Search for a patient by Patient ID.
Discharge a patient.
Count the total number of patients.
Exit.*/
#include<stdio.h>
#include<stdlib.h>
struct Hospital{
    int patient_id;
    char patient_name[100];
    int age;
    char disease[200];
    struct Hospital *next;
};
int main(){
    int n,choice,count=0,id;
    struct Hospital *head=NULL,*temp=NULL, *newreg=NULL;
    printf("Enter no of patient records: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        newreg=(struct Hospital *)malloc(sizeof(struct Hospital));
        printf("Enter patient ID: ");
        scanf("%d",&newreg->patient_id);
        printf("Enter patient name:");
        scanf("%s",newreg->patient_name);
        printf("Enter age: ");
        scanf("%d",&newreg->age);
        printf("Enter disease name: ");
        scanf("%s",newreg->disease);
        newreg->next=NULL;
        if(head==NULL){
            head=newreg;
            temp=newreg;
        }
        else{
            temp->next=newreg;
            temp=newreg;
        }
    }
    while(1)
    { 
        printf("\n-----SELECT FROM MENU-----\n");
        printf("1.Register a new patient.\n");
        printf("2.Display all registered patients.\n");
        printf("3.Search for a patient by Patient ID.\n");
        printf("4.Discharge a patient.\n");
        printf("5.Count the total number of patients.\n");
        printf("6.Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            //reg a new patient
            case 1:
              newreg= (struct Hospital *)malloc(sizeof(struct Hospital));
               if(newreg == NULL)
                {
                    printf("Memory allocation failed\n");
                    return 1;
                }
                printf("Enter Patient ID: ");
                scanf("%d", &newreg->patient_id);
                printf("Enter Patient Name: ");
                scanf("%s", newreg->patient_name);
                printf("Enter Age: ");
                scanf("%d",&newreg->age);
                printf("Enter Disease: ");
                scanf("%s",newreg->disease);
                newreg->next = NULL;
              if(head==NULL){
                head = newreg;
              }
              else{
                temp=head;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=newreg;
              }
              printf("New Patient record inserted succesfully.\n");
              break;
            case 2:
              temp=head;
              printf("\n---------------HOSPITAL PATIENT RECORD-----------\n");
              while(temp!=NULL){
                printf("Patient ID: %d | Patient NAme: %s | PAtient age : %d | Patient disease : %s",temp->patient_id,temp->patient_name,temp->age,temp->disease);
                printf("\n");
                temp=temp->next;
              }
              break;
            case 3:
              temp=head;
              printf("Enter patient id to search: ");
              scanf("%d",&id);
              if(head==NULL){
                printf("Patient record not found.\n");
                break;
              }
              while(temp!=NULL){
                if(temp->patient_id==id){
                printf("Patient ID: %d | Patient NAme: %s | PAtient age : %d | Patient disease : %s",temp->patient_id,temp->patient_name,temp->age,temp->disease);
                printf("\n");
                break;
                }
                temp=temp->next;
              }
              if(temp==NULL){
                printf("Patient record not found.\n");
              }
              break;
            case 4:
               temp=head;
               printf("Enter patient id to delete: ");
               scanf("%d",&id);
               if(head==NULL){
                printf("NO record to delete.\n");
               }
                else if(head->patient_id == id)
                {
                    newreg = head;
                    head = head->next;
                    free(newreg);
                    printf("Patient discharged.\n");
                }
                else
                {
                    temp = head;
                    while(temp->next != NULL && temp->next->patient_id !=id)
                    {
                        temp = temp->next;
                    }
                    if(temp->next == NULL)
                    {
                        printf("Patient not found.\n");
                    }
                    else
                    {
                        newreg = temp->next;
                        temp->next = newreg->next;
                        free(newreg);
                        printf("Patient record deleted.\n");
                    }
                }
                break;
            case 5:
                temp=head;
                while(temp!=NULL){
                    count++;
                    temp=temp->next;
                }
                printf("NUMBER OF PATIENT IN HOPSITAL REGISTER: %d\n",count);
                printf("\n");
                break;
            case 6:
                temp=head;
                while(temp!=NULL){
                    newreg=temp;
                    temp=temp->next;
                    free(newreg);
                }
                printf("EXITING THE REGITER.....\n");
                exit(0);
            default: 
                printf("Invalid choice.\n");
                printf("\nCHOOSE FROM MENU\n");
        }
    }
    return 0;
}