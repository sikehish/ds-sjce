//array operations

#include<stdio.h>
#include<stdlib.h>

int size=0;

int* read(int *p){
    if(size<=0){
        printf("Operations cannot be performed\n");
        exit(0);
    }
    
    else{
         p=(int*)malloc(sizeof(int)*size);
        printf("Enter the element one by one\n");
        for(int i=0;i<(size);i++){
            scanf("%d",(p+i));
        }
        return p;
    }
}

void display(int *p){
    if(size<=0){
        printf("Operations cannot be performed\n");
    }
    
    else{
        printf("The enter elements of the array are\n");
        for(int i=0;i<size;i++){
            printf("%d\t",*(p+i));
        }
    }
}

int* insertByPos(int *p){
    int value,pos;
    printf("Enter the element to be inserted\n");
    scanf("%d",&value);
    printf("Enter the position where the element is to be inserted\n");
    scanf("%d",&pos);

    if(pos>size+1 || pos<1) {
        printf("Inavlid position\n");
        return p;
    }

    size=size+1;
    
    p=(int *)realloc(p,(size)*sizeof(int));
    int i=0;
    for(i=size-1;i>pos-1;i--){
        p[i]=p[i-1];
    }
    p[i]=value;
    printf("The updated array is \n");
    display(p);
    printf("\n");
    return p;
    
}

int* deleteAtPos(int *p){
    int pos;
    printf("Enter the position at which the element is to be deleted\n");
    scanf("%d",&pos);

    if(pos>size || pos<1) {
        printf("Inavlid position\n");
        return p;
    }

    for(int i=pos;i<size;i++){
        p[i-1]=p[i];
    }
    size=size-1;
    p=(int *)realloc(p,(size)*sizeof(int));
    printf("The updated array is \n");
    display(p);
    printf("\n");
    return p;
}

int* insertByKey(int *p){
    int k;
    printf("Enter the key\n");
    scanf("%d", &k);
    int f=0;
    int i=0;
    for(i=0; i<size; i++)
    {
        if(p[i]==k) {
            f=1; break;
        }
    }
    if(f){
        printf("Element %d present at pos %d\n",k,i+1);
        return p;
    }else {
        
    size=size+1;
    p=(int *)realloc(p,(size)*sizeof(int));
    p[size-1]=k;
    printf("The updated array is \n");
    display(p);
    printf("\n");
    return p;
    }
}

int* deleteByKey(int *p){
    int key;
    printf("Enter the key\n");
    scanf("%d",&key);
    int i=0,flag=0;
    for(i=0;i<size;i++){
        if(p[i]==key){
             printf("i: %d p[i]: %d key: %d\n",i, p[i], key);
            flag=1;
            break;
        }
    }
   
    if(flag=0){
        printf("The key is not present in the array \n");
        return p;
    }
    else{
        for(int j=i;j<size-1;j++){
            p[j]=p[j+1];
        }
        size=size-1;
        printf("The updated array is \n");
        p=(int *)realloc(p,(size)*sizeof(int));
        display(p);
        return p;
    }
    
      printf("\n\n");
    
}

int* insertSort(int *p){
    printf("The current staus of the array\n");
    display(p);
    int key,temp;
    printf("Enter the element to be inserted \n");
    scanf("%d",&key);
    
    p=(int *)realloc(p,(size+1)*sizeof(int));
    p[size]=key;
    size=size+1;
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(p[j]>p[j+1]){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    printf("The updated array is .\n");
    display(p);
      printf("\n\n");
      return p;
}

void searchByKey(int *p){
    int key,pos=1,flag=0;
    
    printf("Enter the ele to be searched \n");
    scanf("%d",&key);
    for(int i=0;i<size;i++){
        if(p[i]==key){
            flag=1;
            break;
        }
        pos+=1;
    }
   if(flag==1){
       printf("The element is found at position %d\n",pos);
       display(p);
   }
   else{
       printf("Element not found\n");
   }
   
   printf("\n\n");
   
}

void searchByPos(int *p){
    int pos;
    printf("Enter the position \n");
    scanf("%d",&pos);
    if(pos>size || pos<1){
        printf("The position is invalid\n");
    }
    else{
        printf("The element at the position %d is %d",pos,p[pos-1]);
        printf("\n\n");
    }
}

void reverse(int *p){
    int l=0;
    int r=size-1;
    int temp=0;
    while(l<r){
        temp=p[l];
        p[l]=p[r];
        p[r]=temp;
        l++; r--;
    }
printf("The reversed array is .\n");
    display(p);
      printf("\n\n");
}

void main(){
    int *p=NULL;
    int s,choice;
    printf("Enter the size of the array for which memeory has to be allocated dynamically\n");
    scanf("%d",&s);
    size=s;
    p=read(p);
    display(p);
    while(1){
        printf("\n1.Insert by position\n2.Delete by position\n3.Insert by key\n4.Delete by key\n5.Insert By Order\n6.Search by key\n7.Search By position\n8.Reverse the array\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:p=insertByPos(p);
                    break;
            case 2:p=deleteAtPos(p);
                        break;
                        
            case 3:p=insertByKey(p);
                        break;
                        
            case 4:p=deleteByKey(p);
                        break;
                        
            case 5:p=insertSort(p);
                        break;
                        
            case 6:searchByKey(p);
                   break;
                   
            case 7:searchByPos(p);
                        break;
                        
            case 8:reverse(p);
                        break;
            case 9:exit(0);
            
            default:printf("Inavalid choice\n");
                    break;
        }
        
    
    }
        
}



