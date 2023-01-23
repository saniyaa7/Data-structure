#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* enq(struct node*, int);
struct node* deq(struct node*);
void display(struct node*);
int main()
{
    int ch,item;
    struct node *front, *rear;
    front=rear=NULL;
    while(1)
    {
        printf("\n1.Enq 2.Deq 3.Display 4.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter data:");
                    scanf("%d",&item);
                    rear=enq(rear,item);
                    if(front==NULL)
                        front=rear;
                    break;
case 2: front=deq(front);
                    if(front==NULL)
                        rear=NULL;
                    break;
            case 3: display(front);
                    break;
            case 4: exit(1);
            default:printf("\nWrong choice!!!");
        }
    }
    return 0;
}
struct node* enq(struct node *r, int x)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(r!=NULL)
        r->next=temp;
    r=temp;
    return r;
}
struct node* deq(struct node *f)
{
    struct node *temp;
    if(f==NULL)
    {
        printf("\nQueue underflow");
        return f;
    }
    temp=f;
    f=f->next;
    printf("\nDequeued element is %d",temp->data);
    free(temp);
    return f;
}
void display(struct node *f)
{
    struct node *temp;
    temp=f;
    if(temp==NULL)
    {
        printf("\nQueue is empty");
        return;
    }
    printf("\nElements in queue are:\n");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
