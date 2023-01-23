/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 20
int top;
char stack[MAX],inf[MAX],post[MAX];
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
char pop()
{
    return stack[top--];
}
int prd(char x)
{
    if(x=='(')
        return 1;
    else if(x=='+'||x=='-')
        return 2;
    else if(x=='*'||x=='/')
        return 3;
    else if(x=='^')
        return 4;

}
char inf_post()
{ char x;
int p=0;
char *i;
i=inf;
    while(*i!='\0')
    {
        if(isalnum(*i))
            push(*i);
        else if(*i=='(')
            push(*i);
        else if(*i==')')
        {
            while(stack[top]!='(')
                    post[p++]=pop();
                    pop();

        }
        else
        {
            while(!isEmpty()&&prd(stack[top])>=prd(*i))
            {
                post[p++]=pop();
            }
            push(*i);
        }
        i++;

    }
    while(!isEmpty())
        post[p++]=pop();
    post[p]='\0';



}
int main()
{ char i;
    i=inf;
    top=-1;
    printf("\nconvert infix to postfix\n");
    printf("\nenter infix expresssion: ");
    gets(inf);
   inf_post();
    printf("\npostfix expression : ");
    puts(post);
    return 0;
}*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX 20
int top;
char post[MAX];
int stack[MAX];
void push(int x)
{
    stack[++top]=x;
}
int pop()
{
    return stack[top--];
}
int post_eval()
{
    char post[MAX];
int stack[MAX];
    int a,b,temp;
    int len=strlen(post);

    for(int i=0;i<len;i++)
    {
        if(post[i]>='0'&&post[i]<='9')
        {
            push(post[i]-'0');
        }
        else
        {

          b=pop();
          a=pop();
          switch(post[i])
          {
              case '+': temp=a+b;
                        break;
             case '-': temp=a-b;
                        break;
              case '*': temp=a*b;
                        break;
              case '/': temp=a/b;
                        break;
             case '^': temp=pow(a,b);
                        break;
          }
          push(temp);

        }

    }
    int r=pop();
    return r;
}
int main()
{

    top=-1;
    int x;
    printf("\nenter the postfix expression");
    scanf("%s ",post);
     x=post_eval();
    printf("\nanswer=%d",x);

}



























