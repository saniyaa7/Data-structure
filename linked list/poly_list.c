#include<stdio.h>
#include<stdlib.h>
struct node
{
    int c;
    int e;
    struct node* next;
};
typedef struct node* node;
node creat(node);
node insert_s(node,int,int);
void add(node,node);
void display(node);
node insert(node,int,int);
int main()
{
    struct node* h1=NULL,*h2=NULL;
    printf("\nEnter the polynomial 1: ");
    h1=creat(h1);
    printf("\nEnter the polynomial 2: ");
    h2=creat(h2);
    printf("\npolynomial 1: ");
    display(h1);
    printf("\npolynomial 2: ");
   display(h2);
   add(h1,h2);

    return 0;
}
node creat(node h)
{
    int i,n,co,ex;
    printf("\nEnter no of terms: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\nEnter the coefficient for %d:",i);
        scanf("%d",&co);
         printf("\nEnter the exponent for %d:",i);
        scanf("%d",&ex);
        h=insert_s(h,co,ex);
    }
    return h;
}
node insert_s(node h,int co,int ex)
{
    node tmp=(node)malloc(sizeof(struct node)),ptr;
    tmp->c=co;
    tmp->e=ex;
    if(h==NULL||ex>h->e)
    {
        tmp->next=h;
        h=tmp;
        return h;
    }
    ptr=h;
    while(ptr->next!=NULL&&(ptr->next)->e>=ex)
        ptr=ptr->next;
    tmp->next=ptr->next;
    ptr->next=tmp;
    return h;
}
void add(node p1,node p2)
{
    node h3=NULL;
    while(p1!=NULL&&p2!=NULL)
    {
      if(p1->e>p2->e)
    {
        h3=insert(h3,p1->c,p1->e);
        p1=p1->next;
    }
    else if(p2->e>p1->e)
    {
        h3=insert(h3,p2->c,p2->e);
        p2=p2->next;
    }
    else
    {
        h3=insert(h3,p1->c+p2->c,p1->e);
        p1=p1->next;
        p2=p2->next;
    }
    }
    while(p1!=NULL)
    {
        h3=insert(h3,p1->c,p1->e);
        p1=p1->next;
    }
     while(p2!=NULL)
    {
        h3=insert(h3,p2->c,p2->e);
        p2=p2->next;
    }
    printf("\nAdded Polynomial is:\n");
    display(h3);

}
void display(node ptr)
{
    if(ptr==NULL)
    {
        printf("\nZero Polynomial");
        return;
    }
    while(ptr!=NULL)
    {
        printf("%dx^%d",ptr->c,ptr->e);
        ptr=ptr->next;
        if(ptr!=NULL)
            printf("+");
        else
            printf("\n");

    }
}
node insert(node h,int co,int ex)
{
    node tmp=(node)malloc(sizeof(struct node)),ptr;
    tmp->c=co;
    tmp->e=ex;
    if(h==NULL)
    {
        tmp->next=h;
        h=tmp;
        return h;
    }
    ptr=h;
    while((ptr->next)!=NULL)
        ptr=ptr->next;
    tmp->next=NULL;
    ptr->next=tmp;
    return h;
}
