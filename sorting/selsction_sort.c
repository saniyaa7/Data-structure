#include<stdio.h>
#include<stdlib.h>
void display(int a[],int s);
int selction_sort(int a[],int s);


int main()
{
    int arr[6]={10,40,20,50,30,60};
    printf("\nthe array: ");
    display(arr,6);
    printf("\nthe array after calling function\n");
    selction_sort(arr,6);



}
void display(int a[],int s)
{
    for(int i=0;i<s;i++)
    {
        printf("%d ",a[i]);
    }
}
int selction_sort(int a[],int s)
{
    int min_ind,temp;
    int i,j;
    for(i=0;i<s-1;i++)
    {
        min_ind=i;
        for(j=i+1;j<s;j++)
        {
            if(a[j]<a[min_ind])
                min_ind=j;
        }
        temp=a[i];
        a[i]=a[min_ind];
        a[min_ind]=temp;
        display(a,s);
        printf("\n");
    }

}
