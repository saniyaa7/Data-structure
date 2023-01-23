#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct stack
{  int *arr;
    int top;
};
int isFull(struct stack *ptr)
{
    if(ptr->top=MAX-1)
    {
        return 1;
    }
    else{return 0;}
}
int isEmpty(struct stack *ptr)
{
    if(ptr->top=-1)
    {
        return 1;
    }
    else{return 0;}
}
int pop(struct stack *ptr)

{ int x;
    if(isFull(ptr))
    {
        printf("\nstack is overflow");
        return;
    }
    else{
        ptr->top=ptr->top-1;
        }
}
void push(struct stack *ptr,int x)
{
    if(isEmpty(ptr))
    {
        printf("\nstack is overflow");
        return 0;
    }
    else{
        ptr->top=ptr->top+1;
        ptr->arr[ptr->top]=x;

    }
}
void display(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("stack underflow");
        return(-1);
    }
    else{
    for(int i=ptr->top;i>=0;i--)
    {
        printf("%d ",ptr->arr[i]);
    }
    }
}
int main()
{
    int ch,x;
    struct stack sp;


    sp.top=-1;
    sp.arr=(int*)malloc(MAX*sizeof(int));
    while(1)
    {
        printf("\n1,push 2.pop 3.display 4.exit");
        printf("Enter the choice(1-4)");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter the element");
            scanf("%d",&x);
                push(&sp,x);
                break;

            case 2:pop(&sp);
            break;
            case 3:display(&sp);
            break;
            case 4:exit(0);
            break;
        }
    }
}























