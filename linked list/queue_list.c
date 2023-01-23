//impelemntaion of queue using linked list
//add at last & delete at first


/*#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node* head=NULL;
void enq()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data:");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else{
        struct node* p;
        p=head;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;


    }
}
int deq()
{
    int item;
    struct node* p;
    p=head;
    if(head==NULL)
    {
        printf("\nQueue Underflow");
        return -1;
    }
    item=p->data;

    head=head->link;
    free(p);
    return item;
}
void display()
{

    if(head==NULL)
    {
        printf("\nQueue is Empty!!");
        return;
    }
    else{
    struct node* p;
    p=head;
    printf("\n");
    while(p!=NULL)
    {
        printf("%d->",p->data);
        p=p->link;
    }
    printf("\n");
    }
}
int main()
{
    int ch,x;
    while(1)
    {
        printf("\n1. Enqueue 2. Dequeue 3.Display 4.Exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:enq();
                   break;

            case 2:x=deq();
                   if(x!=-1)
                    printf("\n%d Element deleted",x);
                   break;

            case 3:display();
                   break;

            case 4:exit(1);
            default:printf("\nEnter the valid choice!!");
        }
    }
}
*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node* head=NULL;

int length()
{
    int count=0;
    struct node* temp;
    temp=head;
    while(temp!=NULL)
    {
        count+=1;
        temp=temp->link;
    }
    return count;
}
void enq()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data:");
    scanf("%d",&temp->data);
   temp->link=head;
   head=temp;

    }

int deq()
{
    int item;
    struct node* p;
    if(head==NULL)
    {
        printf("\nQueue underflow");
        return -1;
    }


    p=head;
    if(length()==1)
    {

        item=p->data;
        head=head->link;


    }
    else{
    struct node* q;
    int i=1;
    while(i<length()-1)
    {
        p=p->link;
        i++;
    }
    q=p->link;
    item=q->data;
    p->link=NULL;}

    return item;





    }

void display()
{

    if(head==NULL)
    {
        printf("\nQueue is Empty!!");
        return;
    }
    else{
    struct node* p;
    p=head;
    printf("\n");
    while(p!=NULL)
    {
        printf("<-%d",p->data);
        p=p->link;
    }
    printf("\n");
    }
}
int main()
{
    int ch,x;
    while(1)
    {
        printf("\n1. Enqueue 2. Dequeue 3.Display 4.Exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:enq();
                   break;

            case 2:x=deq();
                   if(x!=-1)
                    printf("\n%d Element deleted",x);
                   break;

            case 3:display();
                   break;

            case 4:exit(1);
            default:printf("\nEnter the valid choice!!");
        }
    }
}
