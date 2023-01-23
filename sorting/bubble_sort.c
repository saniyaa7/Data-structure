#include<stdio.h>
#include<stdlib.h>
void bubble_sort(int a[],int n)
{
    int i,j,k,flag=0,temp;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]<a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;

            }

        }
        printf("\n%d iteration ",i+1);
        for(k=0;k<n;k++)
        {
            printf("%d ",a[k]);
        }

        if(flag==0)
            break;
    }
}

int main()
{
    int size=7,i;
    printf("orignal aaray is ");
    int arr[]={34,23,90,45,15,72,9};
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    bubble_sort(arr,size);
    printf("\n\nsorted array is ");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }

}
