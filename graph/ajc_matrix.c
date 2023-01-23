#include<stdio.h>
#include<stdlib.h>
#define M 100
int adj[M][M];
int n;
void creat_graph();
void insert(int ,int);
int del(int,int);
void display();
int main()
{
  int ch,org,dest;
  creat_graph();
    while(1)
    {
        printf("\n1.insert 2.delete 3.display 4.exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter the edge to be inserted: ");
            scanf("%d%d",&org,&dest);
            insert(org,dest);
            break;
            case 2:printf("\nEnter the edge to be deleted: ");
            scanf("%d%d",&org,&dest);
            int x=del(org,dest);
            (x!=-1)? printf("\nEdge(%d %d) deleted",org,dest):printf("\nThis edge is not exist");
            break;
            case 3:display();
            break;
            case 4:exit(1);
            default:printf("\nEnter valid choice!!");
        }
    }
}
void creat_graph()
{
    int org,dest;
    printf("\nEnter the number of vertices:");
    scanf("%d",&n);
    for(int i=1;i<=n*(n-1);i++)
    {
        printf("\nEnter the edge-%d(-1 -1 to quite): ",i);
        scanf("%d%d",&org,&dest);
        if(org==-1&&dest==-1)
            break;
        if(org<0||dest<0||org>n||dest>n)
        {
            printf("invalid edge!!");
            i--;
        }
        else
            adj[org][dest]=1;

    }
}
void insert(int org,int dest)
{
    if(org>n||org<0)
        printf("\nInvalid origin!!");
    else if(dest>n||dest<0)
        printf("\nInvalid destination!!");
    else if(adj[org][dest]==1)
        printf("\nEdge already exits");
    else
        adj[org][dest]=1;
}
int del(int org,int dest)
{
     if(org<0||dest<0||org>n||dest>n)
         return -1;

     if(adj[org][dest]!=1)
        return -1;
     adj[org][dest]=0;
     return 1;

}
void display()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
}
