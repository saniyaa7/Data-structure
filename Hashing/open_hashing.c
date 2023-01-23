#include<stdio.h>
#include<stdlib.h>
#define size 10
struct node
{
    int data;
    struct node* next;
};
struct node *chain[size];
void init()
{
    for(int i=0;i<size;i++)
    {
        chain[i]=NULL;
    }
}
void insert(int value)
{
    struct node* tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=value;
    tmp->next=NULL;
    int key=value%size;
    if(chain[key]==NULL)
        chain[key]=tmp;
    else
    {
        struct node* p=chain[key];
        while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=tmp;
    }
}
void display()
{
    for(int i=0;i<size;i++)
    {
        struct node* tmp=chain[i];
        printf("chain[%d]-->",i);
        while(tmp)
        {
            printf("%d-->",tmp->data);
            tmp=tmp->next;
        }
        printf("NULL\n");
    }
}
int search(int value)
{
    int key=value%size;
    struct node* tmp=chain[key];
    while(tmp)
    {
        if(tmp->data==value)
        {
            return 1;
        }
        tmp=tmp->next;
    }
    return -1;

}
int delete(int value)
{
    int key=value%size;
    struct node* tmp=chain[key],*dealloc;
    if(tmp!=NULL)
    {
        if(tmp->data==value)
        {
            dealloc=tmp;
            tmp=tmp->next;
            free(dealloc);
            return 1;
        }
        else
        {
            while(tmp->next)
            {
                if(tmp->next->data==value)
                {
                    dealloc=tmp->next;
                    tmp->next=tmp->next->next;
                    free(dealloc);
                    return 1;
                }
                tmp=tmp->next;
            }
            }
        }
        return 0;
    }


int main()
{
    printf("\nImplementation of hash table\n");
    int ch,x;
    init();
    while(1)
    {
        printf("\n1.insert 2.search 3.delete 4.display 5.exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter the data: ");
            scanf("%d",&x);
            insert(x);
            break;

            case 2:printf("\nEnter value for search: ");
            scanf("%d",&x);
            int a=search(x);
            if(a!=-1)
                printf("%d element found!!",x);
            else
                printf("Not found");
            break;

            case 3:printf("\nEnter value for delete: ");
            scanf("%d",&x);

            if(delete(x))
                printf("%d element deleted ",x);
            else
                printf("Element not found");
            break;

            case 4:display();
            break;

            case 5:exit(1);
            default:printf("\nEnter the valid choice!!");
        }
    }
}

