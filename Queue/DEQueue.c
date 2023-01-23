#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int f,r;
int que[MAX];
int isFull()
{
    if((f==0&&r==MAX-1)||r==f-1)
        return 1;
    return 0;
}
int isEmpty()
{
    if(f==-1)
        return 1;
    return 0;
}


void enqf(int x)
{
if(isFull())
    printf("\nQueue overflow");
else{
        if(f==-1&&r==-1)
        f=r=0;
else if(f==0)
    f=MAX-1;
else
    f=f-1;
que[f]=x;


}

}


void enqR(int x)
{
    if(r==MAX-1)
    {
        printf("\nQueue Overflow");

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
            r++;


        que[r]=x;
    }
}
int deqF()
{
if(isEmpty())
{
   printf("\nQueue underflow");
   return -1;
}

else
{ int x=que[f];
    if(r==f)
        f=r=-1;
    else if(f==MAX-1)
        f=0;
    else
        f=f+1;
    return x;

}

}
int deqR()
{
    if(isEmpty())
{
   printf("\nQueue underflow");
   return -1;
}
else{ int x=que[r];



    if(f==r)
    f=r=-1;
    else if(f==0)
    f=MAX-1;
    else
        r=r-1;
    return x;


}


}
void display()
{if(isEmpty())
{
    printf("\nQueue underflow");
return;

}


else
{
 int i;
 printf("\n Elements are: ");
for(int i=f;i!=r;i=i%MAX)
{
    printf("%d ",que[i]);
}
printf("%d ",que[i]);
}
}

int main()
{
    int ch;
    int x,z;
    int f=r=-1;
    while(ch!=6)
    {
        printf("\n1.enq(f) 2.enq(r) 3.deq(f) 4.deq(r) 5.display 6.exit\n");
        printf("please enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
             case 1: printf("\nEnter the number to be added: ");
             scanf("%d ",&x);
             enqf(x);
             break;

             case 2:
             printf("\nEnter the number to be added: ");
            scanf("%d ",&x);
             enqR(x);
                   break;

             case 3:z=deqF();
                    if(z!=-1)
                        printf("\n%d element deleted",z);
                   break;

             case 4:
                   z=deqR();
                    if(z!=-1)
                        printf("\n%d element deleted",z);
                   break;

             case 5:display();
                   break;

             case 6:exit(1);

             default:printf("\nplease enter right choice");

        }
    }
    return 0;
}
