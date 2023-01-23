#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 40

struct stack
{
   int top;
char str[MAX];


};
char pop(struct stack*);
void push(struct stack*,char);
int main()
{
    struct stack sp;
char s[MAX];
sp.top=-1;
printf("\nREVERSING A STRING USING STACK");
printf("\n_______________________________\n");
    printf("\nENTER STRING: ");
    gets(s);
    for(int i=0;i<strlen(s);i++)
    {
        push(&sp,s[i]);
    }
    printf("\nREVERSED STRING: ");

    for(int i=sp.top;i>=0;i--)
    {
        printf("%c",pop(&sp));
    }
    return 0;



}
void push(struct stack*p,char c)
{

        p->str[++p->top]=c;

}
char pop(struct stack*p)
{

    return p->str[p->top--];
}
