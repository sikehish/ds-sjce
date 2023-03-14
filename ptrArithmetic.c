#include <stdio.h>

int main() {

    int x[10], *p,n;
  
    printf("Enter the size of the array\n");
    scanf("%d", &n);
  
    printf("Enter the elements\n");
    for(p=x; p<x+n; p++) scanf("%d",p);
  
    printf("Displaying the elements\n");
    for(p=x; p<x+n; p++) printf("%d ",*p);
  
    printf("\nDisplaying the elements in reverse order\n");
    for(p=x+n-1; p>=x; p--) printf("%d ",*p);
  
    int * s=x, *e=x+n-1;
  
    while(s<e){
        *s=*s+*e;
        *e=*s-*e;
        *s=*s-*e;
        s++;
        e--;
    }
  
    printf("\nDisplaying the elements after array reversal\n");
    for(p=x; p<x+n; p++) printf("%d ",*p);
  
    return 0;
}
