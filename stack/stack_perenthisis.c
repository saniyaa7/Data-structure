#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int top;
char arr[MAX];
int Matched(char a,char b)
{
    if(a=='('&&b==')')
        return 1;
    if(a=='{'&&b=='}')
        return 1;
    if(a=='['&&b==']')
        return 1;
    else
        return 0;
}

int isEmpty()
{
  if(top==-1)
  {
      return 1;
  }
  return 0;
}
void push(char val)
{

       arr[++top]=val;
}

char pop()
{

        return arr[top--];
}
int isParenthisis(char str[])
{
    top=-1;
   arr[MAX];
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='('||str[i]=='{'||str[i]=='[')
        {
            push(str[i]);
        }
        else if(str[i]==')'||str[i]=='}'||str[i]==']')
        {
            if(isEmpty())
            {
                return 0;
            }
               if(!Matched(pop(),str[i]))
                   return 0;


        }

    }
    if(isEmpty())
    {
        return 1;
    }
    else
        return 0;

}
int main()
{

 char str[MAX];
 printf("PARENTHESIS EXPRESION USING STACK");
 printf("\n________________________________\n");
  printf("\nEnter The Expresion: ");
 gets(str);



 if(isParenthisis(str))
 {
     printf("\nPARENTHESIS MATCH!!!");
 }
 else
 {
          printf("\nPARENTHESIS NOT MATCH!!!");
 }
 return 0;
}
