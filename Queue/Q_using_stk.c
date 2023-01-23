#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int top1,top2;
int stack1[MAX],stack2[MAX];
int count=0;


void push1(int x)
{
   if(top1==MAX-1)
   {
       printf("\nStack overflow");
       return;
   }
   stack1[++top1]=x;
}

void push2(int x)
{

   stack2[++top2]=x;
}

int pop1()
{
   if(top1==-1)
   {
       printf("\nStack underflow");

   }
   else
        return stack1[top1--];
}

int pop2()
{
   if(top2==-1)
   {
       printf("\nStack underflow");

   }
   else
      return stack2[top2--];
}
void enq(int x)
{
    push1(x);
    count++;
}
int deq()
{
    if(top1==-1&&top2==-1)
    {
        printf("\nQueue underflow");

    }
    else{


    for(int i=0;i<count;i++)
    {
        int item=pop1();
        push2(item);

    }
    int b=pop2();
    printf("\n%d elelment deleted\n",b);
    count--;
    for(int i=0;i<count;i++)
    {
        int a=pop2();
        push1(a);

    }

}
}
void display()
{
    if(top1==-1&&top2==-1)
    {
        printf("\nQueue is Empty!!");
        return;
    }
    for(int i=0;i<=top1;i++)
    {
        printf("%d ",stack1[i]);
    }
}
int main()
{
    int ch,item;
    top1=top2=-1;
    printf("\nIMPLEMENTATION OF QUEUE USING STACK!!!\n");
    printf("\n_______________________________________\n");



    while(1)
    {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nEnter your choice(1-4): ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter element to be added: ");
                   scanf("%d",&item);
                   enq(item);
                   break;
            case 2:deq();

                    break;
            case 3:display();
            break;
            case 4:exit(1);
            default:printf("\nWrong choice!!!");
        }
    }
}

