#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* next;
    struct Node* prev;
    int data;
}Node;

void display(Node* head)
{
    if(head->data==0) {
        printf("Empty DLL\n"); return;
    }
    Node* temp=head->next;
    while(temp!=head){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}


void insertFront(Node* head, int data)
{
    Node* newnode= (Node *)malloc(sizeof(Node));
    newnode->data=data;
    newnode->prev=head;
    newnode->next=head->next;
    head->next->prev=newnode;
    head->next=newnode;
    (head->data)++;
    display(head);
}

void deleteFront(Node* head)
{
    if(head->data==0) {
        printf("Empty DLL\n"); return;
    }
    Node* temp=head->next;
    head->next=head->next->next;
    temp->next->prev=head;
    free(temp);
    head->data--;
    display(head);
}

void insertRear(Node* head, int data)
{
    // printf("YOOOOO\n");
    Node* newnode= (Node *)malloc(sizeof(Node));
    newnode->data=data;
    newnode->prev=head->prev;
    newnode->next=head;
    head->prev->next=newnode;
    head->prev=newnode;
    (head->data)++;
     display(head);
}

void deleteRear(Node* head)
{
    if(head->data==0) {
        printf("Empty DLL\n"); return;
    }
    Node* temp=head->prev;
    head->prev=temp->prev;
    temp->prev->next=head;
    free(temp);
    head->data--;
    display(head);
}

void insertAtPos(Node* head, int data, int pos)
{
    if(pos<=0 ){
        printf("Invalid pos\n"); return;
    }
    int i=1;
    Node* temp=head->next;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    // if(temp==head) temp=head->next;
    Node* newnode= (Node *)malloc(sizeof(Node));
    newnode->data=data;
    newnode->prev=temp->prev;
    newnode->next=temp;
    temp->prev=newnode;
    newnode->prev->next=newnode;
    head->data++;
     display(head);
}

void deleteAtPos(Node* head, int pos)
{
     if(head->data==0) {
        printf("Empty DLL\n"); return;
    }
    int i=1;
    Node* temp=head->next;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    if(temp==head) temp=head->next;
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    head->data--;
    display(head);
}


void main()
{
    int ch,k,pos;
    Node* head= (Node *)malloc(sizeof(Node));
    head->data=0;
    head->prev=head->next=head;
    while(1)
    {
        printf("Enter the choice:\n1Insert Front\n2.Insert Rear\n3.Insert Pos\n4.Delete Front\n5.Delete Rear\n6.Delete Pos\n7.Display\n8.Exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted\n");
            scanf("%d",&k);
            insertFront(head,k);
            break;
        case 2:
            printf("Enter the element to be inserted\n");
            scanf("%d",&k);
            insertRear(head,k);
            break;
        case 3:
            printf("Enter the  pos and element to be inserted\n");
            scanf("%d",&pos);
            scanf("%d",&k);
            insertAtPos(head,k, pos);
            break;
        case 4:
            deleteFront(head);
            break;
        case 5:
            deleteRear(head);
            break;
        case 6:
            printf("Enter the pos to be deleted\n");
            scanf("%d",&k);
            deleteAtPos(head, k);
            break;
        case 7:
        display(head); break;
        case 8: exit(0);
        default:
            printf("Invalid character\n");
        }
    }
}