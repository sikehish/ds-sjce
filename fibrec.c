#include<stdio.h>

int fib(int n){
    if(n<=0) return 0;
    if(n<=2){
        return n-1;
    }
    return fib(n-2) + fib(n-1);
}

void main(){
        int a;
    printf("Enter a number\n");
    scanf("%d",&a);
    // cout<<"The factorial of "<<a<< " is "<<factorial(a)<<endl;
    printf("The term in fibonacci sequence at position %d is %d\n" ,a, fib(a));
}