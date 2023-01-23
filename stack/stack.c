#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int stack[MAX],top;
int pop();
void push(int);
void display();
int main()
{ int ch;
int x;
top=-1;
 printf("Implementation of stack using array ");
    printf("\n__________________________________\n");
   while(1)
   {

    printf("\n1.push 2.pop 3.display 4.exit");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("\nenter element to push: ");
        scanf("%d",&x);
         push(x);
         break;
         case 2: x=pop();
         if(x!=-1)
           printf("%d popped\n",x);
           break;
           case 3: display();
           break;
           case 4: exit(0);
           break;
    }
   }
   return 0;
}
void push(int x)
{
    if(top==MAX-1)
      {
         printf("stack overflow");
         return;}
    top=top+1;
    stack[top]=x;
}

int pop()
{ int x;
    if(top==-1)
    {
        printf("stack underflow");
        return -1;
    }
        x=stack[top];


    top=top-1;
    return x;
}

void display()
{
    int i;
    if(top==-1)
    {
        printf("\nStack is empty");
        return;
    }
    printf("\nElements in stack are:\n");
    for(i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
}
