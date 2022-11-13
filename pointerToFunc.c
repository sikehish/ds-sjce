#include <stdio.h>


int mul(int a,int b){
    printf("%d\n",a*b);
}

int op(int a,int b){
    printf("%d\n",a+b);
}

int main() {
    // int (* add)()=mul;
    //OR
    int (* add)();
    add=mul;
    add(2,3);
    add=op(2,3);
    
}