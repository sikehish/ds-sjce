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

Node* deleteByKey(Node* head, int k){
    Node* temp= head->next;

    while(temp!=head)
    {
        if(temp->data==k){
            temp->prev->next=temp->next;
            temp->next=temp->prev;
            printf("Element %d deleted\n", temp->data);
            free(temp);
            display(head);
            return head;
        }
        temp=temp->next;
    }
    printf("Element %d not found", k);
    return head;
    
}


void searchByPos(Node* head, int pos){

    Node* temp= head->next;
    int i=0;
    while(temp!=head)
    {
        i++;
        if(head->data==i){
            printf("Element %d found at position %d\n", temp->data, head->data);
            display(head);
            return;
        }
        temp=temp->next;
    }
    printf("Invalid position. Size is %d and position is %d\n",head->data,pos);
}

Node* insertByOrder(Node* head, int data){
       Node* node=(Node *)malloc(sizeof(Node));
       node->data=data;
       node->next=head;
       node->prev=head;

       Node* temp=head->next;
       while(temp->next!=head) temp=temp->next;
       temp->next=node;
       node->prev=temp;
       head->data++;

    printf("Before Insertion: \n");
    display(head);
    
    //Ordering
    Node* temp=head->next;
    Node* temp2=NULL;
    while(temp->next!=head)
    {
        temp2= temp->next;
        
        while(temp2!=head){
            if(temp2->data<temp->data){
                int tempor= temp2->data;
                temp2->data=temp->data;
                temp->data=tempor;
            }
            temp2=temp2->next;
        }
        temp=temp->next;
    }
    printf("After insertion: \n");
    display(head);
       return head;
}


void main()
{
    int ch,k,pos;
    Node* head= (Node *)malloc(sizeof(Node));
    head->data=0;
    head->prev=head->next=head;
    while(1)
    {

printf("0.Exit\n1.Insert By Order\n2.Delete By Key\n3.Search By Position\n");
        printf("\n-----\nEnter you choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 0: exit(0);

            case 1:
            printf("Enter element to be inserted by order \n");
            scanf("%d",&k);
            head=insertByOrder(head, k);
            break;

            case 2:
            printf("Enter pos to delete\n");
            scanf("%d",&pos);
            head=deleteByKey(head, pos);
            break;

            case 3:
            printf("Enter element to search\n");
            scanf("%d",&k);
            searchByPos(head, k);
            break;

            default:
            printf("Invalid character\n");
        }
    }
}