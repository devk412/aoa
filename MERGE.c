#include <stdio.h>
int count;
void merge(int a[],int low,int mid,int high){
int h,i,j,k,b[10];
h=low;//left
i=low;
j=mid+1;//right
while((h<=mid) && j<=high){
if(a[h]<=a[j]){
b[i++]=a[h++];
}
else{
b[i++]=a[j++];
}
}
if(high>mid){
for(k=j;k<=high;k++){
b[i++]=a[k];
}
}
if(j>high){
for(k=h;k<=mid;k++){
b[i++]=a[k];
}
}
for(k=low;k<=high;k++){
a[k]=b[k];
}
}
void mergesort(int a[], int low, int high){
int mid;
 if(low<high){
 mid=(low+high)/2;
 mergesort(a,low,mid);
 mergesort(a,mid+1,high);
 merge(a,low,mid,high);
 }
 count++;
}
int main(){
int i,n;
printf("Enter the size of array \n");
scanf("%d",&n);
int a[n];
printf("Enter the elements\n");
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
printf("Elements are\n");
for(i=0;i<n;i++){
printf("%d\n",a[i]);
}
mergesort(a,0,n-1);
printf("Array after sorting: ");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
printf("\nNumber of calls made to the procedure: %d",count);
return 0;
}