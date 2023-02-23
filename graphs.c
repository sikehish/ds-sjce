#include <stdio.h>
#include <stdlib.h>
int N;

void bfs(int a[][N], int visited[], int start){
    int q[N];
    int f=0,r=-1;
    printf("%d ", start);
    q[++r]=start; visited[start]=1;
    while(f<=r){
        int i=q[f++];
        for(int j=0; j<N; j++){
            if(a[i][j] && visited[j]==0){
                q[++r]=j;
                visited[j]=1;
                printf("%d ", j);
            }
        }
    }
    
    
}

void dfs(int a[][N], int visited[], int start){
     printf("%d ", start);
    visited[start] = 1;
    for (int j = 0; j < N; j++)
    {
        if(a[start][j]==1 && !visited[j]){
            dfs(a, visited, j);
        }
    }
}

void main(){
    int matrix[10][10]; //Declaring adjacency matrix of Graph
 int visited[10]; //Declaring the Visited Array
 int choice,i,j;
 printf("Menu\n1.Enter the Graph\n2.BFS Traversal\n3.DFS Traversal\n4.Exit\n");
 for(;;)
 {
 printf("\nEnter Your Choice : ");
 scanf("%d",&choice);
 switch (choice)
 {
 case 1 : printf("Enter the Number of Nodes : ");
    scanf("%d",&N);
    printf("Enter the Adjacency Matrix :\n");
    for(i=0;i<N;i++)
    for(j=0;j<N;j++)
    scanf("%d",&matrix[i][j]);
    break;
    case 2 :
    for(int i=0; i<N; i++) visited[i]=0;
    printf("BFS Traversal : ");
    bfs(matrix,visited,0);
    printf("\n");
    break;
     case 3 : 
     for(int i=0; i<N; i++) visited[i]=0; 
     printf("DFS Traversal : ");
    dfs(matrix,visited,0);
    printf("\n");
    break;
     case 4 : printf("Exiting...\n");
        exit(0);
     default: printf("Invalid Choice\n");
     }
 }
}
