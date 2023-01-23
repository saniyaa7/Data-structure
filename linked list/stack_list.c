//implementation of stack using linked list
//using at add first and at delete first
/*
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node* head=NULL;

void push()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&temp->data);

    temp->link=head;
    head=temp;

}
int pop()
{
    struct node* p;
    int item;
    if(head==NULL)
    {
        printf("\nUnderflow stack");
        return -1;
    }
    else{
        p=head;
        item=p->data;

        head=head->link;
        free(p);
        return item;


    }
}
void display()
{
    struct node* p;
    if(head==NULL)
    {
        printf("\nstack is Empty");
        return;
    }
    else{

        p=head;
        printf("\n");
        while(p!=NULL)
        {
            printf("<-%d",p->data);
            p=p->link;
        }


    }
}


int main()
{
    int ch,x;
    while(1)
    {
        printf("\n1.push 2.pop 3.display 4.exit");
        printf("\nEnter your choice(1-4):");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
                   break;
            case 2:x=pop();
                   if(x!=-1)
                   {
                       printf("\n%d element deleted",x);
                   }
                   break;

            case 3:display();
                   break;

            case 4:exit(1);
            default:printf("\nplz enter the valid choice!!");
        }
    }
}
*/
//using add at last and delete at last


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

void push()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the node data: ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        struct node* p;
        p=head;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }

}
int pop()
{
    struct node* p;
    int item;
    if(head==NULL)
    {
        printf("\nUnderflow stack");
        return -1;
    }
    else{
        p=head;
        struct node* q;
        int i=1;
        if(length()==1)
        {
             head=p->link;
            p->link=NULL;
            item=p->data;

        }
        else{
        while(i<length()-1)
        {
            p=p->link;
            i++;
        }
        q=p->link;
        p->link=NULL;
        item=q->data;}
        return item;

    }
}
void display()
{
    struct node* p;
    if(head==NULL)
    {
        printf("\nstack is Empty");
        return;
    }
    else{

        p=head;
        printf("\n");
        while(p!=NULL)
        {
            printf("%d->",p->data);
            p=p->link;
        }


    }
}


int main()
{
    int ch,x;
    while(1)
    {
        printf("\n1.push 2.pop 3.display 4.exit");
        printf("\nEnter your choice(1-4):");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
                   break;
            case 2:x=pop();
                   if(x!=-1)
                   {
                       printf("\n%d element deleted",x);
                   }
                   break;

            case 3:display();
                   break;

            case 4:exit(1);
            default:printf("\nplz enter the valid choice!!");
        }
    }
}
