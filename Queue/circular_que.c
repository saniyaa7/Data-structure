#include<stdio.h>
#include<stdlib.h>
struct que
{
    int *queue;
    int f,r;
};
int MAX;
int isFull(struct que* p)
{
    if(p->f==(p->r+1)%MAX)
        return 1;
    return 0;
}
int isEmpty(struct que* p)
{
    if(p->f==-1)
        return 1;
    return 0;
}
void enq(struct que* p,int item)
{
    if(isFull(p))
    {
        printf("\nQueue overflow!!");
        return;
    }
    else if(p->f=-1&&p->r==-1)
        p->f=p->r=0;
    else
       p->r=(p->r+1)%MAX;
    p->queue[p->r]=item;
}
int deq(struct que* p)
{
    if(isEmpty(p))
    {
        printf("\nQueue underflow!!");
        return -1;
    }
    int x=p->queue[p->f];
    if(p->f==p->r)
        p->f=p->r=-1;
    else
        p->f=(p->f+1)%MAX;
    return x;
}
void display(struct que* p)
{
    int i;
    if(isEmpty(p))
    {
        printf("\nQueue is empty!!");
        return;
    }
    printf("\nQueue elements are:\n");
    for(int i=p->f;i!=p->r;i=(i+1)%MAX)
    {
        printf("%d ",p->queue[i]);
    }
    printf("%d",p->queue[p->r]);
}

int main()
{
    int ch,x;
    struct que q;
    q.f=q.r=-1;
    printf("\nIMPLEMENTATION OF CIRCULAR QUEUE");
    printf("\n_________________________________\n");
    printf("\nEnter the Max size of queue: ");
    scanf("%d",&MAX);
    q.queue=(int*)malloc(MAX*sizeof(int));
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


















































































































/*#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int f,r;
int que[MAX];
int isFull()
{
    if((f==0&&r==MAX-1)||(r==f-1))
        return 1;
    return 0;
}
int isEmpty()
{
    if(f==-1)
        return 1;
    return 0;
}
void enq(int x)
{
    if(isFull())
        printf("\nQueue is full");
    else{
        if(f==-1)
            f=0;
        r=(r+1)%MAX;
        que[r]=x;


    }
}
int deq()
{ int x;
    if(isEmpty())
    {
        printf("\nQueue is Empty");
        return -1;
    }
    else{

        x=que[f];
        if(f==r)
        {
            f=-1;
            r=-1;
        }
        else{
            f=(f+1)%MAX;
        }
    }
    return x;
}
void display()
{ int i;
    if(isEmpty())
        printf("\nempty Queue");
    else{
        for(i=f;i!=r;i=(i+1)%MAX)
        { printf("%d ",que[i]);
        }

           printf("%d ",que[i]);
    }
}

int main()
{
    int i,x,ch;
    f=r=-1;
    while(1)
    {
        printf("\n1.enqueue 2.dequeue 3.display 4.exit\nEnter your choice(1-4): ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter element to be added:-");
                   scanf("%d",&x);
                   enq(x);
                   break;

             case 2: x=deq();
                     if(x!=-1)
                            printf("\n%d element deleted\n",x);
                     break;
            case 3:display();
                   break;
            case 4:exit(1);

        }
    }
}*/
