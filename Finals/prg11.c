#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Stack{
    int* arr;
    int top;
    int size;
}Stack;

void push(Stack* s, int data)
{
    if(s->top==(s->size)-1) s->arr=(int *)realloc(s->arr, 2 * (s->size) * sizeof(int));
    s->arr[++(s->top)]=data;
}

int pop(Stack *s){
return s->arr[(s->top)--];
}

int prec(char a) //check if its operator or not
{
    if(a=='^' || a=='$') return 3;
    if(a=='*' || a=='/') return 2;
    if(a=='+' || a=='-') return 1;
    else return 0;
}

int operate(int op1, int op2, char a){
    switch(a){
        case '+': return op1+op2;
        case '-': return op1-op2;
        case '*': return op1*op2;
        case '/': return op1/op2;
        case '^': 
        case '$': return pow(op1,op2);
    }
}


void postEval(char* exp, int size)
{
    Stack* s= (Stack *)malloc(sizeof(Stack));
    s->top=-1;
    s->size=size;
    s->arr=(int *)malloc(size * sizeof(int));
    int i=0,j=0;
    for(i=0; i<size; i++)
    {
        char a=exp[i];
        if(prec(a)==0) {
            int d=a-'0';
            push(s,d);
        }
        else if (prec(a)>0){
            int op1=pop(s);
            int op2=pop(s);
            printf("op1 %d op2 %d\n",op1,op2);
            push(s, operate(op2,op1,a));
        }
    }
    printf("Postfix eval is: %d\n\n",s->arr[s->top]);
}


void preEval(char* exp, int size)
{
    Stack* s= (Stack *)malloc(sizeof(Stack));
    s->top=-1;
    s->size=size;
    s->arr=(int *)malloc(size * sizeof(int));
    int i=0,j=0;
    for(i=size-1; i>=0; i--)
    {
        char a=exp[i];
        if(prec(a)==0) {
            int d=a-'0';
            push(s,d);
        }
        else if (prec(a)>0){
            int op1=pop(s);
            int op2=pop(s);
            push(s, operate(op1,op2,a));
        }
    }
    printf("Prefix eval is: %d\n\n",s->arr[s->top]);
}


void main(){
    char exp[50];
    int ch;
    while(1){
        printf("Enter 1.Postfix Evaluation 2.Prefix Evaluation 3.Exit\n");
        scanf("%d", &ch);
        switch(ch){

            case 1:
            printf("Enter exp\n");
            scanf("%s", exp);
            postEval(exp, strlen(exp));
            break;

            case 2:
            printf("Enter exp\n");
            scanf("%s", exp);
            preEval(exp, strlen(exp));
            break;

            case 3:
            exit(0); 

            default:
            printf("Invalid choice\n");

        }
    }

}