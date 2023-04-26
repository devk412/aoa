#include<stdio.h>
int main()
{
int t,i,j,n;
int a[10];
printf("Enter Size of an Array: ");
scanf("%d" , &n);
printf("Enter an Array: ");
for(i=0; i<n; i++)
{
scanf("%d", &a[i]);
}
for(i=1; i<n; i++)
{
j=i-1;
int key= a[i];
while( j>=0 && a[j]>key)
{
a[j+1]=a[j];
j--;
}
a[j+1]=key;
printf("Pass Number %d : ", i);
for(t=0; t<n; t++)
{
printf("%d ", a[t]);
}
printf("\n");
}printf("Array Sorted: ");
for(i=0; i<n; i++)
{
printf("%d ", a[i]);
}
}
