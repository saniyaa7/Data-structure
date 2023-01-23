#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left,*right;
    int height;
};
typedef struct node* Node;
int max(int,int);
int getHeight(Node);
Node creatNode(int);
Node insert(Node,int);
void inOrder(Node);
Node leftRotate(Node);
Node rightRotate(Node);
int getBalance(Node);
Node deleteNode(Node,int);
Node Predecessor(Node);
Node inOrdersucc(Node root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
};
int main()
{
    int ch,x;
    Node root=NULL;
    printf("\nImplementation of AVL");
    printf("\n_____________________________\n");
    while(1)
    {
        printf("\n1.insert 2.display 3.delete 4.exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter the data: ");
                 scanf("%d",&x);
                 root=insert(root,x);
                 break;

            case 2:inOrder(root);
                    break;

            case 3:printf("\nEnter the data to deleted: ");
                 scanf("%d",&x);
                 root=deleteNode(root,x);
                 (root==NULL)?printf("\nTree is Empty!!"):printf("\n%d element deleted",x);
                 break;
            case 4:exit(1);
            default:printf("\nEnter valid choice!!");
        }
    }
    return 0;
}
int max(int a,int b)
{
    return (a>b)?a:b;
}
int getHeight(Node root)
{
    if(root==NULL)
        return 0;
    return root->height;
}
Node creatNode(int x)
{
    Node tmp=(Node)malloc(sizeof(struct node));
    tmp->data=x;
    tmp->left=tmp->right=NULL;
    tmp->height=1;
    return tmp;
}
Node insert(Node root,int x)
{
    if(root==NULL)
        return creatNode(x);
    if(x>root->data)
        root->right=insert(root->right,x);
    if(x<root->data)
        root->left=insert(root->left,x);
    return root;
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    int bf=getBalance(root);
    if(bf>1 && x<(root->left)->data)
        return rightRotate(root);

    if(bf<-1 && x>(root->left)->data)
        return leftRotate(root);

    if(bf>1 && x>(root->left)->data)
    {

        root->left=leftRotate(root);
        return rightRotate(root);
    }

    if(bf<-1 && x<(root->left)->data)
    {
      root->right=rightRotate(root);
        return leftRotate(root);
    }

    return root;

}
void inOrder(Node root)
{

    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
Node leftRotate(Node x)
{
  Node y=x->right;
  Node T2=y->left;

  y->left=x;
  x->right=T2;

  x->height=max(getHeight(x->left),getHeight(x->right))+1;
  y->height=max(getHeight(y->left),getHeight(y->right))+1;

  return y;
}
Node rightRotate(Node y)
{
    Node x=y->left;
    Node T2=x->right;

    y=x->right;
    y->left=T2;

    x->height=max(getHeight(x->left),getHeight(x->right))+1;
  y->height=max(getHeight(y->left),getHeight(y->right))+1;


  return x;


}
int getBalance(Node root)
{
    if(root==NULL)
        return 0;
    return getHeight(root->left)-getHeight(root->right);
}
Node Predecessor(Node root)
{
    if(root==NULL)
        return NULL;
    while(root->right!=NULL)
        root=root->right;
    return root;
}

Node deleteNode(Node root,int value)
{
    Node isucc;
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left==NULL&&root->right==NULL)
    {


        return NULL;
    }
    if(value<root->data)
        root->left=deleteNode(root->left,value);
    else if(value>root->data)
        root->right=deleteNode(root->right,value);
    else{
            isucc=inOrdersucc(root->right);
            root->data=isucc->data;
            root->right=deleteNode(root->right,isucc->data);
    }

    int height=1+max(getHeight(root->left),getHeight(root->right));
    int bf=getBalance(root);
    if(bf>1&&getBalance(root->left)>=0)
        return rightRotate(root);
    if(bf>1&&getBalance(root->left)==-1)
    {
         root->left=leftRotate(root);
    return rightRotate(root);
    }

    if(bf<-1&&getBalance(root->right)<=0)
     return leftRotate(root);

    if(bf<-1&&getBalance(root->right)==1)
    { root->right=rightRotate(root);
    return leftRotate(root);

    }
    return root;



}
