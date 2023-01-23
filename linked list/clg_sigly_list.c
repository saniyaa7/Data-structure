#include<stdio.h>
#include<stdlib.h>
#define Max 10
int stk[Max],top;
void push(char x)
{
    stk[++top]=x;
}
char pop()
{
    top=top-1;
}
int isEmpty()
{
    if(top==-1)
        return 1;
    return 0;
}

int main()
{
  top=-1;
    char s[100];
    printf("\nEnter the string: ");
    scanf("%s",s);
        for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='(')
            push(s[i]);
        else if(s[i]==')')
        {
            pop();
        }
    }
    if(top==-1)
        printf("\nBalance parentheseis");
    else
        printf("\nnot Balance parentheseis");
}
