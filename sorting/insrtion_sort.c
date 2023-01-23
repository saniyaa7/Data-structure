#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define MAX 5
void printArray(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

}
void insertionSort(int a[],int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0&&key<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
        printf("\niteration no-%d  ",i);
        printArray(a,n);
        printf("\n");

    }
}

int main()
{
  int arr[]={9,8,7,6,5,4};
  printf("\nArray is:  ");
  printArray(arr,6);
  printf("\n");
  insertionSort(arr,6);
  printf("\nAfter calling the function:  ");
  printArray(arr,6);
  return 0;

}
