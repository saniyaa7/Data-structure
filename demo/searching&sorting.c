

#include <stdio.h>
#define size 8

int search(int arr[], int x)
{
	int i;
	for (i = 0; i < size; i++)
		if (arr[i] == x)
			return i;
	return -1;
}


int main(void)
{
	int arr[size],x;
	printf("\nEnter the element:\n");
	for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);
    printf("\nEnter the searching element:  ");
    scanf("%d",&x);


	int result = search(arr, x);
	(result == -1)
		? printf("Element is not present in array")
		: printf("Element is present at index %d", result);
	return 0;
}
