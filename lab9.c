#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack{
    int size; char* arr;
    int top;
}Stack;

void push(Stack *ptr, char val)
{
    if(ptr->top==(ptr->size)-1)
    {
    ptr->arr=realloc(ptr->arr, 2*(ptr->size));
    ptr->size*=2;
    }
    ptr->arr[++(ptr->top)]=val;
}

int pop(Stack* ptr)
{
    char val= ptr->arr[(ptr->top)--];
    return val;
}

int precedence(char c)
{
    if(c=='$' || c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;

    return -1;
}

int infixToPostfix(char* carr, int clen, char* res)
{
    Stack* st=malloc(sizeof(Stack));
    st->top=-1;
    st->size=clen;
    st->arr=(char *)malloc(st->size);
    int j=0;
    for(int i=0; i<clen; i++)
    {
        
        char c=carr[i];
        if(c=='(' || (precedence(c)!=-1 && st->top==-1)) push(st, c);
        else if(c==')')
        {
            while(st->arr[st->top]!='(')
            {
                int x=pop(st);
                res[j++]=x;
            }
            pop(st);
        }
        else if(precedence(c)==-1) {
            res[j++]=c;
        }
        else if(precedence(c)>precedence(st->arr[st->top])) push(st,c);
        else{
            while(precedence(st->arr[st->top])>=precedence(c) && (precedence(c)!=3 && precedence(st->arr[st->top])!=3))
            {
                int x=pop(st);
                res[j++]=x;
            }
            push(st,c);
        }
        printf("%c\n", carr[i]);
    }
    while(st->top!=-1) res[j++]=pop(st);
    res[j]='\0';
    return j;
}

int main()
{
    char c[20];
    char res[20];
    printf("Enter the expression\n");
    scanf("%s",c);
    int reslen=infixToPostfix(c,strlen(c),res);
    printf("Resultant postfix expression is:\n");
    printf("%s",res);
}