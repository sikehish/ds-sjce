// i) Construction ii) Traversals iii) Searching a node by key
// and deleting if exists


#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * rlink;
    struct Node * llink;
}Node;

Node* insert(Node* root, int data)
{
    if(root==NULL) {
        Node* newnode= (Node *)malloc(sizeof(Node));
        newnode->rlink=newnode->llink=NULL;
        newnode->data=data;
        return newnode;
    }
    if(root->data==data) {
        printf("Node with this value already exists\n");
        return root;
    }
    if(data<root->data) root->llink=insert(root->llink,data);
    if(data>root->data) root->rlink=insert(root->rlink,data);
    return root;
}

Node *inOrder_Predecessor(Node *root)
{
    root = root->llink;
    while (root->rlink != NULL)
    {
        root = root->rlink;
    }
    return root;
}
Node* delete(Node *root, int key)
{
    // Base case.
    if (root == NULL) {
        printf("Node not found\n");
        return NULL;
    }
    if (root->data > key) root->llink = delete(root->llink, key);
    else if (root->data < key) root->rlink = delete(root->rlink, key);
    // delete the found Node.
    else
    {
        // Case 1: No child. Leaf Node found.
        if (root->llink == NULL && root->rlink == NULL)
        {
             free(root);
            root = NULL;
        }
        // Case 2: 1 child.
        else if (root->llink == NULL)
        {
            Node *ptr = root;
            root = root->rlink;
            free(ptr);
        }
        else if (root->rlink == NULL)
        {
            Node *ptr = root;
            root = root->llink;
            free(ptr);
        }
        // Case 3: 2 children.
        else
        {
            Node *iPre = inOrder_Predecessor(root);
            root->data = iPre->data;
            root->llink = delete(root->llink, iPre->data); // delete the duplicate from the llink subtree.
        }
    }
    return root;
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
    
    Node* root= NULL;
    int ch,ele;
    while(1)
    {
    printf("1.Build tree\n 2.Delete Node\n 3.Preorder traversal\n 4.Inorder Traversal\n 5.Postorder traversal\n 6.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter element to be inserted\n");
                scanf("%d", &ele);
                root=insert(root,ele);
                break;

            case 2:
                printf("Enter element to be deleted\n");
                scanf("%d", &ele);
                root=delete(root,ele);
                break;

            case 3:
            printf("Preorder traversal is: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
            printf("Inorder traversal is: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
            printf("Postorder traversal is: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
            printf("Exiting..");
            exit(0);

            default: printf("Invalid choice\n");
        }
    }
}