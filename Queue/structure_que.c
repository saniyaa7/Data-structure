#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct queue
{
int *que;
int f,r;
};


void enq(struct queue* ptr,int x)
{
    if(ptr->r==MAX-1)
    {
        printf("\nQueue Overflow");
        return;
    }
    else
    {
        if(ptr->f==-1)
        {
          ptr->f=0;
          ptr->r=0;
        }
        else
            ptr->r++;


        ptr->que[ptr->r]=x;
    }
}
int deq(struct queue* ptr)
{
    if(ptr->f==-1||ptr->f==ptr->r+1)
    {
        printf("\nQueue Underflow");
        return -1;
    }

       return ptr->que[ptr->f++];

}
void display(struct queue* ptr)
{
    if(ptr->f==-1||ptr->f==ptr->r+1)
    {
       printf("\nEmpty Queue");
       return;
    }

    printf("\nElements in Queue are:\n");
    for(int i=ptr->f;i<=ptr->r;i++)
    {
        printf("%d ",ptr->que[i]);
    }
    printf("\n");


}
int main()
{
    int ch,item;
    struct queue q;
    q.f=q.r=-1;
    printf("\nImplementation oF Queue Using Structure");
    printf("\n_________________________________________\n");


    q.que=(int*)malloc(MAX*sizeof(int));



    while(1)
    {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nEnter your choice(1-4): ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter element to be added: ");
                   scanf("%d",&item);
                   enq(&q,item);
                   break;
            case 2:item=deq(&q);
                   if(item!=-1)
                    printf("\n%d element deleted\n",item);
                    break;
            case 3:display(&q);
            break;
            case 4:exit(1);
            default:printf("\nWrong choice!!!");
        }
    }
}

