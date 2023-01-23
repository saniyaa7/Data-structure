#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20
int stack[MAX];
 char post[MAX];
int top;
void push(char x)
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
char eval_postfix()
{
    char temp,r,a,b;
   int len=strlen(post);
    for(int i=0;i<len;i++)
    {
        if(post[i]>='a'&&post[i]<='z')
        {
            push(post[i]);
        }
        else{
            b=pop();
            a=pop();
            switch(post[i])
            {
                case '+':  temp="(a+b)";
                          break;
                case '-':  temp="(a-b)";
                          break;
                case '*':  temp="(a*b)";
                          break;
                case '/':  temp="(a/b)";
                          break;
                case '^':  temp="(a^b)";
                          break;


            }
            temp='\0';
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
    printf("\nEnter expression: ");
    gets(post);
    char x=eval_postfix();

    printf("\nAnswer=%s",x);
    return 0;

}

