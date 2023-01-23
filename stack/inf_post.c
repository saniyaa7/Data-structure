#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 50
int top;
char stack[MAX],post[MAX];
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
void push(char x)
{
    stack[++top]=x;
}
int pop()
{
        return (stack[top--]);
}
int priority(char x)
{
    if(x=='(')
        return 1;
    if(x=='+'||x=='-')
        return 2;
    if(x=='*'||x=='/')
        return 3;
    if(x=='^')
        return 4;

}
void inf_to_post(char inf[])
{ int i=0,p=0;
char symbol,x;
int len=strlen(inf);
for(i=0;i<len;i++)
{
    symbol=inf[i];
    if(symbol=='(')
        push(symbol);
    else if(symbol==')')
    {
        while(stack[top]!='(')
        {
            post[p++]=pop();
        }
        char ele=pop();
    }
    else if(isalnum(symbol))
    {
        post[p++]=symbol;
    }
    else{
        while(!isEmpty()&&(priority(stack[top])>=priority(symbol)))
        {
           post[p++]=pop();
        }push(symbol);
    }
}
    while(!isEmpty())
    {
        post[p++]=pop();
    }
    post[p]='\0';
}
int main()
{
    top=-1;
    char inf[MAX];
    printf("\n INFIX TO POSTFIX CONVERSION USING STACK");
    printf("\n ________________________________________\n");
    printf("\nEnter the infix expresion: ");
    scanf("%s",inf);
    printf("\npostfix expression: ");
    inf_to_post(inf);

    printf("%s",post);
    printf("\n");


}

