#include <stdio.h>
#define MAX 8
int a[MAX];
int b[MAX];
void MergeSort(int, int);
void Merge(int, int, int);
int main()
{
    int i;
    printf("\nEnter array elements:\n");
    for(i=0;i<MAX;i++)
        scanf("%d",&a[i]);
    printf("\nList before sorting:\n");
    for(i=0;i<MAX;i++)
        printf("%d ",a[i]);
    printf("\n");
    MergeSort(0, MAX-1);
    printf("\nList after sorting:\n");
    for(i=0;i<MAX;i++)
        printf("%d ",a[i]);
    return 0;
}
void MergeSort(int low, int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        MergeSort(low, mid);
        MergeSort(mid+1, high);
        Merge(low,mid,high);
    }
}
void Merge(int low, int mid, int high)
{
    int p1,p2,i;
    for(p1=low,p2=mid+1,i=low;p1<=mid && p2<=high; i++)
    {
        if(a[p1]<a[p2])
            b[i]=a[p1++];
        else
            b[i]=a[p2++];
    }
    while(p1<=mid)
        b[i++]=a[p1++];
    while(p2<=high)
        b[i++]=a[p2++];
    for(i=low;i<=high;i++)
    {
        a[i]=b[i];
        printf("%d ",a[i]);
    }
    printf("\n");
}
