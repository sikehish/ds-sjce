#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;


typedef struct Queue{
    Node* f;
    Node* r;
    int count;
}Queue;

void display(Queue* s)
{
if(s->f==NULL || s->r==NULL) {
        printf("Queue empty\n");
        return;
    }
Node * temp=s->f;
printf("Number of elements in Queue: %d\n Queue is: ", s->count);
while(temp!=NULL)
{
    printf("%d ",temp->data);
    temp=temp->next;
}
printf("\n");
}

void enqueue(Queue* s, int data)
{
    Node* newnode= (Node *)malloc(sizeof(Node));
    newnode->data=data;
    if(s->r==NULL) {
        s->f=s->r=newnode;
    newnode->next=NULL;
    }else{
        s->r->next=newnode;
    newnode->next=NULL;
    s->r=newnode;
    }
    s->count++;
    display(s);
}

void dequeue(Queue* s)
{
    if(s->f==NULL || s->r==NULL) {
        printf("Queue empty\n");
        return;
    }
    Node* temp=s->f;
    s->f=s->f->next;
    free(temp);
    s->count--;
    display(s);
}


void main()
{
    Queue* st= (Queue *)malloc(sizeof(Queue));
    st->f=NULL;
    st->r=NULL;
    st->count=0;
    int ch,K;
    while(1)
    {
        printf("Enter the choice\n1.enqueue\n2.dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
            printf("Enter the data you want to enqueue\n");
            scanf("%d",&K);
            enqueue(st, K);
            break;

            case 2:
            dequeue(st);
            break;

            case 3:
            display(st);
            break;

            case 4: exit(0);
        }
    }
}