#include<stdio.h>
#include<stdlib.h>
struct node
{
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
struct node* ins_beg(struct node* h, int x)
{
    struct node *temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    if(h==NULL)
    {
        h=temp;
        h->next=h;
        return h;
    }
    p=h;
    while((p->next)!=h)
    {
        p=p->next;
    }
    temp->next=h;
    h=temp;
    p->next=h;
    return h;
}
struct node* ins_end(struct node *h, int x)
{
    struct node *temp, *p;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    if(h==NULL)
    {
        h=temp;
        h->next=h;
        return h; }
p=h;
    while((p->next)!=h)
    {
        p=p->next;
    }
    p->next=temp;
    temp->next=h;
    return h;
}

struct node* ins_mid(struct node *h, int x, int k)
{
    struct node *temp, *p;
    p=h;
    if(p==NULL)
    {
        printf("\nList is empty");
        return h;
    }
    while((p->next)!=h)
    {
        if((p->data)==k)
        {
            temp=(struct node*)malloc(sizeof(struct node));
            temp->data=x;
temp->next=p->next;
            p->next=temp;
            return h;
        }
        p=p->next;
    }
    if((p->data)==k)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=x;
        temp->next=p->next;
        p->next=temp;
        return h;
    }
    else
    {
        printf("\n%d not found",k);
    }
    return h;
}
struct node* del_beg(struct node *h)
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
p=h;
    while((p->next)!=h)
        p=p->next;
    temp=h;
    h=h->next;
    p->next=h;
    printf("\n%d deleted",temp->data);
    free(temp);
    return h;
}
struct node* del_end(struct node *h)
{
    struct node *temp, *ptemp;
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
    ptemp=temp;
    temp=temp->next;
    while((temp->next)!=h)
    {
        ptemp=temp;
        temp=temp->next;
    }
    ptemp->next=temp->next;
    printf("\n%d deleted",temp->data);
    free(temp);
    return h;
}
struct node* del_mid(struct node *h, int x)
{
    struct node *temp, *ptemp;
    if(h==NULL)
    {
        printf("\nList is empty");
        return h;
    }
    if((h->next)==h)
    {
        if(h->data==x)
        {
            temp=h;
            h=NULL;
            printf("\n%d deleted",x);
            free(temp);
            return h;
        }
printf("\n%d not found",x);
        return h;
    }
    temp=h;
    if(x==h->data)
    {
        h=del_beg(h);
        return h;
    }
    while((temp->data)!=x && (temp->next)!=h)
    {
        ptemp=temp;
        temp=temp->next;
    }
if(temp->data==x)
    {
        ptemp->next=temp->next;
        printf("\n%d deleted",x);
        free(temp);
        return h;
    }
    printf("\n%d not found",x);
    return h;
}
void display(struct node *h)
{
    struct node *p;
    p=h;
    if(p==NULL)
    {
        printf("\nList is empty");
        return;
    }
    printf("\nElements in list are:\n");
    while((p->next)!=h)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("%d",p->data);
}

