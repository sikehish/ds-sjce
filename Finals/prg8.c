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
    if(size==0 || head==NULL) {
        printf("Empty DLL\n"); return;
    }
    Node* temp=head;
    do{
        printf("%d ", temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}

Node* deleteFront(Node* head)
{
    if(size==0 || head==NULL) {
        printf("Empty DLL\n"); return NULL;
    }
    Node* temp=head->next;
    head->prev->next=head->next;
    head->next->prev=head->prev;
    free(head);
    size--;
    if(size==0) temp=NULL;
    display(temp);
    return temp;
}

Node* deleteRear(Node* head)
{
    if(size==0 || head==NULL) {
        printf("Empty DLL\n"); return NULL;
    }
    Node* tail=head->prev;
    tail->prev->next=head;
    head->prev=tail->prev;
    free(tail);
    size--;
    if(size==0) head=NULL;
    display(head);
    return head;
}

// void insertAtPos(Node* head, int data, int pos)
// {
//     if(pos<=0 || pos>size){
//         printf("Invalid pos\n"); return;
//     }
//     int i=1;
//     Node* temp=head;
//     while(i<pos){
//         temp=temp->next;
//         i++;
//     }
//     Node* newnode= (Node *)malloc(sizeof(Node));
//     newnode->data=data;
//     newnode->prev=temp->prev;
//     newnode->next=temp;
//     temp->prev=newnode;
//     newnode->prev->next=newnode;
//     size++;
//     if(i==1) head=newnode;
//      display(head);
//      return head;
// }

void searchByPos(Node* head, int pos){
    Node* temp=head;
    if(pos<=0 || pos>size){
        printf("Invalid pos\n"); return;
    }
    if(temp==NULL) {
        printf("LL Empty\n");
        return;
    }
    int i=1;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    printf("Element %d found at pos %d\n",temp->data,i);
}

Node* insertByOrder(Node* head, int data){
       Node* node=(Node *)malloc(sizeof(Node));
       node->data=data;

       printf("Before Insertion: \n");
    display(head);

       if(head==NULL){
        node->next=node;
        node->prev=node;
        head=node;
       }

    if(head!=NULL)
    {
        Node* tail= head->prev;
       node->next=tail->next;
       node->prev=tail;
       tail->next=node;
       head->prev=node;
    }
       
       size++;

    Node* temp=head;
    Node* temp2=NULL;
    
    do{
        temp2= temp->next;
        
       do{
            if(temp2->data<temp->data){
                int tempor= temp2->data;
                temp2->data=temp->data;
                temp->data=tempor;
            }
            temp2=temp2->next;
        } while(temp2!=head);
        temp=temp->next;
    }while(temp->next!=head);
    printf("After insertion: \n");
    display(head);
       return head;
}

void main()
{
   int ch,k,pos;
    Node* head=NULL;
    while(1)
    {
        printf("0.Exit\n1.Insert By Order\n2.Delete Rear\n3.Delete Front\n4.Search By Pos\n");
        printf("\n-----\nEnter you choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 0: 
            exit(0);

            case 1:
            printf("Enter element to insert at the beginning: ");
            scanf("%d",&k);
            head=insertByOrder(head, k);
            break;

            case 2:
            head=deleteRear(head);
            break;

            case 3:
            head=deleteFront(head);
            break;

            case 4:
            printf("Enter the position at which youre searching for an element:\n");
            scanf("%d",&pos);
            searchByPos(head, pos);
            break;

            default: printf("Invalid choice\n");
        }
    } 
}