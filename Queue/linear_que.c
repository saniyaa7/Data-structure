#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int queue[MAX],f,r;
void enq(int);
int deq();
void display();
int isFull();
int isEmpty();
void main()
{
    int ch,item;
    f=r=-1;
    printf("\nImplementation of linear queue using array");
    printf("\n_________________________________________________\n");
    while(1)
    {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nEnter your choice(1-4):");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter element to be added:");
                    scanf("%d",&item);
                    enq(item);
                    break;
            case 2: item=deq();
                    if(item!=-1)
                        printf("\nDeleted element is %d",item);
                    break;
            case 3: display();
                    break;
            case 4: exit(1);
            default:printf("\nWrong choice!!!");
        }
    }
}
int isEmpty()
{
    if(f==-1 || f==r+1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(r==MAX-1)
        return 1;
    else
        return 0;
}
void enq(int x)
{
    if(isFull())
    {
        printf("\nQueue overflow");
        return;
    }
    if(f==-1)
        f=0;
    queue[++r]=x;
}
int deq()
{
    int x;
    if(isEmpty())
    {
        printf("\nQueue underflow");
        return(-1);
    }
    x=queue[f];
    f++;
    return x;
}
void display()
{
    int i;
    if(isEmpty())
    {
        printf("\nQueue is empty");
        return;
    }
    printf("\nElements in queue are:\n");
    for(i=f;i<=r;i++)
    {
        printf("%d ",queue[i]);
    }
}
