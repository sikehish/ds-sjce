#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int f,r,size,count,*a;
}Queue;

void create(Queue* q){
    printf("Enter the size of the queue: ");
    scanf("%d",&q->size);
    q->a=(int *)malloc((q->size)*sizeof(int));
    q->f=q->count=0;
    q->r=-1;
}

void display(Queue *q){
    int temp=q->f;

    if(q->count==0) {
        printf("Queue Empty\n"); return;
    }
printf("The elements in the queue are: ");
    while(temp!=q->r){
        printf("%d ",q->a[temp]);
        temp=(temp+1)%(q->size);
    }
    //Printing the last element
    printf("%d\n",q->a[q->r]);

}

void enqueue(Queue* q, int k){
    if(q->count==q->size){
        if(q->f>0) {
            printf("Enqueue is not possible as queue cannot be expanded further:(\n");
            return;
        }
        printf("Queue Full. Reallocating memory...\n");
        q->a=(int *)realloc(q->a, 2* (q->size) * sizeof(int));
        q->r=(q->size)-1;
        q->size=2*(q->size);
    }
    q->r=((q->r)+1)%(q->size);
    q->a[q->r]=k;
    (q->count)++;
}

void dequeue(Queue* q){
    if(q->count==0 || q->size==0){
        printf("Queue is empty. Deletion not possible.\n");
        q->f=0; q->r=-1;
        return;
    }
    printf("Deleted element is: %d\n",q->a[q->f]);
    q->f=(q->f+1)%(q->size);
    q->count--;
}


void main(){
    Queue *q= (Queue *)malloc(sizeof(Queue));
    create(q);
    int k,ch;
    while(1){
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n---------------\n");
    printf("Enter choice: ");
    scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter the element to be enqueued\n");
            scanf("%d",&k);
            enqueue(q,k); break;

            case 2: 
            dequeue(q);
            break;

            case 3: 
            display(q);
            break;

            case 4:
            printf("Exiting..\n");
            free(q->a);
            free(q);
            exit(0);

            default:
            printf("Invalid choice!\n");
        }
    }


}