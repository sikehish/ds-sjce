#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node name;
void print(name *tail)
{
    name *temp;
    temp=tail->next;
    printf("Linked list is\t");
    do
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }while(temp!=tail->next);
    printf("\n");
}
name*addtoempty(int data)
{
    name *tail=malloc(sizeof(name));
    tail->data=data;
    tail->next=tail;
    print(tail);
    return tail;
}
name *addtobeg(name *tail,int data)
{
    name *newnode=malloc(sizeof(name));
    if(tail==NULL){
    // printf("CCCCCCCC\n");
        return addtoempty(data);
    }
    newnode->data=data;
    newnode->next=tail->next;
    tail->next=newnode;
     print(tail);
    return(tail);
}
name* addtorear(name *tail,int data)
{
    name *lastnode;
    lastnode=(name*)malloc(sizeof(name));
    lastnode->data=data;
    lastnode->next=tail->next;
    tail->next=lastnode;
    tail=lastnode;
     print(tail);
    return tail;
}
name *addbetween(name*tail,int data)
{
    name *newnode,*temp;
    int pos;
    newnode=(name*)malloc(sizeof(name));
    printf("Enter the position at which element is to be inserted\n");
    scanf("%d",&pos);
    if(pos<=0){
        printf("Invalid position\n"); return tail;
    }
    int position=pos;
    temp=tail;
    while(pos>1)
    {
        temp=temp->next;
        pos--;
    }
    newnode->data=data;
    newnode->next=temp->next;
    temp->next=newnode;
    if(temp==tail && position!=1) tail=newnode;
    printf("TEMP %d TAIL %d\n", temp->data, tail->data);
     print(tail);
    return tail;
}
name* deletebeginning(name *tail)
{
    name *temp;
    temp=tail->next;
    tail->next=temp->next;
    free(temp);
    temp->next=NULL;
     print(tail);
    return tail;
}
name *deleteatend(name *tail)
{
    name *temp,*temp2;
    temp2=tail;
    temp=tail;
    while(temp2->next!=tail)
    {
        temp2=temp2->next;
    }
    temp=temp2->next;
    temp2->next=temp->next;
    free(temp);
    temp=NULL;
    tail=temp2;
     print(tail);
    return tail;
}
name *deleteatpos(name *tail,int pos)
{
    name *temp,*temp2;
    temp=tail;
    while(pos>1)
    {
        temp=temp->next;
        pos--;
    }
    temp2=temp->next;
    temp->next=temp2->next;
    free(temp2);
    temp2=NULL;
     print(tail);
    return tail;
}
name *deletekey(name *tail,int data)
{
    name *temp;
    temp=tail;
    int f=0,pos=0;
    do
    {
        if(temp->data==data)
        {
            f=1;
            break;
        }
        temp=temp->next;
        pos++;
    }   while(temp->next!=tail);
    if(f==0)
    {
        printf("Not found\n");
    }
    else{
            deleteatpos(tail,pos);
    }
    return tail;
}
name *searchkey(name *tail,int ele)
{
    name *temp;
    temp=tail;
    int f=0;
    do
    {
        if(temp->data==ele)
        {
            f=1;
            break;
        }
        temp=temp->next;
    }while(temp->next!=tail);
    if (f==0)
    {
        printf("Not found\n");
    }
    else{
        printf("Element found\n");
    }
    return tail;
}
name *reverse(name* tail)
{
    name *temp,*temp2,*temp3;
    temp=tail->next;
    temp2=tail->next->next;
    temp3=tail->next->next->next;
    temp->next=NULL;
    temp->next=tail;
    do{
        temp2->next=temp;
        temp=temp2;
        temp2=temp3;
        temp3=temp3->next;
    }while(temp!=tail);
    temp2->next=temp;
    tail=temp2;
     print(tail);
    return tail;
}
name* orderedList(name *tail,int n)
{
    int i,j;
    name *node1,*node2,*temp2;
    temp2=(name*)malloc(sizeof(name));
    temp2->next=NULL;
    for(i=0;i<n;i++)
    {        node1=tail->next;
        node2=tail->next->next;
        for(j=0;j<n-i;j++)
        {

            if(node1->data>node2->data)
            {
                temp2->data=node1->data;
                node1->data=node2->data;
                node2->data=temp2->data;
            }
            node1=node2;
            node2=node2->next;
        }
    }

    int data;
    printf("Enter the number you want to insert:\n");
    scanf("%d",&data);

    name* newnode=malloc(sizeof(name));
    newnode->data=data;

printf("Ordered List before insertion: \n");
    print(tail);


    temp2=tail->next;
    if(data<=temp2->data){
        newnode->next=temp2;
        tail->next=newnode;
    }
    else{
        while(temp2!=tail){
        if(data<=temp2->next->data){
            newnode->next=temp2->next;
            temp2->next=newnode;
            break;
        }
        temp2=temp2->next;
    }
    }

if(temp2==tail){
    newnode->next=tail->next;
    tail->next=newnode;
    tail=newnode;
}
    

    printf("Ordered List after insertion: \n");
    print(tail);
    return tail;
}
void copy(name *tail)
{
    name *node1,*node2,*temp,*newhead;
    node2=tail;
    temp=tail;
    node1=(name*)malloc(sizeof(name));
    node1->next=NULL;
    node1->data=temp->data;
    node1->next=temp->next;
    newhead=node1;
    while(temp->next!=tail)
    {
        node1=(name*)malloc(sizeof(name));
        node1->data=temp->data;
        node1->next=temp->next;
        temp=temp->next;
    }
    temp->next=newhead;
    print(newhead);
}
int main()
{
    name node1;
    int data,choice;
    int pos;
    name *tail=NULL;
    while(1)
    {
        printf("Enter your choice 1. add empty 2 .add beg 3. add at end 4.......\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                 printf("Enter the data\n");
                 scanf("%d",&data);
                 tail=addtoempty(data);
                 break;
             case 2:
                 printf("Enter the data\n");
                 scanf("%d",&data);
                 tail=addtobeg(tail,data);
                 break;
            case 3:
                 printf("Enter the data\n");
                 scanf("%d",&data);
                 tail=addtorear(tail,data);
                 break;
            case 4:
                 printf("Enter the data\n");
                 scanf("%d",&data);
                 tail=addbetween(tail,data);
                 break;
            case 5:
                 tail=deletebeginning(tail);
                 break;
            case 6:
                 tail=deleteatend(tail);
                 break;
            case 7:
                printf("Enter the position at which node must be deleted\n");
                scanf("%d",&pos);
                 tail=deleteatpos(tail,pos);
                 break;
            case 8:
                 printf("Enter the data\n");
                 scanf("%d",&data);
                 tail=deletekey(tail,data);
                 break;
            case 9:
                 printf("Enter the data\n");
                 scanf("%d",&data);
                 tail=searchkey(tail,data);
                 break;
            case 10:
                 tail=reverse(tail);
                 break;
             case 11:
                 printf("Enter the no of nodes\n");
                 scanf("%d",&data);
                 tail=sort(tail,data);
                 break;
            case 12:
                 copy(tail);
                 break;
            default : printf("Invalid choice\n");
        }
    }
}
