#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left,*right;
    int data;
};

struct node* insert(struct node*,int);
struct node* search(struct node*,int);
void inOrder(struct node*);
void preOrder(struct node*);
void postOrder(struct node*);
int height(struct node*);

int main()
{
    struct node* root=NULL;
    struct node* ptr;
    int ch,key;
    while(1)
    {
        printf("\n1.insert 2.search 3.preOrder 4.inOrder 5.postOrder 6.height 7.exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1: printf("\nEnter the data: ");
            scanf("%d",&key);
            root=insert(root,key);
            break;
        case 2:printf("\nEnter the element to search: ");
            scanf("%d",&key);
            ptr=search(root,key);
            (ptr)?printf("%d is present",key):printf("%d is not present",key);
            break;
        case 3:preOrder(root);
             break;
        case 4:inOrder(root);
             break;
        case 5:postOrder(root);
             break;
        case 6:printf("\nHeight of tree is %d",height(root));
            break;
        case 7:exit(1);
        default:printf("\nEnter valid choice!!");

        }
    }

}
struct node* insert(struct node* ptr,int key)
{

    if(ptr==NULL)
    {
         ptr=(struct node*)malloc(sizeof(struct node));
        ptr->data=key;
        ptr->right=ptr->left=NULL;


    }
    else if(key<ptr->data)
        ptr->left=insert(ptr->left,key);
    else if(key>ptr->data)
        ptr->right=insert(ptr->right,key);
    else if(key==ptr->data)
        printf("\nDuplicate key");
    return ptr;

}
struct node* search(struct node* ptr,int key)
{
    if(ptr==NULL)
        return NULL;
    else if(key<ptr->data)
        return search(ptr->left,key);
     else if(key>ptr->data)
        return search(ptr->right,key);
    else
        return ptr;
}
void inOrder(struct node* root)
{
    if(root==NULL)
        return;


    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}
void preOrder(struct node* root)
{
    if(root==NULL)
        return;

     printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(struct node* root)
{
    if(root==NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
     printf("%d ",root->data);

}
int height(struct node* ptr)
{
    int l,r;
    if(ptr==NULL)
        return 0;
    l=height(ptr->left);
    r=height(ptr->right);
    return (l>r)? l+1:r+1;

}
