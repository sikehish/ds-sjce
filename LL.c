#include <stdio.h>
#include <stdlib.h>
int size = 0;

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;

node *display(node *head)
{
    node *temp = head;

    if (size == 0)
    {
        printf("Linked list empty\n");
        return head;
    }

    printf("Linked list is\n");
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    return head;
}

node *insertAtPos(node *head, int data, int pos)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->data = data;

    if (pos <= 0 || pos > size + 1)
    {
        printf("Invalid Position\n");
        display(head);
        return head;
    }

    if (size == 0)
    {
        head = newnode;
        size++;
        display(head);
        return head;
    }

    if (pos == 1)
    {
        node *temp = head;
        newnode->next = temp;
        temp->prev = newnode;
        head = newnode;
        size++;
        display(head);
        return head;
    }

    if (pos == size + 1)
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newnode->prev = temp;
        temp->next = newnode;
        size++;
        display(head);
        return head;
    }

    // else
    // {
    //     int i = 1;
    //     node *temp = head;
    //     while (i < pos - 1)
    //     {
    //         temp = temp->next;
    //     }
    //     newnode->next = temp->next;
    //     temp->next = newnode;
    //     newnode->prev = temp;
    //     size++;
    //     display(head);
    //     return head;
    // }
}

node *deleteAtPos(node *head, int pos)
{

    if (size == 0)
    {
        printf("Linked list is empty\n");
        return head;
    }

    if (pos <= 0 || pos > size)
    {
        printf("Invalid position");
        display(head);
        return head;
    }

    if (pos == 1)
    {
        node *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        size--;
        display(head);
        return head;
    }

    if (pos == size)
    {
        node *temp = head;
        node *p;
        while (temp->next != NULL)
        {
            p = temp;
            temp = temp->next;
        }
        p->next = NULL;
        free(temp);
        size--;
        display(head);
        return head;
    }

    // else
    // {

    // }
}

node *reverse(node *head)
{
    // node *temp = head;
    // node *prev = NULL;
    // node *curr = NULL;
    // while (temp != NULL)
    // {
    //     curr = temp->next;
    //     temp->next = prev;
    //     temp->prev = curr;
    //     prev = temp;
    //     temp = curr;
    // }
    // head = prev;

    node* ptr=head;
    node* temp=NULL;
    while(ptr!=NULL){
        temp=ptr->next;
        ptr->next=ptr->prev;
        ptr->prev=temp;
        temp=ptr;
        ptr=ptr->prev;
    }
    head=temp;
    display(head);
    return head;
}

node *deleteByKey(node *head, int key)
{
    node *temp = head;
    int i = 1;
    while (temp != NULL)
    {

        if (temp->data == key)
        {
            if (i == 1)
            {
                head = head->next;
                free(temp);
                size--;
                display(head);
                return head;
            }
            if (i == size)
            {
                temp->prev->next = NULL;
                free(temp);
                size--;
                display(head);
                return head;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
                size--;
                display(head);
                return head;
            }
        }
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Key not found in the list\n");
        return head;
    }
}

int main()
{
    node *head = NULL;
    int ch, data, pos, key;
    while (1)
    {
        printf("\n1.InsertAtPos\n2.DeleteAtPos\n3.Display\n4.Reverse\n5.DeleteByKey\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter position\n");
            scanf("%d", &pos);
            printf("Enter data\n");
            scanf("%d", &data);
            head = insertAtPos(head, data, pos);
            break;

        case 2:
            printf("Enter position\n");
            scanf("%d", &pos);
            head = deleteAtPos(head, pos);
            break;

        case 3:
            head = display(head);
            break;

        case 4:
            head = reverse(head);
            break;

        case 5:
            printf("Enter the key to be deleted\n");
            scanf("%d", &key);
            deleteByKey(head, key);
            break;
        }
    }
}