#include<stdio.h>
#include<stdlib.h>
#define Max 100
#define initial 1
#define waiting 2
#define visited 3
int q[Max],adj[Max][Max],state[Max],n;
void creat_graph();
void BFS_Traversal();
void BFS(int);
int isEmpty();
void enq(int);
int deq();
int f=-1,r=-1;
int main()
{
    creat_graph();
    BFS_Traversal();
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
void BFS_Traversal()
{
    int v;
    for(v=0;v<n;v++)
        state[v]=initial;
    printf("\nEnter the starting vertex: ");
    scanf("%d",&v);
    BFS(v);
}
void BFS(int v)
{
    enq(v);
    state[v]=waiting;
    printf("\nElement present in Graph:\n");
    while(!isEmpty())
    {
        v=deq();
        state[v]=visited;
        printf("%d ",v);
        for(int i=0;i<n;i++)
        {
            if(adj[v][i]==1&&state[i]==initial)
            {
                enq(i);
                state[i]=waiting;
            }

        }
    }
}
int isEmpty()
{
    if(f==-1||f==r+1)
        return 1;
    return 0;
}
void enq(int x)
{
    if(r==Max-1)
    {
        printf("\nQueue overflow");
        return;
    }
    if(f==-1)
        f=0;
    q[++r]=x;
}
int deq()
{
    if(isEmpty())
    {
        printf("\nQueue underflow");
        exit(1);
    }
    return q[f++];
}
