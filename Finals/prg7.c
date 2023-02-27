#include<stdio.h>
#include<stdlib.h>

int size=0;

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void display(Node* tail)
{
    Node* temp=tail->next;
    if(size==0){
        printf("Linked List empty\n");
        return;
    }
    
    do{
        printf("%d ", temp->data);
        temp=temp->next;
    }while(temp!=tail->next);
    printf("\n");

}

Node* insert(Node* tail, int data, int pos)
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

Node* delete(Node* tail, int pos)
{

    if(size==0 || tail==NULL) {
        printf("LL empty!\n"); 
        return NULL;
    }

    if(pos<=0 || pos>(size)){
        printf("Invalid pos\n");
        return tail;
    }
    Node* head=tail->next;

    if(pos==1){
        Node* temp=head;
        head=head->next;
        free(temp);
        tail->next=head;
        size--;
        display(tail); 
        return tail;
    }

     Node* temp=head;
    Node* prev=NULL;
     if(pos==size+1)
    {
        while(temp->next!=tail) {
            temp=temp->next;
        }
        temp->next=tail->next;
        free(tail);
        size--;
        display(tail);
        return tail;
    }
    temp=head;
    int i=1;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    Node* temp2= temp->next;
   temp->next=temp2->next;
    free(temp2);
    size--;
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

Node* deleteByKey(Node* tail, int k)
{
     if(tail==NULL) {
        printf("LL empty\n"); return NULL;
    }
    Node* head=tail->next;
    Node* temp=head;
    int i=0;
    do{
        i++;
        if(temp->data==k) {
            printf("Element %d found!\n", temp->data); 
            return delete(tail, i);
        }
        temp=temp->next;
    }while(temp!=head);
    printf("Element %d not found\n", k);
    return tail;
}

Node* orderedList(Node* tail, int data){
    if(tail==NULL) {
        printf("LL empty\n"); return NULL;
    }
    tail= insert(tail,data, 1);
    Node* head=tail->next;
    printf("Before Insertion: \n");
    display(tail);
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

Node* reverse(Node* tail)
{
    if(tail==NULL){
        printf("LL empty\n"); return NULL;
    }
    Node* prev=tail;
    Node* curr=tail->next;
    Node* head= tail->next;
    Node* temp=NULL;

    printf("Before reversal:\n");
    display(tail);

    do
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }while(curr!=head);
    
    printf("After reversal:\n");
    display(head);
    return head;
}

Node* copyLL(Node* head)
{
    //head here is basically tail ->naming mistake

    if(head==NULL || size==0){
        printf("LL empty\n"); return NULL;
    }
    Node* temp=head;
    Node* head2= (Node *)malloc(sizeof(Node));
    head2->next=NULL;
    head2->data=head->data;
    temp=temp->next; Node* prev=head2;
    do{
        Node* node=(Node *)malloc(sizeof(Node));
        node->data=temp->data;
        prev->next=node;
        node->next=NULL;
        prev=node;
        temp=temp->next;
    }while(temp!=head);
    prev->next=head2;
    return prev;
}

void main()
{
    int ch,k,pos;
    Node* head=NULL;
    Node* h2=NULL;
    while(1)
    {
        printf("0.Exit\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Insert At Pos\n7.Delete At Pos\n8.Search By Key\n9.Delete By Key\n10.Ordered List\n 11.Reverse A List\n");
        printf("12.Copy a list\n");
        printf("\n-----\nEnter you choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 0: 
            while(head!=NULL)
            {
                h2=head->next;
                free(head);
                head=h2;
            }
            exit(0);

            case 1:
            printf("Enter element to insert at the beginning: ");
            scanf("%d",&k);
            head=insert(head, k, 1);
            break;

            case 2:
            printf("Enter element to insert at the end: ");
            scanf("%d",&k);
            head=insert(head, k, size+1);
            break;

            case 3:
            head=delete(head, 1);
            break;

            case 4:
            head=delete(head, size);
            break;

            case 5:
            display(head);
            break;

            case 6:
            printf("Enter element to insert and pos\n");
            scanf("%d%d",&k,&pos);
            head=insert(head, k, pos);
            break;

            case 7:
            printf("Enter pos to delete\n");
            scanf("%d",&pos);
            head=delete(head, pos);
            break;

            case 8:
            printf("Enter element to search\n");
            scanf("%d",&k);
            searchByKey(head, k);
            break;

            case 9:
            printf("Enter element to delete\n");
            scanf("%d",&k);
            head=deleteByKey(head, k);
            break;

            case 10:
            printf("Enter the element to be inserted in ordered list\n");
            scanf("%d",&k);
            head=orderedList(head,k);
            break;

            case 11:
            head=reverse(head);
            break;

            case 12:
            h2=copyLL(head);
            display(head);
            break;

            default: printf("Invalid choice\n");
        }
    }
}