#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
struct stack
{
    int top;
    char arr[MAX];
};

void push(struct stack *ptr,char val)
{
        ptr->top=ptr->top+1;
        ptr->arr[ptr->top]=val;
}

char pop(struct stack *ptr)
{
        ptr->top=ptr->top-1;
}
int main()
{
struct stack s;
s.top=-1;
 char str[MAX];

 printf("PARENTHESIS EXPRESION USING STACK");
 printf("\n________________________________\n");
  printf("\nEnter The Expresion");
 gets(str);

 for(int i=0;str[i]!='\0';i++)
 {
     if(str[i]=='(')
     {
         push(&s,str[i]);
     }
     else if(str[i]==')')
     {
        pop(&s);
     }
 }
 if(s.top==-1)
 {
     printf("\nBalanced Parenthesis");
 }
 else{
    printf("\nNon Balanced Parenthesis");
 }
 return 0;
}

