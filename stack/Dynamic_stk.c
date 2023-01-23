#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* push(struct node*,int);
struct node* pop(struct node*);
void display(struct node*);
int main()
{
    int ch,x;
   struct node* top=NULL;
    while(1)
    {
        printf("\n1.push 2.pop 3.display 4.exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter the data to be pushed: ");
            scanf("%d",&x);
            top=push(top,x);
            break;

            case 2:top=pop(top);
            break;

            case 3:display(top);
            break;

            case 4:exit(1);

            default:printf("\nEnter the valid choice!!");


        }
    }
    return 0;
}
struct node* push(struct node *top, int x)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=top;
    top=temp;
    return top;
}
struct node* pop(struct node *top)
{
    struct node *temp;
    if(top==NULL)
    {
        printf("\nStack underflow");
        return top;
    }
    temp=top;
    top=top->next;
    printf("\nPopped element is %d",temp->data);
    free(temp);
    return top;
}
void display(struct node *top)
{
    struct node *temp;
    temp=top;
    if(temp==NULL)
    {
        printf("\nStack is empty");
        return;
    }
    printf("\nElements in stack are:\n");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
