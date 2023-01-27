#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * rlink;
    struct node * llink;
}Node;

void insert(Node* root, int data)
{
    if(data<root->data && root->llink!=NULL) {
        insert(root,data);
    }

    if(data<root->data && root->llink==NULL) {
        Node* ele= (Node *)malloc(sizeof(Node));
    ele->data=data;
    ele->llink=NULL;
    ele->rlink=NULL;
    root->llink=ele;
    printf("Inserted %d ...\n", data);
    return;
    }

    if(data>root->data && root->rlink!=NULL) {
        insert(root,data);
    }

if(data>root->data && root->rlink==NULL) {
        Node* ele= (Node *)malloc(sizeof(Node));
    ele->data=data;
    ele->llink=NULL;
    ele->rlink=NULL;
    root->rlink=ele;
    printf("Inserted %d ...\n", data);
    return;
    }
    

}

void preorder(Node* root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->llink);
    preorder(root->rlink);
}

void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->llink);
    printf("%d ",root->data);
    inorder(root->rlink);
}

void postorder(Node* root){
    if(root==NULL) return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d ",root->data);
}

void main()
{
    
    Node* root= (Node *)malloc(sizeof(Node));
    root->llink=NULL;
    root->rlink=NULL;
    printf("Enter the data to be stored in root node\n");
    scanf("%d", &root->data);
    int ch,ele;
    while(1)
    {
    printf("1.Build tree\n 2.Preorder traversal\n 3.Inorder Traversal\n 4.Postorder traversal\n 5.Exit");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter element to be inserted\n");
                scanf("%d", &ele);
                insert(root,ele);
                break;

            case 2:
            printf("Preorder traversal is: ");
                preorder(root);
                printf("\n");
                break;

            case 3:
            printf("Inorder traversal is: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
            printf("Postorder traversal is: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
            printf("Exiting..");
            exit(0);

            default: printf("Invalid choice\n");
        }
    }
}