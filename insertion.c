#include<stdio.h>

int main() {
    int arr[20],n,ele,temp,pos;
    printf("Enter the size\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);
    printf("Enter the elemnt to be inserted along wih the pos\n");
    scanf("%d%d",&ele,&pos);
    if(pos>n+1 || pos<=0){
        printf("Enter a valid position\n");
    };
       printf("Before Insertion\n");
    for(int i=0; i<n; i++) printf("%d ",arr[i]);
    int j=n-1;
    while(j>=pos-1) {
        arr[j+1]=arr[j];
        j--;
    }
    arr[pos-1]=ele;
    printf("\nAfter Insertion\n");
    for(int i=0; i<n+1; i++) printf("%d ",arr[i]);
}