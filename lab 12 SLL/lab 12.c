#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct Student
{
    int regId;
    char name[1000];
    char studyCenter[1000];
    char sem[1000];
    char phone[1000];
    struct Student *next;

}* head;

void insert(int regId, char* name, char* studyCenter, char* sem, char* phone)
{

    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    student->regId = regId;
    strcpy(student->name, name);
    strcpy(student->studyCenter, studyCenter);
    strcpy(student->sem, sem);
    strcpy(student->phone, phone);
    student->next = NULL;

    if(head==NULL){
        // if head is NULL
        // set student as the new head
        head = student;
    }
    else{
        // if list is not empty
        // insert student in beginning of head
        student->next = head;
        head = student;
    }

}

void search(int regId)
{
    struct Student * temp = head;
    while(temp!=NULL){
        if(temp->regId==regId){
            printf("Registration Id: %d\n", temp->regId);
            printf("Name: %s\n", temp->name);
            printf("Study center: %s\n", temp->studyCenter);
            printf("Semester: %s\n", temp->sem);
            printf("Phone: %s\n\n\n", temp->phone);
            return;
        }
        temp = temp->next;
    }
    printf("Student with Registration Id %d is not found !!!\n\n\n", regId);
}

void update(int regId)
{

    struct Student * temp = head;
    while(temp!=NULL){

        if(temp->regId==regId){
            printf("Record with Registration %d Found !!!\n", regId);
            printf("Enter new name: ");
            scanf("%s", temp->name);
            printf("Enter new Study center: ");
            scanf("%s", temp->studyCenter);
            printf("Enter new Semester: ");
            scanf("%s", temp->sem);
            printf("Enter new phone number: ");
            scanf("%s", temp->phone);
            printf("Updation Successful!!!\n\n\n");
            return;
        }
        temp = temp->next;

    }
    printf("Student with Registration Id %d is not found !!!\n\n\n", regId);

}


void Delete(int regId)
{
    struct Student * temp1 = head;
    struct Student * temp2 = head;
    while(temp1!=NULL){

        if(temp1->regId==regId){

            printf("Record with Registration Id %d Found !!!\n", regId);

            if(temp1==temp2){
                // this condition will run if
                // the record that we need to delete is the first node
                // of the linked list
                head = head->next;
                free(temp1);
            }
            else{
                // temp1 is the node we need to delete
                // temp2 is the node previous to temp1
                temp2->next = temp1->next;
                free(temp1);
            }

            printf("Record Successfully Deleted !!!\n\n\n");
            return;

        }
        temp2 = temp1;
        temp1 = temp1->next;

    }
    printf("Student with Registration Id %d is not found !!!\n\n\n", regId);

}
void display()
{
    struct Student * temp = head;
    while(temp!=NULL){

        printf("Registration Id: %d\n", temp->regId);
        printf("Name: %s\n", temp->name);
        printf("Study center: %s\n", temp->studyCenter);
        printf("Semester: %s\n", temp->sem);
        printf("Phone: %s\n\n\n", temp->phone);
        temp = temp->next;

    }
}

int main()
{
    head = NULL;
    int choice;
    char name[100];
    char studyCenter[100];
    char sem[100];
    char phone[100];
    int regId;
    printf("1  insert student details\n2  search for student details\n3  delete student details\n4  update student details\n5  display all student details\n6  exit");
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter Registration Id: ");
                scanf("%d", &regId);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter Study center: ");
                scanf("%s", studyCenter);
                printf("Enter Semester: ");
                scanf("%s", sem);
                printf("Enter phone number: ");
                scanf("%s", phone);
                insert(regId, name, studyCenter, sem, phone);
                break;

            case 2:
                printf("Enter Registration Id to search: ");
                scanf("%d", &regId);
                search(regId);
                break;

            case 3:
                printf("Enter Registration Id to delete: ");
                scanf("%d", &regId);
                Delete(regId);
                break;
            case 4:
                printf("Enter Registration Id to update: ");
                scanf("%d", &regId);
                update(regId);
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);
        }

    } while (choice != 0);
}
