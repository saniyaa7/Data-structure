#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left,*right;
    int lthread,rthread;
};
struct node* insert(struct node*,int);
void display(struct node*);
struct node* sucessor(struct node*);
struct node* delete(struct node*,int data);
struct node* caseA(struct node*,struct node*,struct node*);
struct node* caseB(struct node*,struct node*,struct node*);
struct node* caseC(struct node*,struct node*,struct node*);
struct node* inSuccessor(struct node*);
struct node* inPredecessor(struct node*);
int main()
{
    struct node* root=NULL;
    printf("\nImplementation of Threaded Binary Tree");
    printf("\nvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n");
    int ch,x;
    while(1)
    {
        printf("\n1.insert 2.display 3.delete 4.exit\nEnter tour choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter the data: ");
                    scanf("%d",&x);
                    root=insert(root,x);
                    break;
            case 2:
                display(root);
            break;
            case 3:printf("\nEnter the data: ");
                    scanf("%d",&x);
                delete(root,x);
                break;
            case 4:exit(1);
            default:printf("\nEnter a valid choice!!");
        }
    }
    return 0;
}

struct node* insert(struct node* root,int data)
{
    struct node* ptr=root;
    struct node* par=NULL;
    while(ptr!=NULL)
    {
        if(data==ptr->data)
        {
            return root;
        }
        par=ptr;
        if(data<ptr->data)
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
    struct node* tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=data;

    tmp->lthread=tmp->rthread=1;
    if(ptr==NULL)
    {
        root=tmp;
        tmp->left=tmp->right=NULL;
    }
    else if(ptr->data>data)
    {
        tmp->left=par->left;
        tmp->right=par;
        par->left=tmp;
        par->lthread=0;
    }
    else{
        tmp->left=par;
        tmp->right=par->right;
        par->right=tmp;
        par->rthread=0;

    }
    return root;

}
void display(struct node* root)
{
    if(root==NULL)
    {
        printf("\nTree is Empty!!");
    }
    struct node* ptr=root;
    while(ptr->lthread==0)
        ptr=ptr->left;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=sucessor(ptr);
    }
}
struct node* sucessor(struct node* ptr)
{
    if(ptr->rthread==1)
    {
        return ptr->right;
    }
    ptr=ptr->right;
    while(ptr->lthread==0)
        ptr=ptr->left;
    return ptr;
};
struct node* delete(struct node* root,int data)
{
    struct node* ptr=root;
    struct node* par=NULL;
    int found=0;
    while(ptr!=NULL)
    {
        if(data==ptr->data)
            {
                found=1;
                break;
            }

        par=ptr;
        if(data<ptr->data)
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
        printf("%d element is not present in tree",data);
    else if(ptr->lthread==1&&ptr->rthread==1)
    {
        root=caseA(root,par,ptr);

    }
    else if(ptr->lthread==0||ptr->rthread==0)
    {
        root=caseB(root,par,ptr);
    }
    else{
        root=caseC(root,par,ptr);
    }
    return root;
}
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
        child=ptr->left;
    else
        child=ptr->right;
    if(par==NULL)
        root=NULL;
    else if(ptr==par->left)
        par->left=child;
    else
        par->right=child;
    struct node* s=inSuccessor(ptr);
    struct node* p=inPredecessor(ptr);
    if(ptr->lthread==0)
        p->right=s;
    else
        s->left=p;
    free(ptr);
    return root;


};
struct node* caseC(struct node* root,struct node* par,struct node* ptr)
{
    struct node* parsucc=ptr;
    struct node* succ=ptr->right;
    while(succ->lthread==0)
    {
        parsucc=succ;
        succ=succ->left;
    }
    ptr->data=succ->data;
    if(succ->lthread==1&&succ->rthread==1)
        root=caseA(root,parsucc,succ);
    else
        root=caseB(root,parsucc,succ);
    return root;

};
struct node* inSuccessor(struct node* ptr)
{
    if(ptr->rthread==1)
    {
        return ptr->right;
    }
    ptr=ptr->right;
    while(ptr->lthread==0)
        ptr=ptr->left;
    return ptr;
};
struct node* inPredecessor(struct node* ptr)
{
    if(ptr->lthread==1)
        return ptr->left;
    ptr=ptr->left;
    while(ptr->rthread==0)
        ptr=ptr->right;
    return ptr;
};






























/*#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left,*right;
    int lthread,rthread;
};
struct node* insert(struct node* root,int data)
{
    struct node* ptr,*par=NULL;
    ptr=root;
    while(ptr!=NULL)
    {
        if(data==ptr->data)
        {
            return root;
        }
        par=ptr;
        if(data<ptr->data)
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
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->lthread=1;
    temp->rthread=1;
    if(par==NULL)
    {
        root=temp;
        temp->left=NULL;
        temp->right=NULL;
    }
    else if(data<(par->data))
    {
        temp->left=par->left;
        temp->right=par;
        par->lthread=0;
        par->left=temp;
    }
    else
    {
        temp->left=par;
        temp->right=par->right;
        par->rthread=0;
        par->right=temp;
    }
    return root;

};
struct node* inordersuccesor(struct node* ptr)
{
    if(ptr->rthread==1)
    {
        return ptr->right;

    }
    ptr=ptr->right;
    while(ptr->lthread==0)
    {
        ptr=ptr->left;
    }
    return ptr;
}
void display(struct node* root)
{
    if(root==NULL)
        printf("\ntree is empty!!");
    struct node* ptr=root;
    while(ptr->lthread==0)
    {
        ptr=ptr->left;
    }
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=inordersuccesor(ptr);

    }
}

int main()
{
    int ch,x;
    struct node* root=NULL;
    printf("\nImplementation of Threded Binary Tree");
    printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    while(1)
    {
        printf("\n1.insert 2.display 3.exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the data: ");
                    scanf("%d",&x);
                root=insert(root,x);
                    break;
            case 2:display(root);
                    break;
            case 3:exit(1);
            default:printf("\nEnter a valid choice!!");
        }
    }
}*/


