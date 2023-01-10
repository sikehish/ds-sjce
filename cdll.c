#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int data;
struct node* lptr;
struct node* rptr;
}node;

int i;

node* createLL(node*);//Working Correctly :)
node* createNode(void);//Working Correctly :)
void display(node*);//Working Correctly :)
node* insertBeg(node*);//Working Correctly :)
node* insertEnd(node*);//Working Correctly :)
node* deleteBeg(node*);//Working Correctly :)
node* deleteEnd(node*);//Working Correctly :)
node* deleteAtPosition(node*,int);//Working Correctly :)
node* insertAtPosition(node*,int);//Working Correctly :)
node* deleteByKey(node*);//Working Correctly :)
void searchByKey(node*);//Working Correctly :)
node* reverseList(node*);//Working Correctly :)
node* copyLL(node*,node*);//Working Correctly :)
node* orderedList(node* head, int data);

int main()
{
node*h = NULL; node*h2 = NULL;
int data;
h = createLL(h); display(h); int choice;
for(;;)
{

printf("\n\n1.Insert At The Beginning\n2.Insert At The End\n3.Delete At The Beginning\n4.Delete At the End\n5.Insert At Position\n6.Delete At Position\n7.Delete By Key\n8.Search By Key\n9.Reverse List\n10.Create A Copy\n11.Ordered List\n12.Exit\n\n");
printf("Enter your choice:\t"); scanf("%d",&choice);
switch(choice)
{
case 1: h = insertBeg(h); display(h); break;
case 2: h = insertEnd(h); display(h); break;
case 3: h = deleteBeg(h); display(h); break;
case 4: h = deleteEnd(h); display(h); break;
case 5: printf("\nEnter the position:\t"); scanf("%d",&choice);
if(choice<=0 || choice>h->data+1)
{printf("\nInvalid Position...\n");break;}
h = insertAtPosition(h,choice); display(h); break;
case 6: printf("\nEnter the position:\t"); scanf("%d",&choice);
if(choice<=0 || choice>h->data)
{printf("\nInvalid Position...\n");break;}
h = deleteAtPosition(h,choice); display(h); break;
case 7: h = deleteByKey(h); display(h); break;
case 8: searchByKey(h); break;
case 9: h = reverseList(h); display(h); break;
case 10: h2 = copyLL(h,h2); display(h2); break;
case 11: 
printf("Enter the data\n");
scanf("%d", &data);
    h= orderedList(h,data);
    // display(h);
    break;
case 12: exit(0);
default: printf("\nInvalid Position...\n"); break;

}
}

return 0;
}

node*createNode(void)
{
node*newnode;
newnode = (node*)malloc(sizeof(node));

printf("\nEnter the data:\t"); scanf("%d",&newnode->data);
newnode->rptr = NULL;
newnode->lptr = NULL;

return newnode;
}

node*createLL(node*h)
{
int n;
printf("\nNodes:\t"); scanf("%d",&n);
h = (node*)malloc(sizeof(node));

h->lptr = h;
h->rptr = h;
h->data = 0;

if(n == 0)
{
return h;
}

else
{
node*newnode;
for(i=0; i<n; i++)

{
printf("\nNode %d",i+1);
newnode = createNode();

newnode->rptr = h;
newnode->lptr = h->lptr;

h->lptr->rptr = newnode;
h->lptr = newnode;
h->data += 1;
}
return h;
}
}

void display(node*h)
{
printf("\nCurrent status of the linked list is...\n");
printf("Number of nodes: %d\n",h->data);
printf("\nLinked list");
if(h->data == 0)
{
printf(":\tIt is empty");
}

else
{ printf("\n");
node*temp = h->rptr;
while(temp != h)
{

printf("%d\t",temp->data);
temp = temp->rptr;
}
}
}

node*insertBeg(node*h)
{
node* newnode;
printf("\nFor the node to be inserted at the beginning...\n");
newnode = createNode();

newnode->lptr = h;
newnode->rptr = h->rptr;

h->rptr->lptr = newnode;
h->rptr = newnode;
h->data += 1;

return h;

}

node* insertEnd(node*h)
{
node*newnode;
printf("\nFor the node to be inserted at the end:\t");
newnode = createNode();

newnode->rptr = h;
newnode->lptr = h->lptr;

h->lptr->rptr = newnode;
h->lptr = newnode;
h->data += 1;

return h;

}

