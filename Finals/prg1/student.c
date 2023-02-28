#include<stdio.h>
#include<stdlib.h>

int n=0;

typedef struct Student
{
    int regno;
    char name[30];
    int marks[3];
    float average;
}Student;

void read(Student *sp, int* size)
{
    int i,j;
    printf("Enter the number of students : ");
    scanf("%d",&n);
    if(n>(*size))
    {
      printf("Insufficent space\n");
      printf("Allocating memory Dynamically\n");
      sp=(Student*)realloc(sp,n*sizeof(Student));
      *size= n;
    }
    for(i=0;i<n;i++)
    {
        printf("Enter the Reg no and Name of the student %d\n",i+1);
        scanf("%d%s",&(sp[i].regno),sp[i].name);
        printf("enter the marks of the student in  three tests\n");
        for(j=0;j<3;j++)
        {
            scanf("%d",&(sp[i].marks[j]));
        }
    }
}

void disp(Student *sp)
{
    int i,j;
    if(n==0)
    {
        printf("list empty\n");
        return;
    }
    printf("Regno\tName\t\tTest 1\t\tTest 2\t\tTest 3\t\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%s\t",sp[i].regno,sp[i].name);
        for(j=0;j<3;j++)
        {
          printf("\t%d\t",sp[i].marks[j]);
        }
    printf("\n");
    }
}

void average(Student *sp)
{
    int i,j;
    if(n==0)
    {
        printf("list empty\n");
        return;
    }
    for(i=0;i<n;i++)
    {
        int sum=sp[i].marks[0],min=sp[i].marks[0];
        for(j=1;j<3;j++)
        {
            sum+=sp[i].marks[j];
            if(sp[i].marks[j]<min) min=sp[i].marks[j];
        }
        printf("Sum %d min %d\n",sum,min);
        sp[i].average=(sum-min)/2.0;
        printf("Average of best of the two subject marks of student %d is %lf\n",i+1,sp[i].average);
    }
}

void main()
{
    Student *sp=NULL;
   int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    sp=(Student*)malloc(size*sizeof(Student));
    int ch;
    while(1)
    {
        
        printf("1.Read\n2.Dislay\n3.Average\n4.Exit\nEnter choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: read(sp, &size);
                    break;
            case 2: disp(sp);
                    break;
            case 3: average(sp);
                    break;
            case 4: free(sp);
                     sp=NULL;
                     exit(0);
            default: printf("Invalid Input\n");     
        }
    
    }
}