#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left,*right;
    int data;
};
typedef struct node* Node;
Node insert(Node,int);
Node search(Node,int);
void inOrder(Node);
void preOrder(Node);
void postOrder(Node);
int height(Node);
Node del(Node,int);
int main()
{
    Node root=NULL;
    Node ptr;
    int ch,key;
    while(1)
    {
        printf("\n1.insert 2.search 3.preOrder 4.inOrder 5.postOrder 6.height 7.delete 8.exit");
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
        case 7:printf("\nEnter the element to deleted: ");
        scanf("%d",&key);
        root=del(root,key);
        break;
        case 8:exit(1);
        default:printf("\nEnter valid choice!!");

        }
    }

}
Node insert(Node ptr,int key)
{

    if(ptr==NULL)
    {
         ptr=(Node)malloc(sizeof(struct node));
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
Node search(Node ptr,int key)
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
void inOrder(Node root)
{
    if(root==NULL)
        return;


    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}
void preOrder(Node root)
{
    if(root==NULL)
        return;

     printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node root)
{
    if(root==NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
     printf("%d ",root->data);

}
int height(Node ptr)
{
    int l,r;
    if(ptr==NULL)
        return 0;
    l=height(ptr->left);
    r=height(ptr->right);
    return (l>r)? l+1:r+1;

}
Node del(Node ptr,int key)
{

    Node tmp,succ;
    if(ptr==NULL)
    {

        printf("\n%d not found",key);
        return ptr;
    }
    if(key<ptr->data)
        ptr->left=del(ptr->left,key);
    else if(key>ptr->data)
        ptr->right=del(ptr->right,key);
    else{
        if(ptr->left!=NULL&&ptr->right!=NULL)
        {

            succ=ptr->right;
            while(succ->left)
                succ=succ->left;
            ptr->data=succ->data;
            ptr->right=del(ptr->right,succ->data);
        }
        else
        {

            tmp=ptr;
            if(ptr->left!=NULL)
                ptr=ptr->left;
            else if(ptr->right!=NULL)
                ptr=ptr->right;
            else
                ptr=NULL;
            free(tmp);
        }
    }
    return ptr;

}
