#include<stdio.h>
#include<conio.h>
void Bubble_Sort(int a[6],int n)
{
  int i, temp, pass;
  for (pass=1; pass<n; pass++)
  for(i=0; i<=n-pass-1;i++)
    {
    if(a[i]>a[i+1])
      {
      temp=a[i];
      a[i]=a[i+1];
      a[i+1]=temp;
      }
    }
 }
  void main()
 {
   int a[6],i,n;
   clrscr();
   printf("how many numbers:");
   scanf("%d",&n);
   printf("\n enter the unsorted elements:");
   for(i=0;i<n;i++)

    scanf("%d",&a[i]);

   Bubble_Sort (a,n);
   printf("\n the sorted output is:");
   for(i=0;i<n;i++)

   printf("%d \t",a[i]);

   getch();
 }