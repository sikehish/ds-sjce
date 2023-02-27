#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* next;
    struct Node* prev;
    int data;
}Node;

int size=0;

void display(Node* head)
{
    if(size==0) {
        printf("Empty DLL\n"); return;
    }
    Node* temp=head;
    do{
        printf("%d ", temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}

Node* insertFront(Node* head, int data)
{
    Node* newnode= (Node *)malloc(sizeof(Node));
    if(newnode==NULL) {
        printf("HEAAAAD\n");
        printf("%d\n", newnode->data);
    }
    newnode->data=data;
    if(size==0 || head==NULL) head=newnode;
    newnode->next=head;
    newnode->prev=head->prev;
    head->prev->next=newnode;
    head->prev=newnode;
    head=newnode;
    size++;
    display(head);
    return head;
}

Node* insertRear(Node* head, int data)
{
   Node* newnode= (Node *)malloc(sizeof(Node));
   if(size==0 || head==NULL) head=newnode;
    newnode->data=data;
    newnode->next=head;
    newnode->prev=head->prev;
    head->prev->next=newnode;
    head->prev=newnode;
    size++;
    display(head);
    return head;
}

Node* deleteByPos(Node* head, int pos)
{
     if(size==0 || head==NULL) {
        printf("Empty DLL\n"); return NULL;
    }
    if(pos<1 || pos>size) {
        printf("Invalid position\n"); return NULL;
    }
    if(pos==1){
        head->prev->next=head->next;
        free(head);
        size--;
        head=NULL;
        display(head);
    }
    Node* temp=head;
    int i=0;
    do{
        i++;
        if(i==pos){
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
            temp=NULL;
            size--;
            display(head);
            return head;
        }
        temp=temp->next;
    }while(temp!=head);
}

void searchByKey(Node* head, int k)
{
    if(head==NULL) {
        printf("LL empty\n"); return;
    }
    Node* temp=head;
   do{
        if(temp->data==k) {
            printf("Element %d found!\n", temp->data); return;
        }
        temp=temp->next;
    } while(temp!=head);
    printf("Element %d not found\n", k);
}


void main()
{
   int ch,k,pos;
    Node* head=NULL;
    while(1)
    {
        printf("0.Exit\n1.Insert Front\n2.Insert Rear\n3.Search By Pos\n4.Delete By Key\n");
        printf("\n-----\nEnter you choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 0: 
            exit(0);

            case 1:
            printf("Enter element to insert at the beginning: ");
            scanf("%d",&k);
            head=insertFront(head, k);
            break;

            case 2:
            printf("Enter element to insert at the end: ");
            scanf("%d",&k);
            head=insertRear(head, k);
            break;

            case 3:
            printf("Enter the element to be searched\n");
            scanf("%d",&k);
            searchByKey(head, k);
            break;

            case 4:
            printf("Enter the position at which deletion should occur:\n");
            scanf("%d",&pos);
            head=deleteByPos(head, pos);
            break;

            default: printf("Invalid choice\n");
        }
    } 
}