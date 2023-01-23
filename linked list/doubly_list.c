#include <stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev, *next;
    int data;
};
struct node* ins_beg(struct node*, int);
struct node* ins_end(struct node*, int);
struct node* ins_mid(struct node*, int, int);
struct node* del_beg(struct node*);
struct node* del_end(struct node*);
struct node* del_mid(struct node*, int);
void display(struct node*);
int main()
{
    struct node *head=NULL;
    int ch, k, item;
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
                    printf("\nEnter data after which you want to add:");
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
    return 0;
}
struct node* ins_beg(struct node *h, int x)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->prev=NULL;
    if(h!=NULL)
        h->prev=temp;
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
    if(h==NULL)
    {
        temp->prev=NULL;
        h=temp;
        return h;
    }
    p=h;
    while((p->next)!=NULL)
        p=p->next;
    p->next=temp;
    temp->prev=p;
    return h;
}
struct node* ins_mid(struct node *h, int x, int k)
{
    struct node *temp,*p;
    if(h==NULL)
    {
        printf("\nList is empty");
        return h;
    }
    p=h;
    while(p!=NULL)
    {
        if(p->data==k)
        {
            temp=(struct node*)malloc(sizeof(struct node));
            temp->data=x;
            temp->next=p->next;
            if((p->next)!=NULL)
                (p->next)->prev=temp;
            p->next=temp;
            temp->prev=p;
            return h;
        }
        p=p->next;
    }
    printf("\n%d not present",k);
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
    temp=h;
    h=h->next;
    printf("\n%d deleted",temp->data);
    if(h!=NULL)
        h->prev=NULL;
    free(temp);
    return h;
}
struct node* del_end(struct node *h)
{
    struct node *temp,*p;
    if(h==NULL)
    {
        printf("\nList is empty");
        return h;
    }
    if(h->next==NULL)
    {
        temp=h;
        h=h->next;
        printf("\n%d deleted",temp->data);
        free(temp);
        return h;
    }

    temp=h;
    while((temp->next)!=NULL)
        temp=temp->next;
    p=temp->prev;
    p->next=NULL;   // (temp->prev)->next=NULL
    printf("\n%d deleted",temp->data);
    free(temp);
    return h;
}
struct node* del_mid(struct node *h, int x)
{
    struct node *temp,*p;
    temp=h;
    if(temp==NULL)
    {
        printf("\nList is empty");
        return h;
    }
    if(h->data==x)
    {
        h=h->next;
        if(h!=NULL)
          h->prev=NULL;

        printf("\n%d deleted",temp->data);
        free(temp);
        return h;
    }
    temp=temp->next;
    while(temp!=NULL)
    {
      if(temp->data==x)
      {
        (temp->prev)->next=temp->next;
        if(( temp->next)!=NULL)
          (temp->next)->prev=temp->prev;
        printf("\n%d deleted",temp->data);
        free(temp);
        return h;
      }
      temp=temp->next;
    }
    printf("\n%d not present",x);
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
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
