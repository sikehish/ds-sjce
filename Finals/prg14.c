// i) Construction ii) Traversals  iii) Searching a node by key
// and displaying its information along with its parent is exists, otherwise a suitable
// message. iv) Counting all types of nodes. v) Finding height


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

Node* search(Node* root, int data)
{
      if (root == NULL)
      {
        printf("Node not found\n");
        return NULL;
      }
      
      if(root->data == data) {
        printf("Node found: Value= %d\n",root->data);
        return root;
      }
    // Key is greater than root's key
    if (root->data < data)
    {
    if(root->rlink!=NULL && root->rlink->data==data) printf("Parent Node: Value= %d\n",root->data);
       return search(root->rlink, data);
    }
 
    // Key is smaller than root's key
    if(root->llink!=NULL && root->llink->data==data) printf("Parent Node: Value= %d\n",root->data);
    return search(root->llink, data);
}


int totalNodes(Node* root)
{
    if (root == NULL)
        return 0;

    int l = totalNodes(root->llink);
    int r = totalNodes(root->rlink);
 
    return 1 + l + r;
}

//Path having lagest no of edges from the leaf node to root
int height(Node* node)
{
    if (node == NULL || (node->llink==NULL && node->rlink==NULL))
        return 0;
    else {
        /* compute the depth of each subtree */
        int lh = height(node->llink);
        int rh = height(node->rlink);
 
        /* use the larger one */
        if (lh > rh)
            return (lh + 1);
        else
            return (rh + 1);
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
    
    Node* root= NULL;
    int ch,ele;
    while(1)
    {
    printf(" 1.Build tree\n 2.Search Node\n 3.Preorder traversal\n 4.Inorder Traversal\n 5.Postorder traversal\n 6.Count Nodes\n 7.Find Height\n 8.Exit\n");
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
                printf("Enter element to be searched\n");
                scanf("%d", &ele);
                search(root,ele);
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
                printf("Total Number of nodes: %d\n", totalNodes(root));
                break;

            case 7:
                printf("Total Height: %d\n", height(root));
                break;

            case 8:
            printf("Exiting..");
            exit(0);

            default: printf("Invalid choice\n");
        }
    }
}