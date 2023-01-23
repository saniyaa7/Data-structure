/*#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int top;
int stack[MAX];
void push(int x)
{
    if(top==MAX-1)
        printf("\nstack overflow");
    else
    {
        stack[++top]=x;
    }
}
int pop()
{
    if (top==-1)
    {
        printf("stack underflow");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}
void display()
{
    if(top==-1)
    {


        printf("underflow");
        return; }
    else
    { printf("\ntop=%d \n",top);
       for(int i=0;i<=top;i++)
       {
           printf("%d ",stack[i]);
       }
    }
}
int main()
{
    top=-1;
    int x,ch;
    while(1)
    {
        printf("\n1.ins 2.del 3.disp 4.exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nenter num: ");
                   scanf("%d",&x);
                   push(x);
                   break;
            case 2:x=pop();
                  if(x!=-1)
                    printf("\n%d element deleted",x);
                  break;
            case 3: display();
            break;
            case 4:exit(1);
            default:printf("\nwrong choice!!");
        }
    }
}*/
vfhb

/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
int top;
int stack[MAX];
void push(char x)
{
    if(top==MAX-1)
    {


        printf("\nstack overflow");
        return; }
    else
    {
        stack[++top]=x;
    }
}
char pop()
{
    if (top==-1)
    {
        printf("stack underflow");
       // return -1;
    }
    else
    {
        return stack[top--];
    }
}

int main()
{
    char str[MAX];
    top=-1;
    printf("\nenter the string ");
   // scanf("%s",str);
   gets(str);
    for(int i=0;i<strlen(str);i++)
    {
        push(str[i]);
    }
    for(int i=top;i>=0;i--)
    {
        printf("%c ",pop());
    }
}*/
dsgvdfnjt
#include<stdio.h>
#include<stdlib.h>
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
void redix_sort(int a[],int n)
{
   int i,j,k,bucket[10][10],bucket_cnt[10],pass,NOP,r,divisor=1;
  int max=get_max(a,n);
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
       for(i=0;i<10;i++)
       {
           r=(a[i]/divisor)%10;
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
       printf("\nAfter sorting pass-%d",pass);
       for(int i=0;i<n;i++)
       {
           printf("%d ",a[i]);
       }
   }
}

int main()
{
    int i,n,a[10];
    printf("Enter size of array: ");
    scanf("%d",&n);
    printf("Array before sorting:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    redix_sort(a,n);
    printf("Array after sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

}




