#include<stdio.h>
#include<stdlib.h>

typedef struct circular_Q
{
    int f;
    int r;
    int *que;
}queue;
int MAX;
int isEmpty(queue* ptr)
{
    if(ptr->f==-1&&ptr->r==-1)
        return 1;
    return 0;
}
int isFull(queue* ptr)
{
    if(ptr->f==(ptr->r+1)%MAX)
        return 1;
    return 0;
}
void enqueue(queue* ptr,int value)
{
    if(isFull(ptr))
    {
        printf("\nQueue overflow");
        return;
    }


        else if(ptr->f==-1&&ptr->r==-1)
            ptr->f=ptr->r=0;
        else
            ptr->r=(ptr->r+1)%MAX;
        ptr->que[ptr->r]=value;

}
int dequeue(queue* ptr)
{
    if(isEmpty(ptr))
    {
        printf("\nQueue underflow");
        return -1;
    }
    int x=ptr->que[ptr->f];
    if(ptr->f==ptr->r)
        ptr->f=ptr->r=-1;
    else
        ptr->f=(ptr->f+1)%MAX;
    return x;


}
void display(queue* ptr)
{
    int i;
    if(isEmpty(ptr))
    {
        printf("\nQueue is Empty!!");
        return;
    }
    printf("\nElements in queue:\n");
    for(i=ptr->f;i!=ptr->r;i=(i+1)%MAX)
    {
        printf("%d ",ptr->que[i]);
    }
    printf("%d",ptr->que[ptr->r]);

}
int main()
{
    int ch,x;
    queue sp;
    sp.f=sp.r=-1;
    printf("\nImplementation of Circular Queue Using Structure");
    printf("\n__________________________________________________\n");
    printf("\nEnter MAX size of Queue: ");
    scanf("%d",&MAX);
    sp.que=(int*)malloc(MAX*sizeof(int));
    while(1)
    {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
           case 1:printf("\nEnter the data to be insert:");
                scanf("%d",&x);
                enqueue(&sp,x);
                break;
            case 2:x=dequeue(&sp);
                if(x!=-1)
                        printf("\n%d element deleted",x);
                        break;
            case 3:display(&sp);
                    break;
            case 4:exit(0);
            default:printf("\nEnter valid choice!!");



        }
    }
}
