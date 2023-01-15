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
if(s->f==NULL || s->r==NULL || s->count==0) {
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

void enqueueF(Queue* s, int data)
{
    Node* newnode= (Node *)malloc(sizeof(Node));
    newnode->data=data;
    if(s->r==NULL || s->f==NULL || s->count==0) {
        s->f=s->r=newnode;
    newnode->next=NULL;
    }else{
    newnode->next=s->f;
        s->f=newnode;
    }
    s->count++;
    display(s);
}


void enqueueR(Queue* s, int data)
{
    Node* newnode= (Node *)malloc(sizeof(Node));
    newnode->data=data;
    if(s->r==NULL || s->f==NULL || s->count==0) {
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

void dequeueF(Queue* s)
{
    if(s->f==NULL || s->r==NULL || s->count==0) {
        printf("Queue empty\n");
        return;
    }
    Node* temp=s->f;
    s->f=s->f->next;
    free(temp);
    s->count--;
    display(s);
}

void dequeueR(Queue* s)
{
    if(s->f==NULL || s->r==NULL || s->count==0) {
        printf("Queue empty\n");
        return;
    }
    if(s->f==s->r) {
        free(s->f); 
        s->f=s->r=NULL;
        display(s);
        return;
    }
    Node* temp=s->f;
    while(temp->next!=s->r) temp=temp->next;
    free(s->r);
    temp->next=NULL;
    s->r=temp;
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
        printf("Enter the choice\n1.enqueue at front\n2.enqueue at rear\n3.dequeue at front\n4.dequeue at rear\n5.Display\n6.Exit\n");
        scanf("%d", &ch);
        switch(ch){

            case 1:
            printf("Enter the data you want to enqueue at front\n");
            scanf("%d",&K);
            enqueueF(st, K);
            break;

            case 2:
            printf("Enter the data you want to enqueue at rear\n");
            scanf("%d",&K);
            enqueueR(st, K);
            break;

            case 3:
            dequeueF(st);
            break;

            case 4:
            dequeueR(st);
            break;

            case 5:
            display(st);
            break;

            case 6: exit(0);
        }
    }
}