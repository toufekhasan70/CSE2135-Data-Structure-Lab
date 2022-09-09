
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void beginsert ();
void begin_delete();
void display();

void main ()
{
    int choice =0;
    printf("\n.....Main Menu.....\n");
    while(choice != 4)
    {
        printf("\nChoose one option from the following list :\n");
        printf("\n=======\n");
        printf("\n1.Insert in begining\n2.Delete from the begining\n3.Show\n4.Exit\n");
               printf("\nEnter your choice: ");
               scanf("\n%d",&choice);
               switch(choice)
        {
        case 1:
            beginsert();
                break;
            case 2:
                begin_delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Please enter valid choice:");
            }
    }
}

void beginsert()
{
    struct node *ptr;
    int item;
    ptr = (struct node *) malloc(sizeof(struct node *));
    if(ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value\n");
        scanf("%d",&item);
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("\nNode inserted\n");
    }

}

void begin_delete()
{
    struct node *ptr;
    if(head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\nNode deleted from the begining ...\n");
    }
}

void display()
{
    struct node *ptr;
    ptr = head;
    if(ptr == NULL)
    {
        printf("Nothing to print\n");
    }
    else
    {
        printf("\nprinting values . . . . .\n");
        while (ptr!=NULL)
        {
            printf("\n%d",ptr->data);
            ptr = ptr -> next;
        }
    }
}
