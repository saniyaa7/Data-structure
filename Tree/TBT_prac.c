#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left,*right;
    int lthread,rthread;
};
struct node* insert(struct node*,int);
struct node* inOrdersucc(struct node* );
struct node* inOrderpred(struct node* );
void display(struct node*);
struct node* deleteNode(struct node*,int);
struct node* caseA(struct node*,struct node*,struct node*);
struct node* caseB(struct node*,struct node*,struct node*);
struct node* caseC(struct node*,struct node*,struct node*);
int main()
{
    int ch,x;
    struct node* root=NULL;
    printf("\nImplementation of TBT");
    printf("\n--------------------------------\n");
    while(1)
    {
        printf("\n1.insert 2.display 3.delete 4.exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter the data:");
                    scanf("%d",&x);
                    root=insert(root,x);
                    break;

            case 2:display(root);
                    break;

            case 3:printf("\nEnter the data:");
                    scanf("%d",&x);
                    deleteNode(root,x);
                    break;

            case 4:exit(1);
            default:printf("\nEnter the valid choice!!");
        }
    }
    return 0;
}

struct node* insert(struct node* root,int value)
{
    struct node* par=NULL;
    struct node* ptr=root;
    while(ptr!=NULL)
    {
        if(value==ptr->data)
            return root;
        par=ptr;
        if(value<ptr->data)
        {
            if(ptr->lthread==0)
                ptr=ptr->left;
            else
                break;
        }
        else
        {
            if(ptr->rthread==0)
                ptr=ptr->right;
            else
                break;
        }
    }

    struct node* tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=value;
    tmp->lthread=tmp->rthread=1;
    if(par==NULL)
    {
        root=tmp;
        tmp->left=tmp->right=NULL;
    }
    else if(value<par->data)
    {
        tmp->left=par->left;
        tmp->right=par;
        par->lthread=0;
        par->left=tmp;

    }
    else
    {
        tmp->right=par->right;
        tmp->left=par;
        par->rthread=0;
        par->right=tmp;
    }

    return root;
};

void display(struct node* root)
{
    if(root==NULL)
    {
        printf("\nTree is Empty");
    }

    struct node* ptr=root;
    while(ptr->lthread==0)
            ptr=ptr->left;

        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=inOrdersucc(ptr);
        }
}
struct node* inOrdersucc(struct node* ptr)
{
    if(ptr->rthread==1)
        return ptr->right;
    ptr=ptr->right;
    while(ptr->lthread==0)
        ptr=ptr->left;
    return ptr;
};
struct node* inOrderpred(struct node* ptr)
{
    if(ptr->lthread==1)
        return ptr->left;
    ptr=ptr->left;
    while(ptr->rthread==0)
        ptr=ptr->right;
    return ptr;
};
struct node* deleteNode(struct node* root,int value)
{
    struct node* ptr=root;
    struct node* par=NULL;
    int found=0;
    while(ptr!=NULL)
    {
        if(value==ptr->data)
        {
            found=1;
            break;
        }
        par=ptr;
        if(value<ptr->data)
        {
            if(ptr->lthread==0)
                ptr=ptr->left;
            else
                break;
        }
        else{
            if(ptr->rthread==0)
                ptr=ptr->right;
            else
                break;
        }

    }
    if(found==0)
    {
        printf("\nTree is Empty!!");
    }

   else  if(ptr->lthread==1&&ptr->rthread==1)
         root=caseA(root,par,ptr);

    else if(ptr->lthread==0||ptr->rthread==0)
        root=caseB(root,par,ptr);
    else
        root=caseC(root,par,ptr);
    return root;
};
struct node* caseA(struct node* root,struct node* par,struct node* ptr)
{
 if(par==NULL)
        root=NULL;
 else if(ptr==par->left)
 {
     par->lthread=1;
     par->left=ptr->left;
 }
 else{
    par->rthread=1;
    par->right=ptr->right;
 }
 free(ptr);
 return root;
}

struct node* caseB(struct node* root,struct node* par,struct node* ptr)
{
    struct node* child;
    if(ptr->lthread==0)
    {
        child=ptr->left;
    }
    else{
        child=ptr->right;
    }
    if(par==NULL)
    {
       root=child;
    }
    else if(ptr=par->left)
    {
        par->left=child;
    }
    else
    {
        par->right=child;
    }
    struct node* ipre=inOrderpred(ptr);
    struct node* isucc=inOrdersucc(ptr);
    if(ptr->lthread==0)
        ipre->right=isucc;
    else
        isucc->left=ipre;
    free(ptr);
    return root;


};
struct node* caseC(struct node* root,struct node* par,struct node* ptr)
{
    if(par==NULL)
    {
        printf("\nTree is Empty");
    }
    struct node* succ=ptr;
    struct node* parsucc=NULL;
    while(succ!=NULL)
    {

    if(succ->rthread==1)
        return succ->right;
    succ=succ->right;
    parsucc=succ;
    while(succ->lthread==0)
        succ=succ->left;

    }
    ptr->data=succ->data;
    if(succ->lthread==1&&succ->rthread)
    {
        root=caseA(root,parsucc,succ);
    }
    else{
        root=caseB(root,parsucc,succ);
    }
    return root;

};


