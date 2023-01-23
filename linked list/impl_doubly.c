#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
     struct node* prev;
     struct node* next;
};
struct node* head;
struct node* last;
int sh;

int length()
{
    struct node* p=head;
    int count=0;
    while(p!=NULL)
    {
      p=p->next;
      count++;
    }
    return count;
}
int acesselement()
{
    int loc,i=1;
    printf("\nEnter the location: ");
    scanf("%d",&loc);
    struct node* p=head;
    if(loc>length())
    {
        printf("\nEnter rigth location!!");
    }
    else
    {
         while(i<loc)
    {
        p=p->next;
    }
    printf("at location %d fount element %d",loc,p->data);

    }


}
void insertatlast()
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));

    printf("\nEnter the data: ");
    scanf("%d",&temp->data);
    last=temp;
    temp->next=NULL;
        temp->prev=NULL;

    if(head==NULL)
    {
        head=temp;


    }
    else
    {
        struct node* p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
        temp->prev=p;

    }

}
void insertatfirst()
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d",&temp->data);
    temp->next=head;
    temp->prev=NULL;
    head->prev=temp;
    head=temp;

}
void insertatrandom()
{
    int loc,i=1;
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the location: ");
    scanf("%d",&loc);
    if(loc>length())
    {
        printf("\nplzz Enter right location!!");

    }
    else if(loc==1)
    {
        insertatfirst();
    }
    else if(loc==length())
    {
        insertatlast();
    }
    else{
         printf("\nEnter the data: ");
    scanf("%d",&temp->data);
    struct node* p=head;

    while(i<loc-1)
    {
        p=p->next;
        i++;
    }
      temp->next=p->next;
      p->next->prev=temp;
    p->next=temp;
    temp->prev=p;

    }


}
void delete()
{
    int loc,i=1;
    struct node* p=head;
    printf("\nEnter location of element: ");
    scanf("%d",&loc);
    if(loc>length())
    {
        printf("\nEnter valid location!!");
    }
    else if(loc==1)
    {
    head->next->prev=NULL;
        head=head->next;

    }
    else if(loc==length())
    {
      struct node* p=head;


        int i=1;
        while(i<loc-1)
        {
            p=p->next;
            i++;
        }
        p->next=NULL;
        last=p;


    }
    else{
        while(i<loc-1)
        {
            p=p->next;
            i++;
        }
        p->next->next->prev=p;
        p->next=p->next->next;



    }
}
/*void delete()
{
    int loc;
    struct node* temp;


    printf("\nEnter the location: ");
    scanf("%d",&loc);
    if(loc>length())
    {
        printf("\nInvalid location!!");
    }
    else if(loc==1)
    {
      temp=head;
      head=temp->next;
      temp->next->prev=NULL;


    }
    else if(loc==length())
    {
      struct node* p=head,*q;


        int i=1;
        while(i<loc-1)
        {
            p=p->next;
            i++;
        }
        q=p->next;
        p->next=NULL;
        last=p;


    }
    else{
            struct node* p=head,*q;


        int i=1;
        while(i<loc-1)
        {
            p=p->next;
            i++;
        }
        q=p->next;
        p->next=q->next;
        q->next->prev=p;


    }
}*/

int search()
{

    printf("\nEnter element to be search: ");
    scanf("%d",&sh);
    struct node* p=head;
    int count=1;
    while(p!=NULL)
    {
        if(sh==p->data)
        {
            return count;
            break;
        }
        p=p->next;
        count++;

    }
    return -1;
}
void Fdisplay()
{
   struct node* p=head;
   printf("\n\nElement in forward direction: ");
    while(p!=NULL)
    {
        printf("%d-->",p->data);
        p=p->next;

    }
    printf("\n");
}
void Bdisplay()
{
     printf("\n\nElement in reversed direction: ");
struct node* q=last;
    while(q!=NULL)
    {
        printf("<--%d",q->data);
        q=q->prev;

    }
    printf("\n");
}
int main()
{
    int ch,x;
    while(1)
    {
        printf("\n1.insert at last 2. insert at first  3.insert at random 4.length  5.Delete 6.display forward 7.display backward 8.search 9.acsses element 10.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insertatlast();
                    break;
            case 2: insertatfirst();
                    break;
            case 3:insertatrandom();
                    break;
            case 4:x=length();
                    printf("length=%d",x);
                    break;
            case 5:delete();
                    break;
            case 6:Fdisplay();
                    break;
            case 7:Bdisplay();
                    break;
            case 8:x=search();
                    (x!=-1)? printf("\n%d element fount at location %d",sh,x):printf("\n%d Element is not found!!",sh);

                    break;
            case 9:acesselement();

            case 10:exit(1);
            default: printf("\n\nPLZZ ENTER VALID CHOICE!!");

        }
    }
}
