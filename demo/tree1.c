#include<stdio.h>
#include<stdlib.h>
 struct node
{
    struct node*left,*right;
    int data;
} ;
typedef struct node* node;
node insert(node,int);
void inOrder(node);
void preOrder(node);
void postOrder(node);
node search(node,int);
int main()
{
    node root=NULL;
    int ch,x;
    while(1)
    {
        printf("\n1.insert 2.inOrder 3.preOrder 4.postOrder 5search 6.exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter the data: ");
            scanf("%d",&x);
            root=insert(root,x);
            break;
            case 2:inOrder(root);
            break;
            case 3:preOrder(root);
            break;
            case 4:postOrder(root);
            break;
            case 5:printf("\nEnter the data to be searched: ");
            scanf("%d",&x);
            node ptr=search(root,x);
            (ptr)?printf("\n%d element is present!!"):printf("\n%d element is not present!!");
            break;
            case 6:exit(1);
            default:printf("\nEnter valid choice!!");
        }
    }

}
node insert(node ptr,int key)
{

    if(ptr==NULL)
    {
        node tmp=(node)malloc(sizeof(struct node));
        tmp->left=tmp->right=NULL;
        tmp->data=key;
        return tmp;
    }
    else if(ptr->data<key)
        ptr->right=insert(ptr->right,key);
    else if(ptr->data>key)
        ptr->left=insert(ptr->left,key);
    else
        printf("%d element is already present",key);
    return ptr;

}
void inOrder(node ptr)
{
    if(ptr==NULL)
        return;
    inOrder(ptr->left);
    printf("%d ",ptr->data);
    inOrder(ptr->right);
}
void preOrder(node ptr)
{
    if(ptr==NULL)
        return;

    printf("%d ",ptr->data);
    preOrder(ptr->left);
    preOrder(ptr->right);
}
void postOrder(node ptr)
{
    if(ptr==NULL)
        return;


    postOrder(ptr->left);
    postOrder(ptr->right);
    printf("%d ",ptr->data);
}
node search(node ptr,int key)
{
    if(ptr==NULL)
    {
      return NULL;
    }
    else if(ptr->data<key)
        ptr->right=search(ptr->right,key);
    else if(ptr->data>key)
        ptr->left=search(ptr->left,key);

    else
        return ptr;
}
