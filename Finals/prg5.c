#include<stdio.h>
#include<stdlib.h>

int size=0;

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void display(Node* tail)
{
    if(size==0){
        printf("Linked List empty\n");
        return;
    }
    Node* temp=tail->next;
    
    do{
        printf("%d ", temp->data);
        temp=temp->next;
    }while(temp!=tail->next);
    printf("\n");

}

Node* insertFront(Node* tail, int data){
    Node* newnode=(Node *)malloc(sizeof(Node));
    newnode->data=data;
    if(tail==NULL){
        newnode->next=newnode;
        size++;
        return newnode;
    }
    newnode->next=tail->next;
    tail->next=newnode;
    size++;
    display(tail);
    return tail;
}

Node* insertRear(Node* tail, int data){
    Node* newnode=(Node *)malloc(sizeof(Node));
    newnode->data=data;
    if(tail==NULL){
        newnode->next=newnode;
        size++;
        return newnode;
    }
    newnode->next=tail->next;
    tail->next=newnode;
    tail=newnode;
    size++;
    display(tail);
    return tail;
}

Node* deleteByKey(Node* tail, int data){

    if(tail==NULL) {
        printf("LL empty\n"); return NULL;
    }

    Node* temp=tail->next;
    int pos=0,f=0;
    do{
        pos++;
        if(temp->data==data) {
            f=1; break;
        }
        temp=temp->next;
    }while(temp!=tail->next);

    if(!f) {
        printf("Key %d not found\n",data);
        return tail;
    }

    Node* head=tail->next;
     temp=head;
    if(pos==size){
        while(temp->next!=tail) temp=temp->next;
        temp->next=tail->next;
        printf("Element %d found at tail\n", tail->data); 
        free(tail);
        size--;
        if(size==0) temp=NULL; 
        display(temp);
        return temp;
    }
    if(pos==1){
        head=temp->next;
        tail->next=head;
        free(temp);
        size--;
        display(tail);
        return tail;
    }
   temp=head;
    Node*prev=tail;
    int i=1;
    while(i<pos-1){
        i++;
        temp=temp->next;
    }
    Node* temp2=temp->next;
    temp->next=temp2->next;
    printf("Element %d found at pos %d \n",temp2->data, pos);
    free(temp2);
    size--;
    display(tail);
    return tail;
}

void searchByPos(Node* tail, int pos)
{
     if(tail==NULL) {
        printf("LL empty\n"); return;
    }
    Node* head=tail->next;
    Node* temp=head;
    if(pos<1 || pos>size) {
        printf("%d is invalid!\n", pos); return;
    }
    int i=1;
    for(int i=1; i<pos; i++) temp=temp->next;
    printf("%d found at %d pos\n",temp->data, pos);
    
}

void main()
{
    int ch,k,pos;
    Node* tail=NULL;
    Node* h2=NULL;
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
            tail=insertFront(tail, k);
            break;

            case 2:
            printf("Enter element to insert at the end: ");
            scanf("%d",&k);
            tail=insertRear(tail, k);
            break;

            case 3:
            printf("Enter position to search for element\n");
            scanf("%d",&pos);
            searchByPos(tail, pos);
            break;

            case 4:
            printf("Enter element to delete\n");
            scanf("%d",&k);
            tail=deleteByKey(tail, k);
            break;

            default: printf("Invalid choice\n");
        }
    }
}