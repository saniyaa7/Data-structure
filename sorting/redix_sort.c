/*#include<stdio.h>
#include<stdlib.h>
int max(int a[],int size)
{
    int max=a[0];
    for(int i=0;i<size;i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    return max;
}
void redix_sort(int a[],int size)
{
    int i,j,k,pass,bucket[6][6],nop=0,r,divisor=1;
    int bucket_cnt[6];
    int max1=max(a,size);
    while(max1>0)
    {
        nop++;
       max1=max1/10;
    }
    for(pass=0;pass<nop;pass++)
    {
        for(i=0;i<6;i++)
        {
            bucket_cnt[i]=0;
        }
        for(i=0;i<6;i++)
        {
            r=(a[i]/divisor)%10;
            bucket[r][bucket_cnt[r]]=a[i];
            bucket_cnt[r]+=1;
        }
        i=0;
        for(k=0;k<6;k++)
        {
            for(j=0;j<bucket_cnt[k];j++)
            {
                a[i]=bucket[k][j];
            i++;
            }
        }
        divisor=divisor*10;
        printf("\npass-%d:\n",pass);
        for(i=0;i<6;i++)
    {
        printf("%d ",a[i]);
    }

    }

}
int main()
{
    int i=0,a[6]={12,34,78,90,10,45};
    int n;
    printf("\nEnter the size:");
    scanf("%d",&n);
    printf("\nArray before sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    redix_sort(a,n);
    printf("\nArray after sorting:\n");
     for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;

}*/

#include <stdio.h>
int get_max(int a[], int n)
{
    int max=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    return max;
}
void radix_sort(int a[], int n)
{
    int bucket[10][10], bucket_cnt[10];
    int i,j,k,r, NOP=0, divisor=1, max, pass;
    max=get_max(a,n);
    while(max>0)
    {
        NOP++;
        max=max/10;
    }
    for(pass=0;pass<NOP;pass++)
    {
        for(i=0;i<10;i++)
        {
            bucket_cnt[i]=0;
        }
        for(i=0;i<n;i++)
        {
            r=(a[i]/divisor)%10;    //e.g. 123
            bucket[r][bucket_cnt[r]]=a[i];
            bucket_cnt[r]+=1;
        }
        i=0;
        for(k=0;k<10;k++)
        {
            for(j=0;j<bucket_cnt[k];j++)
            {
                a[i]=bucket[k][j];
                i++;
            }
        }
        divisor=divisor*10;
        printf("\nAfter pass-%d:\n",pass);
        for(i=0;i<n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
}
int main()
{
    int i, n, a[10];
    printf("\nEnter no of elements to be sorted:");
    scanf("%d",&n);
    printf("\nEnter elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    radix_sort(a,n);
    printf("\nSorted Elements:");
     for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}



