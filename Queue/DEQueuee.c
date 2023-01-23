#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int top;
int que[MAX];
int f,r;
void enqF(int x)
{
    if((f==0&&r==MAX-1)||r==f-1)
    {
        printf("\nQueue Overflow");
        return;
    }
    else
    {
        if(f==-1)
        {
          f=0;
          r=0;
        }
    else if(f==0)
        r=MAX-1;
        else
            f=f-1;


        que[f]=x;
    }
}
void enqR(int x)
{
    if((f==0&&r==MAX-1)||r==f-1)
    {
        printf("\nQueue Overflow");
        return;
    }
    else
    {
        if(f==-1)
        {
          f=0;
          r=0;
        }
    else if(r==MAX-1)
        r=0;
        else
            r=r+1;


        que[r]=x;
    }
}
int deqF()
{ int x;
    if(f==-1)
    {
        printf("\nQueue Underflow");
        return -1;
    }
    else{

        x=que[f];
        if(f==r)
            f=r=-1;
        else if(f==MAX-1)
            f=0;
        else
            f=f+1;

       return x;
    }

}
int deqR()
{ int x;
    if(f==-1)
    {
        printf("\nQueue Underflow");
        return -1;
    }
    else{

        x=que[r];
        if(f==r)
            f=r=-1;
        else if(r==0)
            r=MAX-1;
        else
            r=r-1;

       return x;
    }

}
void display()
{
   if(f==-1)
    {
        printf("\nQueue is Empty");
        return;
    }
    int i;
    printf("\nfront=%d \nrear=%d\n\n",f,r);
    for(i=f;i!=r;i=(i+1)%MAX)
    {
        printf("%d ",que[i]);
    }
    printf("%d ",que[i]);
}

int main()
{
    int ch,item;
    f=r=-1;



    while(1)
    {
        printf("\n1.Enqueue at front 2.Enqueue at rear 3.Dequeue at front \n4.Dequeue at rear 5.Display 6.Exit\nEnter your choice(1-4): ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter element to be added: ");
                   scanf("%d",&item);
                   enqF(item);
                   break;
            case 2:printf("\nEnter element to be added: ");
                   scanf("%d",&item);
                   enqR(item);
                   break;

            case 3:item=deqF();
                   if(item!=-1)
                    printf("\n%d element deleted\n",item);
                    break;
            case 4:item=deqR();
                   if(item!=-1)
                    printf("\n%d element deleted\n",item);
                    break;
            case 5:display();
            break;
            case 6:exit(1);
            default:printf("\nWrong choice!!!");
        }
    }
}

