#include<stdio.h>
#include<stdlib.h>
int step=1;
void display(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}

int partition(int a[],int low,int high)
{
    int tmp;
    int i,j,p;

    if(low<high)
    {
     p=a[low];
     i=low;
     j=high;
     while(i<j)
     {
        while(a[i]<=p&&i<=high)
        i++;

        while(a[j]>p&&j>=low)
         j--;
        if(i<j)
        {
           tmp=a[i];
           a[i]=a[j];
           a[j]=tmp;
        }

     }
        tmp=a[j];
        a[j]=a[low];
        a[low]=tmp;
        printf("\nstep-%d: ",step++);
        display(a,high+1);
        return j;


    }
}

void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int j=partition(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}





int main()
{
    int i;
    int a[]={2,74,1,48,5,3,967,7,6};
    int size=sizeof(a)/sizeof(a[0]);
    printf("\n----QuickSort----\n");
    printf("\nArray before sorting:\n");
    for(i=0;i<size;i++)
        printf("%d ",a[i]);
    quicksort(a,0,size-1);
    printf("\nArray After sorting:\n");
    for(i=0;i<size;i++)
        printf("%d ",a[i]);

        return 0;

}
