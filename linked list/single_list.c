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
struct node* del_mid(struct node*,int);
void display(struct node*);
void main()
{
    struct node *head=NULL;
    int ch,item,k;
    while(1)
    {
        printf("\n1.Ins_beg 2.Ins_end 3.Ins_mid  4.del_beg 5.del_end 6.del_mid 7.Display 8.Exit\nEnter your choice:");
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
                    printf("\nEnter element after which you want to insert:");
                    scanf("%d",&k);
                    head=ins_mid(head,item,k);
                    break;

            case 4:head=del_beg(head);
                    break;
             case 5:head=del_end(head);
                    break;
             case 6:printf("\nEnter elemnt to deleted: ");
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
    temp->next=h;
    h=temp;
    return h;
}
struct node* ins_end(struct node *h, int x)
{
    struct node *temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    p=h;
    if(p==NULL)
    {
        h=temp;
    }
    else
    {
        while((p->next)!=NULL)
            p=p->next;
        p->next=temp;
    }
    return h;
}
struct node* ins_mid(struct node *h, int x, int k)
{
    struct node *temp,*p;
    p=h;
    while(p!=NULL)
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
    printf("\n%d does not exist",k);
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
    if((h->next)==NULL)
    {
        temp=h;
        printf("\n%d deleted",temp->data);
        h=h->next;
        free(temp);
        return h;
    }
temp=h;
    while((temp->next)!=NULL)
    {
        ptemp=temp;
        temp=temp->next;
    }
    printf("\n%d deleted",temp->data);
    ptemp->next=NULL;
    free(temp);
    return h;
}
struct node* del_beg(struct node* h)
{
  struct node *temp=h;
    if(h==NULL)
    {
        printf("\nList is empty");
        return h;
    }
    printf("%d element deleted",temp->data);
    h=h->next;
    free(temp);
    return h;
};
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
        h=h->next;
        printf("\n%d deleted",temp->data);
        free(temp);
        return h;
    }
p=h;
    while((p->next)!=NULL)
    {
        if((p->next)->data==x)
        {
            temp=p->next;
            p->next=temp->next;
            printf("\n%d deleted",temp->data);
            free(temp);
            return h;
        }
        p=p->next;
    }
    printf("\n%d not found",x);
    return h;
}
void display(struct node *h)
{
    struct node *temp;
    if(h==NULL)
    {
        printf("\nList is empty");
        return;
    }
    temp=h;
    printf("\nElements in list are:\n");
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
}
