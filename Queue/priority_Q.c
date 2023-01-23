#include<stdio.h>
#include<stdlib.h>
struct node
{
    int p;
    int d;
    struct node *next;
};
struct node* enq(struct node*, int, int);
struct node* deq(struct node*);
void display(struct node*);
int main()
{
    struct node *head;
    head=NULL;
    int ch,item,pr;
    printf("\nImplementation of Priority Queue");
    printf("\n_____________________________________\n");
    while(1)
    {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter element to be added:");
                    scanf("%d",&item);
                    printf("\nEnter its priority:");
                    scanf("%d",&pr);
                    head=enq(head,pr,item);
                    break;
            case 2: head=deq(head);
                    break;
            case 3: display(head);
                    break;
            case 4: exit(1);
            default:printf("\nWrong choice!!!");
        }
    }
    return 0;
}
struct node* enq(struct node* h, int pr, int item)
{
    struct node *temp, *ptemp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->p=pr;
    temp->d=item;
    if(h==NULL || (pr<h->p))
    {
        temp->next=h;
        h=temp;
        return h;
    }
ptemp=h;
    while((ptemp->next!=NULL) && (ptemp->next)->p<=pr)
        ptemp=ptemp->next;
    temp->next=ptemp->next;
    ptemp->next=temp;
    return h;
}
struct node* deq(struct node* h)
{
    struct node *temp;
    temp=h;
    if(temp==NULL)
    {
        printf("\nQueue underflow");
        return h;
    }
    printf("\n%d with priority %d deleted",temp->d,temp->p);
    h=h->next;
    free(temp);
    return h;
}
void display(struct node *h)
{
    struct node *ptr;
    ptr=h;
    if(ptr==NULL)
    {
        printf("\nQueue is empty");
        return;
    }
    printf("\nElements in queue are:\n");
    printf("\nPriority  Data\n");
    while(ptr!=NULL)
    {
        printf("%d\t  %d\n",ptr->p,ptr->d);
        ptr=ptr->next;
    }
}
