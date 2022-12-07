#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

void read(int*, int*);
void display(int*, int);
void insert(int*, int*);
void del(int*, int*);
void search(int*, int);

void main()

{

            int choice,a[SIZE], n=0;
            while(1)
            {
             printf("\n The choices are \n 1.Read\n2.Display\n3.Insert\n4.Delete\n5.Search\n6.Exit\n");
           printf("\nEnter your choice: ");
           scanf("%d", &choice);
           switch(choice)
           {
             case 1: read(a, &n);
                  break;
            case 2: display(a,n);
                  break;
           case 3: insert(a, &n);
                  break;
           case 4:del(a, &n);
                  break;
           case 5:search(a, n);
                  break;
           case 6:exit(0);
                  break;
        default:printf("\nPlease enter a valid choice:");
                        }
            }
}

void read(int *a, int *n)

{
            int i;
            printf("\nEnter the number of elements: ");
            scanf("%d", n);
            printf("\nEnter the elements: \n");
            for(i=0; i<*n; i++)
            {
                        scanf("%d", &a[i]);
            }
}

void display(int* a, int n)
{
            int i;
            if(n == 0)
            {
                    printf("\nNo elements to display");
                        return;
            }
            printf("\nArray elements are: ");
            for(i=0; i<n;i++)
                        printf("%d\t ", a[i]);
}

void insert(int* a, int* n)
{
            int i,pos;
            if(*n == SIZE)
            {
        printf("\nArray is full. Insertion is not possible");
                        return;
            }
            do
            {
printf("\nEnter a valid position where element to be inserted:    ");
scanf("%d", &pos);
            }while(pos > *n);
            int elem;
            printf("\nEnter the value to be inserted:   ");
            scanf("%d", &elem);
            for(i=*n-1; i>=pos ; i--)
        {
                       a[i+1] = a[i];
            }
            a[pos] = elem;
            (*n)++;
           display(a, *n);
}

void del(int* a, int* n)

{
            int i,pos;
            if(*n == 0)
            {
                        printf("\nArray is empty and no elements to delete");
                        return;
            }
            do
            {
                        printf("\nEnter a valid position from where element to be deleted:    ");

                        scanf("%d", &pos);

            }while(pos>=(*n));
          int elem = a[pos];
         printf("\nDeleted element is : %d \n", elem);

            for( i = pos; i< (*n)-1; i++)
            {
                        a[i] = a[i+1];
            }            *n = *n-1;

            display(a, *n);

} 

void search(int* a, int n){

     int i, flag = 0,key;
     printf("Enter the key to be searched \n");
     scanf("%d",&key);
    for (i = 0; i < n; i++)
    {
        if (key == *(a + i))
        {
            printf(" %d found at %d ", key, i + 1);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf(" element not found ");
    }
}