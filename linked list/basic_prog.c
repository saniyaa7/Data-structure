#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node* root=NULL;
void print()
{
  struct node* p;
    p=root;
    printf("\nElements in linked list: ");
    while(p!=NULL)
    {
        printf("%d-->",p->data);
        p=p->link;
    }
}
void len()
{
    struct node* p=root;
    int count=0;
    while(p!=NULL)
    {
      p=p->link;
      count++;
    }
    printf("\nlength of linked list: %d",count);
}
int main()
{
    struct node* one;
    struct node* two;
    struct node* three;
    one=(struct node*)malloc(sizeof(struct node));
    two=(struct node*)malloc(sizeof(struct node));
    three=(struct node*)malloc(sizeof(struct node));
    one->data=1;
    two->data=2;
    three->data=3;
    one->link=two;
    two->link=three;
    three->link=NULL;
    root=one;
   print();
   len();
}
