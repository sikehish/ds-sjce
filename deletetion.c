#include<stdio.h>

int main() {
    int arr[20],n,ele,temp,pos;
    printf("Enter the size\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);
    printf("Enter the index at which deletion should occur\n");
    scanf("%d",&pos);
    if(pos>n || pos<=0){
        printf("Deletion not possible\n");
        return -1;
    } 
       printf("Before Deletion\n");
    for(int i=0; i<n; i++) printf("%d ",arr[i]);

    int j=pos-1;
    while(j<n-1) {
        // printf("%d%d",arr[j],arr[j+1]);
        arr[j]=arr[j+1];
        j++;
    }
    n--;
    printf("\nAfter Insertion\n");
    for(int i=0; i<n; i++) printf("%d ",arr[i]);
}