#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node* ins_beg(struct node*, int);
struct node* ins_end(struct node*, int);
struct node* ins_mid(struct node*, int, int);
struct node* del_beg(struct node*);
struct node* del_end(struct node*);
struct node* del_mid(struct node*, int);
void display(struct node*);
void main()
{
    struct node *head=NULL;
    int ch,item,k;
    while(1)
    {
        printf("\n1.Ins_beg 2.Ins_end 3.Ins_mid 4.Del_beg 5.Del_end 6.Del_mid 7.Display 8.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter element:");
                    scanf("%d",&item);
                    head=ins_beg(head,item);
                    break;
            case 2: printf("\nEnter element:");
                    scanf("%d",&item);
                    head=ins_end(head,item);
                    break;
            case 3: printf("\nEnter element:");
                    scanf("%d",&item);
                    printf("\nEnter the data after which you want to insert:");
                    scanf("%d",&k);
                    head=ins_mid(head,item,k);
                    break;
            case 4: head=del_beg(head);
                    break;
            case 5: head=del_end(head);
                    break;
            case 6: printf("\nEnter element to be deleted:");
                    scanf("%d",&item);
                    head=del_mid(head,item);
                    break;
            case 7: display(head);
                    break;
            case 8: exit(1);
            default:printf("\nWrong choice!!!");
        }
    }
}
struct node* ins_beg(struct node *h, int x)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    if(h==NULL)
    {
        temp->next=temp;
        temp->prev=temp;
        h=temp;
        return h;
    }
    temp->next=h;
    temp->prev=h->prev;
    (temp->prev)->next=temp;
    h->prev=temp;
    h=temp;
    return h;
}
struct node* ins_end(struct node *h, int x)
{
    struct node *temp, *p;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    if(h==NULL)
    {
        temp->next=temp;
        temp->prev=temp;
        h=temp;
        return h;
    }
    p=h->prev;
    p->next=temp;
    temp->prev=p;
    temp->next=h;
    h->prev=temp;
    return h;
}
struct node* ins_mid(struct node *h, int x, int k)
{
    struct node *temp, *p;
    if(h==NULL)
    {
        printf("\nList is empty");
        return h;
    }
    if(h->data==k)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=x;
        temp->next=h->next;
        temp->prev=h;
        (h->next)->prev=temp;
        h->next=temp;
        return h;
    }
    p=h->next;
    while(p!=h)
    {
        if(p->data==k)
        {
            temp=(struct node*)malloc(sizeof(struct node));
            temp->data=x;
            temp->next=p->next;
            (p->next)->prev=temp;
            temp->prev=p;
            p->next=temp;
            return h;
        }
        p=p->next;
    }
    printf("\n%d not found",k);
    return h;
}
struct node* del_beg(struct node *h)
{
    struct node *temp;
    if(h==NULL)
    {
        printf("\nList is empty");
        return h;
    }
    if(h->next==h)
    {
        temp=h;
        h=NULL;
        printf("\n%d deleted",temp->data);
        free(temp);
        return h;
    }
    temp=h;
    h=h->next;
    h->prev=temp->prev;
    (temp->prev)->next=h;
    printf("\n%d deleted",temp->data);
    free(temp);
    return h;
}
struct node* del_end(struct node *h)
{
    struct node *temp, *p;
    if(h==NULL)
    {
        printf("\nList is empty");
        return h;
    }
    if(h->next==h)
    {
        temp=h;
        h=NULL;
        printf("\n%d deleted",temp->data);
        free(temp);
        return h;
    }
    temp=h->prev;
    p=temp->prev;
    p->next=h;
    h->prev=p;
    printf("\n%d deleted",temp->data);
    free(temp);
    return h;
}
struct node* del_mid(struct node *h, int x)
{
    struct node *temp, *p;
    if(h==NULL)
    {
        printf("\nList is empty");
        return h;
    }
    if(h->data==x)
    {
        temp=h;
        if(h->next==h)
            h=NULL;
        else
        {
            p=temp->prev;
            h=h->next;
            p->next=h;
            h->prev=p;
        }
        printf("\n%d deleted",x);
        return h;
    }
    temp=h->next;
    while(temp!=h)
    {
        if(temp->data==x)
        {
            p=temp->prev;
            p->next=temp->next;
            (temp->next)->prev=p;
            printf("\n%d deleted",x);
            free(temp);
            return h;
        }
        temp=temp->next;
    }
    printf("\n%d not found",x);
    return h;
}
void display(struct node *h)
{
    struct node *ptr;
    ptr=h;
    if(ptr==NULL)
    {
        printf("\nList is empty");
        return;
    }
    printf("\nElements in list are:\n");
    while(ptr->next!=h)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d ",ptr->data);
}
