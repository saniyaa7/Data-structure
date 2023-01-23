#include<stdio.h>
#include<stdlib.h>
#define initial 1
#define visited 2
#define Max 100
int adj[Max][Max],n,state[Max];
void creat_graph();
void DFS_Traversal();
void DFS();
int main()
{
    creat_graph();
    DFS_Traversal();

}
void creat_graph()
{
    int org,dest;
  printf("\nEnter the no of vertices: ");
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
      printf("\nEnter the Edge %d : ",i);
      scanf("%d%d",&org,&dest);
      if(org==-1&&dest==-1)
        break;
      else if(org>n||org<0||dest>n||dest<0)
      {
          printf("\nInvalid edge!!");
          i--;
      }
      else
        adj[org][dest]=1;
  }
}
void DFS_Traversal()
{
    int v;
    for(v=0;v<n;v++)
    {
        state[v]=initial;
    }
    printf("\nEnter the starting vertex: ");
    scanf("%d",&v);
    DFS(v);


}
void DFS(int v)
{

    printf("%d ",v);
    state[v]=visited;
    for(int i=0;i<n;i++)
    {
        if(adj[v][i]==1&&state[i]==initial)
            DFS(i);
    }
}
