#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int f1,r1,f2,r2;
int que1[MAX],que2[MAX];
int isEmpty()
{
    if(f1==-1||r1==f1-1)
        return 1;
        return 0;
}

void enq1(int x)
{
    if(r1==MAX-1)
    {
        printf("\nqueue overflow");
    }
    else{
        if(f1==-1)
            f1=0;
        que1[++r1]=x;

    }
}

void enq2(int x)
{
    if(r2==MAX-1)
    {
        printf("\nqueue overflow");
    }
    else{
        if(f2==-1)
            f2=0;
        que1[++r2]=x;

    }
}


int deq1()
{
    if(f1==-1||r1==f1-1)
    {
        printf("\nqueue underflow");
    }
    else{
        return que1[f1++];

    }
}

int deq2()
{
    if(f2==-1||r2==f2-1)
    {
        printf("\nqueue underflow");
    }
    else{
        return que1[f2++];

    }
}
void push(int x)
{
    enq2(x);
    while(!isEmpty())

          {
            int a=deq1();
              enq2(a);
          }
    int p[MAX];

     for(int i=r1;i>=f2;i--)
        {
           p[i]=que1[i];
           que1[i]=que2[i];
           que2[i]=p[i];
        }



}
int pop()
{
    if(f1==-1||r1==f1-1)
    {
        printf("\nStack underflow");
    }
    else
    {
       int a= deq1();
       printf("\n%d element deleted",a);
    }
}

void display()
{
    if(f1==-1||r1==f1-1)
    {
        printf("\nstack underflow");
    }
    else{
        for(int i=r1;i>=f1;i--)
        {
            printf("%d ",que1[i]);
        }

    }
}



int main()
{ int ch;
int x;
f1=r1=f2=r2=-1;
 printf("Implementation of stack using Queue ");
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
         case 2: pop();

           break;
           case 3: display();
           break;
           case 4: exit(1);
           break;
    }
   }
   return 0;
}
