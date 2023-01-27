#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;


typedef struct Stack{
    Node* top;
    int count;
}Stack;

void display(Stack* s)
{
if(s->top==NULL) {
        printf("Stack empty\n");
        return;
    }
Node * temp=s->top;
printf("Number of elements in stack: %d\n Stack is: ", s->count);
while(temp!=NULL)
{
    printf("%d ",temp->data);
    temp=temp->next;
}
printf("\n");
}

void push(Stack* s, int data)
{
    Node* newnode= (Node *)malloc(sizeof(Node));
    newnode->data=data;
    if(s->top==NULL) newnode->next=NULL;
    else newnode->next=s->top;
        s->top=newnode;
    s->count++;
    display(s);
}

void pop(Stack* s)
{
    if(s->top==NULL) {
        printf("Stack empty\n");
        return;
    }
    Node* temp=s->top;
    s->top=s->top->next;
    free(temp);
    s->count--;
    display(s);
}


void main()
{
    Stack* st= (Stack *)malloc(sizeof(Stack));
    st->top=NULL;
    st->count=0;
    int ch,K;
    while(1)
    {
        printf("Enter the choice\n1.Push\n2.Pop\n3.Display(From top)\n4.Exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
            printf("Enter the data you want to push\n");
            scanf("%d",&K);
            push(st, K);
            break;

            case 2:
            pop(st);
            break;

            case 3:
            display(st);
            break;

            case 4: exit(0);
        }
    }
}