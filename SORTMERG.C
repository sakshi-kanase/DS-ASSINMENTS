#include<stdio.h>
#include<conio.h>
void merge(int a[],int low,int mid,int high)
{
  int i,j,k,b[6];
  i=low;
  j=mid+1;
  k=0;
   while((i<=mid) && (j<=high))
     {
      if(a[i]<=a[j])
	b[k++]=a[i++];
      else
	 b[k++]=a[j++];
      }
   while(i<=mid)
     b[k++]=a[i++];
   while(j<=high)
     b[k++]=a[j++];
   for(i=low,k=0;i<=high;i++,k++)
     a[i]=b[k];
    }
  void mergesort(int a[],int low,int high)
   {
     int mid;
     if(low<high)
      {
       mid=(low+high)/2;
       mergesort(a,low,mid);   //sort first sub list
       mergesort(a,mid+1,high);   //sort second sub list
       merge(a,low,mid,high);//merge sorted sub list
      }
   }
   void main()
    {
     int a[6],i,n;
     clrscr();
     printf("\n how many numbera:");
     scanf("%d",&n);
     printf("\n enter the unsorted number:");
     for(i=0; i<n;i++)
     scanf("%d",&a[i]);
     mergesort(a,0,n-1);
     printf("/n the sorted list is:");
     for(i=0;i<n;i++)
     printf("%d \t ",a[i]);
     getch();
    }
