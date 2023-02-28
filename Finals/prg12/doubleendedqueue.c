#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
    int f, r, size, *a;
}Queue;

void create(Queue *q)
{
   // int size1;
    printf("Enter the size\n");
    scanf("%d",&q->size);
    q->a=malloc(sizeof(int)*q->size);
     q->f=0; q->r=-1;
}

void dequeueR(Queue *q)
{
    if(q->r==-1)
    {
        printf("Deletion not possible\n");
        return;
    }
    printf("%d is the deleted element\n",q->a[q->r--]);
}

void enqueueF(Queue *q,int data)
{ 
   if(q->f==0)
   {
        printf("Insertion not possible\n");
       return;
   }
   else q->a[--q->f]=data;
  
   
}
void enqueueR(Queue *q,int data)
{
 
    if(q->r==q->size-1)
    {
       printf("Overflow\n");
       printf("Reallocating memory dynamically\n");
       q->a=realloc(q->a,2*q->size*sizeof(int));
       q->r=q->size-1;
       q->size=2*q->size;
    }
    
       q->a[++(q->r)]=data;
}

void dequeueF(Queue *q)
{
    int x;
     if(q->f > q->r)
     {
          printf("Deletion not possible\n");
          q->f=0;q->r=-1;
     }
     else printf("Deleted element is %d \n",q->a[q->f++]);
}

void display(Queue *q)
{
    if(q->f>q->r) {
        printf("Empty DEqueue!\n"); return;
    }
    for(int i=q->f;i<=q->r;i++) printf("%d ",q->a[i]);
    printf("\n");
}


void main()
{
    int k,ch;
    Queue *q=(Queue *)malloc(sizeof(Queue));
    create(q);

    while(1)
    {
        printf("\n1.Enqueue front\n2.Enqueue Rear\n3.Dequeue front\n4.Dequeue Rear\n5.Display\n6.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {

            case 1: printf("Enter the value to be enqueued at the front\n");
                    scanf("%d",&k);
                    enqueueF(q,k);
                    break;

            case 2: printf("Enter the value to be enqueued at the rear\n");
                    scanf("%d",&k);
                    enqueueR(q,k);
                    break;

            case 3:dequeueF(q);
                   break;

            case 4: dequeueR(q);
                    break;

            case 5:display(q);
                    break;

            case 6:
            printf("Exiting...\n");
            exit(0);
                
            default:printf("Invalid Choice\n");
                    break;
        }
    }
}