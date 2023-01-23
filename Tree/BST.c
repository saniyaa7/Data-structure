/*#include<stdio.h>
#include<stdlib.h>
int count=-1;

struct BST
{
    int data;
    struct BST* left,*right;
};
struct BST *creat(int key)
{
    struct BST* temp=(struct BST*)malloc(sizeof(struct BST));
    temp->data=key;
    temp->right=temp->left=NULL;
    return temp;

}
struct BST *insert(struct BST* root,int key)
{
    if(root==NULL)
    {
        return creat(key);
    }
    if(key<root->data)
        root->left=insert(root->left,key);

     if(key>root->data)
        root->right=insert(root->right,key);

    return root;

}
struct BST* searchkey(struct BST* current,int key,struct BST* parent)
{
    while(current!=NULL&&current->data!=key)
    {
        parent=current;
        if(key<current->data)
            current=current->left;
        else
            current=current->right;
    }
    return parent;

}
struct BST* minValue(struct BST* p)
{
    struct BST* current=p;
    while(current->left!=NULL)
    {
        current=current->left;
    }
    return current;

};
struct BST* delete(struct BST *root, int x)
{
    //searching for the item to be deleted
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right = delete(root->right, x);
    else if(x<root->data)
        root->left= delete(root->left, x);
    else
    {
        //No Children
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left==NULL || root->right==NULL)
        {
            struct BST *temp;
            if(root->left==NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }

        //Two Children
        else
        {
            struct BST *temp = minValue(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}
void inorder(struct BST* root)
{


       if(root!=NULL)
       {
         inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);

       }

}
void preorder(struct BST* root)
{


       if(root!=NULL)
       {
           printf("%d ",root->data);
         preorder(root->left);

        preorder(root->right);


       }

}
void postorder(struct BST* root)
{


       if(root!=NULL)
       {


        postorder(root->left);
         postorder(root->right);
        printf("%d ",root->data);


       }

}

int level(struct BST* root,int key)
{
 count++;

    if(root==NULL||root->data==key)
    {
        if(root==NULL)
        {
            printf("%d element is not present in Tree!!",key);
            return 0;
        }

      int x=count;
    count=-1;

        return x;

    }


    if(root->data>key)

       return level(root->left,key);

    if(root->data<key)


            return level(root->right,key);


}
int main()
{
    int ch,x,value;

    struct BST* root = NULL;
    while(1)
    {
        printf("\n1.insert 2.inorder 3.preorder 4.postorder 5.search  6.delete 7.exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter the data: ");
                    scanf("%d",&x);
                    root=insert(root,x);
                    break;
            case 2:inorder(root);
                break;

            case 3:preorder(root);
                    break;
            case 4:postorder(root);
                    break;
            case 5:printf("\nEnter element to be searched: ");
                    scanf("%d",&value);
                x=level(root,value);
                printf("%d element at level: %d",value,x);
            break;
            case 6:printf("\nEnter element to be deleted: ");
                    scanf("%d",&value);
               delete(root,value);

                    break;
            case 7:exit(1);
            default:printf("\nEnter valid choice!!");
        }
    }


    return 0;
}*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;

};
struct node* root=NULL;
struct node* creatnode(int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
struct node* insert(struct node* p,int data)
{

    if(p==NULL)
    {
        return creatnode(data);


    }
     if(data<p->data)
        p->left=insert(p->left,data);

     if(data>p->data)
        p->right=insert(p->right,data);
        return p;


}
void inorder(struct node* p)
{


       if(p!=NULL)
       {
         inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);

       }

}
int main()
{
    int ch,x;
    printf("\nImplementation of Binary search Tree\n");
    printf("\n_______________________________________\n");
    while(1)
    {
        printf("\n1.insert 2.display\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter the data:");
                    scanf("%d",&x);
                    root=insert(root,x);
                    break;
            case 2:inorder(root);
                    break;
            case 3:exit(1);
        }

    }
}






















