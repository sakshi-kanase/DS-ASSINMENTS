#include<stdio.h>
#include<conio.h>
void Insertion_sort(int a[6],int n)
{
int i,j,key;
for(j=1;j<n;j++)
 {
key=a[j];
for(i=j-1;i>=0;i--)
  {
    if(a[i]>key)
    a[i+1]=a[i];
  else
    break;
  }
  a[i+1]=key;
 }
}
void main()
{
int a[6],i,n;
clrscr();
printf("how many numbers");
scanf("%d",&n);
printf("\n enter the unsorted elements:");
for(i=0; i<n;i++)
scanf("%d",&a[i]);
Insertion_sort(a,n);
printf("\n thr sorted output is ");
for(i=0;i<n;i++)
printf("%d \t",a[i]);
getch();
}