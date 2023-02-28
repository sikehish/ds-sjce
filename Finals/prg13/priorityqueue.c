#include<stdio.h>
#include<stdlib.h>

typedef struct Queue {
    int size;
    int f;
    int r;
    int *a;
    
}Queue;

void create(Queue *q)
{
    printf("Enter the size\n");
    scanf("%d",&q->size);
    q->a=malloc(sizeof(int)*q->size);
     q->f = 0;
    q->r = -1;
}
void enqueue(Queue *q, int data) {
    if(q->r==q->size-1)
    {
       printf("Overflow\n");
       printf("Reallocating memory dynamically\n");
       q->a=realloc(q->a,2*q->size*sizeof(int));
       q->r=q->size-1;
       q->size=2*q->size;
    }

    // //EMPTY QUEUE
    // if(q->r==-1)
    //      q->a[++q->r]=data;

    int i;
    for (i = q->r; i >= q->f; i--)
    {
        
        if(q->a[i]>data)
        {
             q->a[i+1]=q->a[i];
            q->a[i]=data;
        }
           
       else
          break;
    }
           q->a[i+1]=data;
           q->r++;
   
}
void dequeue(Queue *q) {
    if (q->f > q->r) {
        printf("Queue Underflow\n");
        return ;
    }
    printf("Deleted data: %d\n",  q->a[q->f++]);
}

void display(Queue *q) {
    int i;
    if(q->f>q->r) {
        printf("Queue empty\n"); return;
    }
    for (i = q->f; i <= q->r; i++) {
        printf("%d ", q->a[i]);
    }
    printf("\n");
}
int main() {
    Queue *q=malloc(sizeof(Queue));
   create(q);
    int choice, data;
    while(1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("\nEnter data  ");
                    scanf("%d", &data);
                    enqueue(q, data);
                    break;
            case 2: 
                    dequeue(q);
                    break;
            case 3: display(q);
                    break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
                     break;
        }
    }
    return 0;
}