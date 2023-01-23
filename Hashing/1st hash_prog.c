#include<stdio.h>
#include<stdlib.h>
#define size 10
int arr[size];
void init()
{
    for(int i=0;i<size;i++)
    {
        arr[i]=-1;
    }
}
void insert(int value)
{
    int key=value%size;
    if(arr[key]==-1)
    {
        arr[key]=value;
        printf("\n%d inserted at arr[%d]",value,key);
    }
    else
    {
       for(int i=0;i,size;i++)
       {
           if(arr[key+i]==-1)
           {
             arr[key+i]=value;
        printf("\n%d inserted at arr[%d]",value,key+i);
        break;
           }
       }
    }
}
void display()
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==-1)
        {
            printf("~~ ");
        }
        else
        {
           printf("%d ",arr[i]);

        }

    }
}
void delete(int value)
{
    int key=value%size;
    for(int i=0;i,size;i++)
{
    key=key+i;
if(arr[key]==value)
   {
    printf("%d element deleted",arr[key]);
    arr[key]=-1;
   break;

   }
}

}
void search(int value)
{int key=value%size;
for(int i=0;i,size;i++)
{
    key=key+i;
if(arr[key]==value)
   {
    printf("search found!!\nat key %d",key);
   break;

   }
}

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
            search(x);
            break;

            case 3:printf("\nEnter value for delete: ");
            scanf("%d",&x);
            delete(x);
            break;

            case 4:display();
            break;

            case 5:exit(1);
            default:printf("\nEnter the valid choice!!");
        }
    }
}
