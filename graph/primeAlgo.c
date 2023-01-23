#include<stdio.h>
#include<stdlib.h>
void Prime(int a[10][10],int n)
{
    int i,j,u,v,min,minCost=0,visited[10],ne=1;
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
    }
    visited[1]=1;
    while(ne<n)
    {
        for(i=1,min=999;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(a[i][j]<min)
                {
                    if(visited[i]==0)
                        continue;
                    else
                    {
                        min=a[i][j];
                        u=i;
                        v=j;
                    }

                }
            }
        }
        if(visited[u]==0||visited[v]==0)
        {
            printf("%d edge(%d,%d)=%d",ne++,u,v,min);
            minCost+=min;
            visited[i]=1;
        }
        a[u][v]=a[v][u]=999;


    }
    printf("\nCost of MST:%d",minCost);

}
int main()
{
    int n,a[10][10],v;
    printf("\nEnter the vertex: ");
    scanf("%d",&n);
    printf("\nEnter the adjecency matrix:\n");
    for(int i=1;i<=n;i++)
    {
       for(int j=1;j<=n;j++)
       {
           scanf("%d",&a[i][j]);
           if(a[i][j]==0)
                a[i][j]=999;
       }

    }


    Prime(a,n);
    return 0;

}
