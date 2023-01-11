//Linear Queue Static Memory Allocation
#include<stdio.h>
#include<stdlib.h>
struct q
{
    int f,r,n,a[10];
};

void disp(struct q *q)
{
    if(q->f>q->r)
       printf("Queue Empty\n");
    else
    {
        printf("Queue : ");
        for(int i=q->f;i<=q->r;i++)
        {
           printf("%d\t",q->a[i]);
        }
    }
    printf("\n");
}
void insert(struct q *q,int k)
{
    if(q->r==(q->n)-1)
        printf("Queue Full\n");
    else
      q->a[++q->r]=k;
}
void del(struct q *q)
{
    if(q->f>q->r)
    {
        printf("Deletion complete!! Queue empty\n");
        q->f=0;q->r=-1;
    }
    else
    {
       printf("Deleted element is: %d\n",q->a[q->f]);
       q->f++;
    }
}
void main()
{
    struct q *q=malloc(sizeof(struct q));
    printf("Enter size of queue : ");
    scanf("%d",&q->n);
    q->f=0,q->r=-1;
    int k,ch;
    while(1)
    {
        printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
        printf("Enter the choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter element to insert : ");
                   scanf("%d",&k);
                   insert(q,k);
                   break;
            case 2:del(q);
                   break;
            case 3:disp(q);
                   break;
            case 4:exit(0);
            default:printf("Invalid choice !!\n");
        }
    }
}
-------------------------------------------------------------------------------------------------------
//Linear Queue Static Dynamic Allocation
#include<stdio.h>
#include<stdlib.h>
struct q
{
    int f,r,n,*a;
};
void create(struct q *q)
{
    printf("Enter size of queue : ");
    scanf("%d",&q->n);
    q->a=malloc((q->n)*sizeof(int));
    q->f=0;
    q->r=-1;
}
void disp(struct q *q)
{
    if(q->f>q->r)
       printf("Queue Empty\n");
    else
    {
        printf("Queue : ");
        for(int i=q->f;i<=q->r;i++)
        {
           printf("%d\t",q->a[i]);
        }
    }
    printf("\n");
}
void insert(struct q *q,int k)
{
    if(q->r==(q->n)-1)
    {
        printf("Queue Full\n");
        printf("Allocating Memory Dynamically\n");
        int *t = realloc(q->a,2*(q->n)*sizeof(int));
        q->r=q->n-1;
        q->n=2*q->n;
        q->a=t;
    }
      q->a[++q->r]=k;
}
void del(struct q *q)
{
    if(q->f>q->r)
    {
        printf("Deletion complete!! Queue empty");
        q->f=0;q->r=-1;
    }
    else
    {
       printf("Deleted element is: %d\n",q->a[q->f]);
       q->f++;
    }
}
void main()
{
    struct q *q=malloc(sizeof(struct q));
    create(q);
    int k,ch;
    while(1)
    {
        printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
        printf("Enter the choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter element to insert : ");
                   scanf("%d",&k);
                   insert(q,k);
                   break;
            case 2:del(q);
                   break;
            case 3:disp(q);
                   break;
            case 4:exit(0);
            default:printf("Invalid choice !!\n");
        }
    }
}
---------------------------------------------------------------------------------------------------------
//Circular Queue Static Memory Allocation
#include<stdio.h>
#include<stdlib.h>
struct q
{
    int f,r,n,c,a[10];
};
void disp(struct q *q)
{
    
    if(q->c==0)
        printf("Queue Empty\n");
    else if(q->c>0)
    {
        int i=q->f;
        printf("Circular Queue : ");
       while(i!=q->r)     
        {  
           printf("%d\t",q->a[i]);
           i=(i+1)%q->n;
        }
    printf("%d\t\n",q->a[q->r]);
    }
}
void insert(struct q *q,int k)
{
    if(q->c==q->n)
        printf("Queue Full\n");
    else
    {
        q->r=(q->r+1)%q->n;
        q->a[q->r]=k;
        q->c++;
    }
}
void del(struct q *q)
{
    if(q->c==0)
    {
        q->r=-1;q->f=0;
        printf("Deletion complete!! queue empty\n");
    }
    else
    {
        printf("Deleted element is: %d\n",q->a[q->f]);
        q->f=(q->f+1)%q->n;
        q->c--;
    }
}
void main()
{
    struct q *q=malloc(sizeof(struct q));
    printf("Enter size of queue : ");
    scanf("%d",&q->n);
    q->f=0,q->r=-1,q->c=0;
    int k,ch;
    while(1)
    {
        printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
        printf("Enter choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter element to insert : ");
                   scanf("%d",&k);
                   insert(q,k);
                   break;
            case 2:del(q);
                   break;
            case 3:disp(q);
                   break;
            case 4:exit(0);
            default:printf("Invalid Choice\n");
        }
    }
}
-------------------------------------------------------------------------------------------------------
//Circular Queue Dynamic Memory Allocation
#include<stdio.h>
#include<stdlib.h>
struct q
{
    int f,r,n,c,*a;
};
void create(struct q *q)
{
    printf("Enter size of queue : ");
    scanf("%d",&q->n);
    q->a=malloc((q->n)*sizeof(int));
    q->f=0; q->r=-1;q->c=0;
}
void disp(struct q *q)
{
    
    if(q->c==0)
        printf("Queue Empty\n");
    else if(q->c>0)
    {
        int i=q->f;
        printf("Circular Queue : ");
       while(i!=q->r)     
        {  
           printf("%d\t",q->a[i]);
           i=(i+1)%q->n;
        }
    printf("%d\t\n",q->a[q->r]);
    }
}
void insert(struct q *q,int k)
{
    if(q->c==q->n)
    {
        printf("Queue Full\n");
        printf("Allocating Memory Dynamically\n");
        int *t = realloc(q->a,2*(q->n)*sizeof(int));
        q->r=q->n-1;
        q->n=2*q->n;
        q->a=t;
    } 
        q->r=(q->r+1)%q->n;
        q->a[q->r]=k;
        q->c++;
    
}
void del(struct q *q)
{
    if(q->f>q->r)
    {
        printf("Deletion complete!! Queue empty");
        q->f=0;q->r=-1;
    }
    else
    {
       printf("Deleted element is: %d\n",q->a[q->f]);
       q->f++;
    }
}
void main()
{
    struct q *q=malloc(sizeof(struct q));
    create(q);
    int k,ch;
    while(1)
    {
        printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
        printf("Enter choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter element to insert : ");
                   scanf("%d",&k);
                   insert(q,k);
                   break;
            case 2:del(q);
                   break;
            case 3:disp(q);
                   break;
            case 4:exit(0);
            default:printf("Invalid Choice\n");
        }
    }
}
