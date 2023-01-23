#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20
int stack[MAX];
 char post[MAX];
int top;
void push(int x)
{
    if(top==MAX-1)
    {
        printf("\nstack overflow");
        exit(1);
    }
 stack[++top]=x;

}
int pop()
{
    if(top==-1)
    {
        printf("\nStack underflow");
        exit(1);
    }
return stack[top--];
}
int eval_postfix()
{
    int len,temp,r,a,b,x;
    len=strlen(post);
    for(int i=0;i<len;i++)
    {
        if(post[i]>='0'&&post[i]<='9')
        {
            push(post[i]-'0');
        }
        else{
            b=pop();
            a=pop();
            switch(post[i])
            {
                case '+':  temp=a+b;
                          break;
                case '-':  temp=a-b;
                          break;
                case '*':  temp=a*b;
                          break;
                case '/':  temp=a/b;
                          break;
                case '^':  temp=pow(a,b);
                          break;

            }
            push(temp);
        }
    }
    r=pop();
    return r;
}
int main()
{ int top=-1;

    printf("\nEVALUATION OF POSTFIX EXPRESSSION\n");
    printf("\n__________________________________\n");
    printf("\nEnter the postfix expression: ");
    scanf("%s",post);
    int x=eval_postfix();
    printf("\nAnswer=%d",x);
    return 0;

}
