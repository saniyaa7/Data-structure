#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
typedef struct node* Node;
Node ins_beg(Node,int);
Node ins_end(Node,int);
Node ins_mid(Node,int,int);
void display(Node);
Node delete_beg(Node);
Node delete_end(Node);
Node delete_mid(Node,int);

int main()
{
    int x,ch,k;
    Node root=NULL;
    printf("\nImplementation of Linked List");
    printf("\n----------------------------------\n");

    while(1)
    {
        printf("\n1.ins_beg  2.ins_end  3.ins_mid  4.display  5.del_beg  6.del_end  7.del_mid  8.exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter the value:");
            scanf("%d",&x);
            root=ins_beg(root,x);
            break;

            case 2:printf("\nEnter the value:");
            scanf("%d",&x);
            root=ins_end(root,x);
            break;

            case 3:printf("\nEnter the value:");
            scanf("%d",&x);
            printf("\nEnter value after which you want to insert:");
            scanf("%d",&k);
            root=ins_mid(root,x,k);
            break;

            case 4:display(root);
            break;

            case 5:root=delete_beg(root);
            break;

            case 6:root=delete_end(root);
            break;

            case 7:printf("\nEnter elemnet to be delete:");
            scanf("%d",&x);
                root=delete_mid(root,x);
                break;

            case 8:exit(1);

            default:printf("\nEnter the valid choice!!");

        }

    }
}
Node ins_beg(Node root,int value)
{
    Node tmp=(Node)malloc(sizeof(struct node));
    tmp->data=value;
    tmp->next=root;
    root=tmp;
    return root;
}
Node ins_end(Node root,int value)
{
    Node tmp=(Node)malloc(sizeof(struct node));
    tmp->data=value;
    tmp->next=NULL;
    Node p=root;
    if(root==NULL)
    {
        root=tmp;
    }
    else
    {
        while((p->next)!=NULL)
            p=p->next;

        p->next=tmp;
    }
    return root;

}
Node ins_mid(Node root,int value,int prev)
{

    Node p=root;
    while(p!=NULL)
    {
        if(p->data==prev)
        {
            Node tmp=(Node)malloc(sizeof(struct node));
            tmp->data=value;
            tmp->next=p->next;
            p->next=tmp;
            return root;

        }
        p=p->next;
    }
    printf("\n%d does not exit",prev);
    return root;

}
void display(Node root)
{
    Node p=root;
    if(root==NULL)
    {
        printf("\nLinked List is Empty!!\n");
        return;
    }
    printf("\n");
    while(p!=NULL)
    {
        printf("%d-->",p->data);
        p=p->next;
   }
    printf("\n");


}

Node delete_beg(Node root)
{
    Node p=root;
     if(root==NULL)
    {
        printf("\nLinked list is empty!!");
        return NULL;
    }
    printf("\n%d element deleted",p->data);
    root=root->next;
    free(p);
    return root;
}

Node delete_end(Node root)
{
    Node p=root,q;
    if(root==NULL)
    {
        printf("\nLinked list is empty!!");
        return NULL;
    }
    if(root->next==NULL)
    {
      printf("\n%d element deleted",p->data);
     root=root->next;
     free(p);
     return root;
    }

            while(p->next!=NULL)
            {
                q=p;
                p=p->next;
            }

            printf("\n%d element deleted",p->data);
            free(p);
            q->next=NULL;
            return root;



}
Node delete_mid(Node root,int x)
{
    Node p=root,q;
    if(root==NULL)
    {
        printf("\nLinked list is empty!!");
        return NULL;
    }
    if(root->data==x)
    {
         printf("\n%d element deleted",p->data);
     root=root->next;
     free(p);
     return root;

    }
        while(p!=NULL)
        {
            if(p->data==x)
            {
                q->next=p->next;
                printf("\n%d element deleted",p->data);
                free(p);
                return root;
            }
            q=p;
            p=p->next;
        }
            printf("\n%d element not found",x);
            return root;
        }




