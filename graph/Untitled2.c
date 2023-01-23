#include<stdio.h>
#include<stdlib.h>
#define MAX 5
 struct queue
 {
   int items[MAX];
   int f,r;
 };
 int isFull(struct queue*);
 int isEmpty(struct queue*);
 void enq(struct queue*, int);
 int deq(struct queue*);
 void display(struct queue*);
int main()
{
    int ch,x;
    struct queue q;
    q.f=q.r=-1;
    printf("\nImplementation of circular Queue using structure");
    printf("\n________________________________________________________\n");
    while(1)
    {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nEnter your choice(1-4):");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter element to be added:");
                    scanf("%d",&x);
                    enq(&q,x);
                    break;
            case 2: x=deq(&q);
                    if(x!=-1)
                        printf("\nDequeued element is %d",x);
                    break;
            case 3: display(&q);
                    break;
            case 4: exit(1);
            default:printf("\nWrong choice!!!");
        }
    }
    return 0;
}
int isFull(struct queue *ptr)
 {
    if(ptr->f==((ptr->r)+1)%MAX)
        return 1;
    else
        return 0;
 }
 int isEmpty(struct queue *ptr)
 {
    if(ptr->f==-1)
        return 1;
    else
        return 0;
 }
void enq(struct queue *p, int x)
 {
    if(isFull(p))
    {
        printf("\nQueue overflow");
        return;
    }
    if(p->f==-1)
        p->f=0;
    p->r=((p->r)+1)%MAX;
    p->items[p->r]=x;
 }
int deq(struct queue *p)
 {
    int x;
    if(isEmpty(p))
    {
        printf("\nQueue underflow");
        return(-1);
    }
    x=p->items[p->f];
    if(p->f==p->r)
    {
        p->f=-1;
        p->r=-1;
    }
    else
    {
        p->f = ((p->f)+1)%MAX;
    }
    return x;
 }
void display(struct queue *p)
 {
     int i;
     if(isEmpty(p))
     {
         printf("\nQueue is empty");
         return;
     }
     printf("\nQueue elements are:\n");
     i=p->f;
     while(i!=p->r)
     {
         printf("%d ",p->items[i]);
         i=(i+1)%MAX;
     }
     printf("%d ",p->items[i]);
 }
