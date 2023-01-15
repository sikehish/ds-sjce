#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack{
    char* arr;
    int top;
    int size;
}Stack;

void push(Stack* s, char data)
{
    if(s->top==(s->size)-1) s->arr=(char *)realloc(s->arr, 2 * (s->size));
    s->arr[++(s->top)]=data;
}

int pop(Stack *s){

return s->arr[(s->top)--];
}

int prec(char a)
{
    if(a=='(' || a==')') return 0;
    if(a=='^' || a=='$') return 3;
    if(a=='*' || a=='/') return 2;
    if(a=='+' || a=='-') return 1;
    else return -1;
}

void infixToPostfix(char* exp, int size, char* ans)
{
    Stack* s= (Stack *)malloc(sizeof(Stack));
    s->top=-1;
    s->size=size;
    s->arr=(char *)malloc(size);
    int i=0,j=0;
    for(i=0; i<size; i++)
    {
        char a=exp[i];
        if(prec(a)==-1) ans[j++]=a;
        else if(a==')'){
            while(s->arr[s->top]!='(') {
                ans[j++]=pop(s);
            }
            pop(s);
        } 
        else if (s->top==-1 || prec(a)>prec(s->arr[s->top]) || a=='(') push(s, a);
        
        else if(prec(a)==3 && prec(s->arr[s->top]==3)) push(s,a);
        else {
            while (prec(a)<=prec(s->arr[s->top]) && s->top!=-1){
                ans[j++]=pop(s);
            }
            push(s,a);
        }
    }
    while(s->top!=-1)
    {
        ans[j++]=pop(s);
    }
    ans[j]='\0';
    printf("Postfix is: %s",ans);
}



void main(){
    char exp[50];
    char ans[50];
    printf("Enter exp\n");
    scanf("%s", exp);
    infixToPostfix(exp, strlen(exp), ans);
}