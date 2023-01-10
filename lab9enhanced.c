#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int len;
struct stack
{
    int n;
    int top;
    int *a;
};
void create(struct stack *sp)
{
    printf("Enter size of stack: ");
    scanf("%d",&sp->n);
    sp->a=malloc((sp->n)*sizeof(int));
    if(sp->a==NULL)
    {
        printf("Memory allocation failed...exiting\n");
        exit(0);
    }
    else
    {
        sp->top=-1;
    }
}
int check(char s)
{
    switch(s)
    {
        case '(':
        case ')':return 0;
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 2;
        case '^':
        case '$':return 3;
        default: return-1;
    }
}
void postfix(struct stack *sp,char p[],char ans[])
{
    int i=0,j=0,c;
    while(i!=len)
    {
        c=check(p[i]);
        if(c==-1)
        {
            ans[j++]=p[i];
        }
        else
        {
            if(sp->a[sp->top]==')'||p[i]==')')
            {
                if(sp->a[sp->top]==')')
                   sp->top-=1;
                while(sp->a[sp->top]!='(')
                {
                    ans[j++]=sp->a[sp->top];
                    sp->top-=1;
                }
                sp->top-=1;
            }
            else
            {
                while((check(p[i])!=0)&&(check(p[i])<=check(sp->a[sp->top]))&&sp->top!=-1)
                {
                    if((check(p[i])==3)&&(check(sp->a[sp->top])==3))
                        break;
                    else
                    {
                    ans[j++]=sp->a[sp->top];
                    sp->top-=1;
                    }
                }
                sp->a[++sp->top]=p[i];
            }
        }
        i++;
    }
    while(sp->top!=-1)
    {
        ans[j++]=sp->a[sp->top];
        sp->top-=1;
    }
    printf("Postfix is: ");
    ans[j]='\0';
    for(i=0;i<j;i++)
    {
        printf("%c",ans[i]);
    }
    printf("\n");
}
void prefix(struct stack *sp,char p[],char ans[])
{
    int i=len-1,j=0,c;
    while(i!=-1)
    {
        c=check(p[i]);
        if(c==-1)
        {
            ans[j++]=p[i];
        }
        else
        {
            if(sp->a[sp->top]=='('||p[i]=='(')
            {
                if(sp->a[sp->top]=='(')
                   sp->top-=1;
                while(sp->a[sp->top]!=')')
                {
                    ans[j++]=sp->a[sp->top];
                    sp->top-=1;
                }
                sp->top-=1;
            }
            else
            {
                while((check(p[i])!=0)&&(check(p[i])<check(sp->a[sp->top]))&&sp->top!=-1)
                {
                    ans[j++]=sp->a[sp->top];
                    sp->top-=1;
                }
                sp->a[++sp->top]=p[i];
            }
        }
        i--;
    }
    while(sp->top!=-1)
    {
        ans[j++]=sp->a[sp->top];
        sp->top-=1;
    }
    printf("Prefix is: ");
     ans[j]='\0';
    for(i=j-1;i>=0;i--)
    {
        printf("%c",ans[i]);
    }
    printf("\n");
}
int operate(int a,int b,char s)
{
    switch(s)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        case '^': return pow(a,b);
        case '$': return pow(a,b);
    }
}
void post_eva(struct stack *sp,char p[])
{
    int i=0,j=0,z;
    char op1,op2;
    char d[1];
    while(p[i]!='\0')
    {
        if(i==0)
        {
            printf("enter the value of %c: ",p[i]);
            scanf("%s",d);
            sp->a[0]=d[0];
            sp->top+=1;
        }
        else if((p[i]>='a'&&p[i]<='z')||(p[i]>='A'&&p[i]<='Z'))
        {
            printf("enter the value of %c: ",p[i]);
            scanf("%s",d);
            p[i]=d[0];
           
        }
        i++;
    }
    i=1;
    while(i!=len)
    {
        z=check(p[i]);
        if(z==-1)
        {
            sp->a[++sp->top]=p[i];
        }
        else
        {
            if('0'<=sp->a[sp->top]&&sp->a[sp->top]<='9')
               op2=sp->a[sp->top--]-'0';
            else
               op2=sp->a[sp->top--];
            if('0'<=sp->a[sp->top]&&sp->a[sp->top]<='9')
               op1=sp->a[sp->top]-'0';
            else
               op1=sp->a[sp->top];
            sp->a[sp->top]=operate(op1,op2,p[i]);
        }
        i++;
    }
    printf("Evaluation is: %d\n",sp->a[0]);
}
void main()
{
    struct stack *sp=malloc(sizeof(struct stack));
    create(sp);
   
    int i=0,c,n;
    char p[50]={0};
    char ans[50]={0};
    while(1)
    {
         
        printf("1.Infix to postfix\n2.Infix to prefix\n3.Postfix Evaluation\n4.Exit\nEnter choice\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:printf("enter the expression\n");
                   scanf("%s",p);
                    len=strlen(p);
                   postfix(sp,p,ans);
                   break;
            case 2:printf("enter the expression\n");
                   scanf("%s",p);
                   len=strlen(p);
                   prefix(sp,p,ans);
                   break;
            case 3:printf("enter the expression for evaluation\n");
                   scanf("%s",p);
                   i=0;
                    len=strlen(p);
                   post_eva(sp,p);
                   break;
            case 4:exit(0);
        }
    }
}
