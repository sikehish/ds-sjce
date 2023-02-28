#include<stdio.h>
#include<stdlib.h>
typedef struct time
{
 int h,m,s;
}tm;
void read(tm *t)
{
    printf("Enter the time in hrs,min and sec : ");
    scanf("%d%d%d",&t->h,&t->m,&t->s);
}
void display(tm *t)
{
    printf("%dhrs %dmin %dsec ",t->h,t->m,t->s);
}
void update(tm *t)
{
    t->s++;
    if(t->s==60)
    {
        t->s=0;
        t->m++;
    }
    if(t->m==60)
    {
        t->m=0;
        t->h++;
    }
    if(t->h==24)
    {
        t->h=0;t->m=0;t->s=0;
    }
    printf("Updated time : ");
    display(t);
}
void add(tm *t1,tm *t2)
{
    t1->s +=t2->s;
    t1->m +=t2->m;
    t1->h +=t2->h;
    if(t1->s>=60)
    {
        t1->s%=60;
        t1->m++;
    }
    if(t1->m>=60)
    {
        t1->m%=60;
        t1->h++;
    }
    if(t1->h>24)
    {
        t1->h%=24;
    }
    printf("Addition of time : ");
    display(t1);
}
/*void check(tm *t)
{
    if(t->h>=24 ||t->m>=60 ||t->s>=60)       to check if
       exit(0);                           valid time is entered
}*/
void main()
{
    int ch;
    tm t1,t2;
    while(1)
    {
     printf("\n1.Read\n2.Display\n3.Update\n4.Add\n5.Exit\nChoice : ");
     scanf("%d",&ch);
     switch(ch)
     {
        case 1:read(&t1);
               break;
        case 2:display(&t1);
               break;
        case 3:update(&t1);
               break;
        case 4:printf("Enter time 1 : ");
               read(&t1);
               printf("Enter time 2 : ");
               read(&t2);
               add(&t1,&t2);
               break;
        case 5:printf("END");
               exit(0);
        default:printf("Invalid choice !!");
     }
    }
}