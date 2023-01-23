#include<stdio.h>
#include<stdlib.h>
int step=1,size;
void display(int ar[],int s)
{
    printf("\n");
    for(int i=0;i<s;++i)
    {
        printf("%d ",ar[i]);
    }
    printf("\n");
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void quicksort(int a[],int low,int high)
{
    int temp;
    int i,j,pivot;

    if(low<high)
    {
     pivot=low;
     i=low;
     j=high;
     while(i<j)
     {
        while(a[i]<=a[pivot]&&i<=high)
        i++;

        while(a[j]>a[pivot]&&j>=low)
         j--;
        if(i<j)
        {
           swap(&a[i],&a[j]);
        }

     }
        swap(&a[j],&a[pivot]);
        printf("\nstep-%d: ",step++);
        display(a,size);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);

    }
}
int main()
{
    int arr[50],i;

    printf("\nEnter the array size: ");
    scanf("%d",&size);
    printf("\nEnter array element:\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nbefore sorting array: ");
    display(arr,size);
    quicksort(arr,0,size-1);
    printf("\nAfter sorting array: : ");

    display(arr,size);
    return 0;

}




/*#include<stdio.h>
#include<stdlib.h>
void display(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}

int quicksort(int a[],int low,int high)
{
    int step=1;
    int i,j,temp,pivot;
    pivot=a[high];
    i=low-1;
    if(low<high)
    {

    for(int j=low;j<high;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
    temp=a[i+1];
    a[i+1]=a[j];
    a[j]=temp;
    printf("\nSTEP-%d",step++);
    display(a,high+1);
        quicksort(a,low,j-1);
    quicksort(a,j+1,high);
    }



}

int main()
{
    int n;
    int a[100];
    printf("\n----------QUICK SORT----------");
    printf("\n");
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter the element:");
    for(int i=0;i<n;i++)
    {
        printf("\nElement[%d]: ",i);
        scanf("%d",&a[i]);
    }
    printf("Array before sorting: ");
    display(a,n);
    quicksort(a,0,n-1);
    printf("\nArray after sorting:");
    display(a,n);
}*/

