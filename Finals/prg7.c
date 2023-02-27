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

Node* deleteFront(Node* tail){   
    if(tail==NULL || size==0){
        printf("LL is empty. Deletion not possible.\n");
        return NULL;
    }
    Node* head=tail->next;
    tail->next=head->next;
    free(head);
    size--;
    if(size==0) tail=NULL;
    display(tail);
    return tail;
}

Node* deleteRear(Node* tail){   
    if(tail==NULL || size==0){
        printf("LL is empty. Deletion not possible.\n");
        return NULL;
    }
    Node* head=tail->next;
    Node* temp=head;
    while(temp->next!=tail) temp=temp->next;
    temp->next=tail->next;
    free(tail);
    size--;
    if(size==0) temp=NULL;
    display(temp);
    return temp;
}


Node* insertByPos(Node* tail, int data, int pos)
{
    Node* node= (Node *)malloc(sizeof(Node));
    node->data=data;
    node->next=node;

    if(size==0 || tail==NULL) {
        size++;
        display(node);
        return node;
    }

    Node* head=tail->next;
    if(pos<=0 || pos>(size+1)){
        printf("Invalid pos\n");
        display(tail); 
        return tail;
    }

    if(pos==1){
        node->next=tail->next;
        tail->next=node;
        size++;
        display(tail); 
        return tail;
    }
Node* temp=head;
    if(pos==size+1)
    {
        size++;
        node->next=tail->next;
        tail->next=node;
        tail=node;
        display(tail);
        return tail;
    }
    temp=head;
    int i=1;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    node->next=temp->next;
    temp->next=node;
    size++;
    display(tail);
    return tail;
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

void main()
{
    int ch,k,pos;
    Node* tail=NULL;
    Node* h2=NULL;
    while(1)
    {
        printf("0.Exit\n1.Insert By Pos\n2.Delete Front\n3.Delete Rear\n4.Search By Pos\n");
        printf("\n-----\nEnter you choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 0: 
            exit(0);

            case 1:
            printf("Enter element and position at which you want to insert\n");
            scanf("%d%d",&k, &pos);
            tail=insertByPos(tail, k, pos);
            break;

            case 2:
            tail=deleteFront(tail);
            break;

            case 3:
            tail=deleteRear(tail);
            break;

            case 4:
            printf("Enter the element to be searched\n");
            scanf("%d",&k);
            searchByKey(tail, k);
            break;

            default: printf("Invalid choice\n");
        }
    }
}