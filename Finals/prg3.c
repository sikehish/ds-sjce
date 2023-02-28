#include<stdio.h>
#include<stdlib.h>

int size=0;

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void display(Node* tail)
{
    if(size==0 || tail==NULL){
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


void searchByKey(Node* tail, int k)
{

    if(tail==NULL) {
        printf("LL empty\n"); return;
    }
    Node* head=tail->next;
    Node* temp=head;
   do{
        if(temp->data==k) {
            printf("Element %d found!\n", temp->data); return;
        }
        temp=temp->next;
    } while(temp!=head);
    printf("Element %d not found\n", k);
}

Node* deleteByPos(Node* tail, int pos)
{
     if(tail==NULL) {
        printf("LL empty\n"); return NULL;
    }
     if(pos<1 || pos>size) {
        printf("Invalid position\n"); return tail;
    }
    Node* head=tail->next;
    Node* temp=head;
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

Node* insertByOrder(Node* tail, int data){
       Node* node=(Node *)malloc(sizeof(Node));
       node->data=data;
       node->next=NULL;
    if(tail==NULL) {
        tail=node;
       node->next=tail;
       size++;
       display(tail);
         return tail;
    }
     printf("Before Insertion: \n");
    display(tail);
    Node* head=tail->next;
    //Insertion
    tail->next=node;
    node->next=head;
    tail=node;
    size++;

    
    //Ordering
    Node* temp=head;
    Node* temp2=NULL;
    do
    {
        temp2= temp->next;
        
        do{
            if(temp2->data<temp->data){
                int tempor= temp2->data;
                temp2->data=temp->data;
                temp->data=tempor;
            }
            temp2=temp2->next;
        }while(temp2!=head);
        temp=temp->next;
    }while(temp->next!=head);
    printf("After insertion: \n");
    display(tail);
       return tail;
}

void main()
{
    int ch,k,pos;
    Node* tail=NULL;
    Node* h2=NULL;
    while(1)
    {
        printf("0.Exit\n1.Insert By Order\n2.Delete By Position\n3.Search By Key\n");
        printf("\n-----\nEnter you choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 0: 
            exit(0);

            case 1:
            printf("Enter element to be inserted by order ");
            scanf("%d",&k);
            tail=insertByOrder(tail, k);
            break;

            case 2:
            printf("Enter pos to delete\n");
            scanf("%d",&pos);
            tail=deleteByPos(tail, pos);
            break;

            case 3:
            printf("Enter element to search\n");
            scanf("%d",&k);
            searchByKey(tail, k);
            break;

            default: printf("Invalid choice\n");
        }
    }
}