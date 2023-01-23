#include<stdio.h>
#include<stdlib.h>
#define Max 5
struct queue
{
int r,f;
int arr[Max];
};
int isEmpty(struct queue* ptr)
{
    if(ptr->f==(ptr->r+1)%Max)
        return 1;
    return 0;
}
int isEmpty(struct queue* ptr)
{
    if(ptr->f==(ptr->r+1)%Max)
        return 1;
    return 0;
}
void enq(struct queue* ptr,int x)
{
    if(isFull(ptr))
    {
        printf("\nQueue overflow");
        return;
    }
    if(ptr->f==-1&&ptr->r==-1)
        ptr->f=ptr->r=0;
        else
    ptr->r=(ptr->r+1)%Max;
    ptr->arr[ptr->r]=x;
}
int deq(struct queue* ptr)
{
    if(isEmpty(ptr))
    {
        printf("\nQueue underflow");
        return -1;
    }
    int x=ptr->arr[ptr->f];
    if(ptr->f==ptr->r)
        ptr->f=ptr->r=-1;
    else
        ptr->f=(ptr->f+1)%Max;
    return x;

}
void display(struct queue* ptr)
{
    int i;
     if(isEmpty(ptr))
    {
        printf("\nQueue is empty");
        return ;
    }
    for( i=ptr->f;i!=ptr->r;i=(i+1)%Max)
        printf("%d ",ptr->arr[i]);
    printf("%d\n",ptr->arr[i]);

}

int main()
{
    int ch,x;
    struct queue q;
    q.f=q.r=-1;
    printf("\nIMPLEMENTATION OF CIRCULAR QUEUE");
    printf("\n_________________________________\n");
    printf("\nEnter the Max size of queue: ");


    while(1)
    {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nEnter your choice:");
        scanf("\n%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter data: ");
                    scanf("%d",&x);
                    enq(&q,x);
                    break;
            case 2:x=deq(&q);
                    if(x!=-1)
                        printf("\n%d element deleted",x);
                    break;
            case 3:display(&q);
                    break;
            case 4:exit(1);
            default:printf("\nplzz enter valid choice!!");
        }
    }
}


















