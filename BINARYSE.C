#include<stdio.h>
#include<conio.h>
int binarysearch(int a[],int n,int key)
{
int top,mid,bottom;
top=0;
bottom=n-1;
while(top<=bottom)
{
 mid=(top+bottom)/2;
 if(a[mid]==key)
  return mid+1;
  else
   if(key< a[mid])
   bottom=mid-1;
   else
   top=mid+1;
}
return -1;
}
void main()
{
 printf("how many numbers");
 scanf("%d",&n);
 printf("enter the numbers");
 for(i=0;i<n; i++)
 scanf("%d", &a[i]);
 printf("enter the key to be searched");
 scanf("%d",&key);
 ans=binarysearch(a,n,key);
 if(ans==-1)
  printf("element not found");
  else
  printf("record found at position %d",ans);
getch();
}