node* deleteBeg(node*h)
{
node*temp;
temp = h->rptr;
h->rptr = temp->rptr;
temp->rptr->lptr = h;
free(temp);
if(h->data <= 0)
h->data = 0;

else
h->data -=1;

return h;
}

node* deleteEnd(node*h)
{
if(h->data == 0)
{
return h;
}

else
{
node*temp;
temp = h->lptr;
temp->lptr->rptr = h;
h->lptr = temp->lptr;
free(temp);
if(h->data <= 0)
h->data = 0;

else
h->data -=1;

return h;
}
}

node* deleteAtPosition(node*h, int p)
{
node*temp;
temp = h->rptr;
for(i=1; i<p; i++)
{
temp = temp->rptr;
}

temp->lptr->rptr = temp->rptr;
temp->rptr->lptr = temp->lptr;

free(temp);

if(h->data <= 0)
h->data = 0;

else
h->data -=1;

return h;
}

node* insertAtPosition(node*h, int p)
{
node*temp; node*newnode;
temp = h->rptr;

for(i=1; i<p; i++)
{
temp = temp->rptr;
}

printf("\nFor the data to be inserted at position %d...\n",p);
newnode = createNode();

newnode->lptr = temp->lptr;
newnode->rptr = temp;

temp->lptr->rptr = newnode;
temp->lptr = newnode;

h->data += 1;

return h;

}

node* deleteByKey(node*h)
{
int key, flag = 1; i = 1;
printf("\nEnter the key:\t"); scanf("%d",&key);

node*temp = h->rptr;

while(temp != h)
{
if(temp->data == key)
{
printf("\nElement found at position %d\n",i);
temp->lptr->rptr = temp->rptr;
temp->rptr->lptr = temp->lptr;
free(temp);
h->data -= 1;
flag = 0;
break;
}

else
{
temp = temp->rptr;
i++;
}
}

if(flag == 1)
{

printf("\nELement absent\n");
}

return h;
}

void searchByKey(node*h)
{
int key, flag = 1; i = 1;
printf("\nEnter the key:\t"); scanf("%d",&key);

node*temp = h->rptr;

while(temp != h)
{
if(temp->data == key)
{
printf("\nElement found at position %d\n",i);
flag = 0;
break;
}

else
{
temp = temp->rptr;
i++;
}
}

if(flag == 1)
{

printf("\nELement absent\n");
}

}

node* reverseList(node*h)
{
node*left = h->lptr;
node*right = h->rptr;
int temp;

if(h->data<=1) return h;

while(right!=left->rptr)
{
temp = right->data;
right->data = left->data;
left->data = temp;

left = left->lptr;
right = right->rptr;
}

return h;
}

node* copyLL(node*h,node*h2)
{
h2 = (node*)malloc(sizeof(node));
h2->lptr = h2;
h2->rptr = h2;
h2->data = 0;

node*temp = h; node*current = h2;

do{
temp = temp->rptr;
current->rptr = (node*)malloc(sizeof(node));
current->rptr->lptr = current;
current = current->rptr;
current->rptr = h2;
h2->lptr = current;
current->data = temp->data;
}while(temp->rptr != h);

h2->data = h->data;

return h2;
}

node* orderedList(node* head, int data)
{
     node* newnode= malloc(sizeof(node));
    newnode->data=data;
    if(head==NULL) {
        newnode->rptr=newnode;
        newnode->lptr=newnode;
        head=newnode;
        return head;
    }
   

    printf("Before insertion: \n");
    display(head);
    head->data++;

        node * temp=head->rptr;
        node* temp2=NULL;
    while(temp!=head)
    {
        temp2=temp->rptr;
        while(temp2!=head)
        {
            if(temp2->data<temp->data){
                int t=temp2->data;
                temp2->data=temp->data;
                temp->data=t;
            }
            temp2=temp2->rptr;
        }
        temp=temp->rptr;
    }

    temp2=head->rptr;
    while(temp2!=head)
    {
        if(data<=temp2->data)
        {
            newnode->rptr=temp2;
            newnode->lptr=temp2->lptr;
            temp2->lptr->rptr=newnode;
            temp2->lptr=newnode;
            break;
        }
        temp2=temp2->rptr;
    }

    if(temp2==head){
        newnode->rptr=head;
        newnode->lptr=head->lptr;
        head->lptr->rptr=newnode;
        head->lptr=newnode;
    }

    printf("\nAfter insertion: \n");
    display(head);
    return head;
    
}