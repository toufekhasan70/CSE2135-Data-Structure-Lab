#include<stdio.h>
#include<conio.h>
int n, pos, elem, a[10];
void create()
{
    int i;
    printf("Enter the value of N: ");
    scanf("%d",&n);
    printf("\nEnter %d elements: ", n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    display();
}
void display()
{
    int i;
    printf("\nThe array is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n-------------------------------\n");
}
void insertion()
{
    int i;
    printf("Enter a valid position where element to be inserted: ");
    scanf("%d", &pos);
    if (pos>n)
    {
        printf("\nEntered position is not valid\n");
        insertion();
    }
    printf("Enter the value to be inserted: ");
    scanf("%d", &elem);
    for(i=n; i>=pos ; i--)
    {
            a[i+1] = a[i];
    }
    a[pos] = elem;
    n+=1;
    display();
}
void deletion()
{
    int i;
    printf("Enter a valid position from where element to be deleted: ");
    scanf("%d", &pos);
    if (pos>=n)
    {
        printf("\nEntered position is not valid\n");
        deletion();
    }
    while(pos<n){
        a[pos-1]=a[pos];
        pos++;
    }
    n-=1;
    display();
}
int main()
{
    int ch;
    while(1)
    {
    printf("1. Create\n2. Display\n3. Insertion\n4. Delete\n5. Exit");
    printf("\nEnter your Choice: ");
    scanf("%d",&ch);
    printf("\n");
    switch(ch)
    {
        case 1: create();
        break;
        case 2: display();
        break;
        case 3: insertion();
        break;
        case 4: deletion();
        break;
        case 5: exit(0);
        }

    }
}
