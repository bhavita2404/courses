#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
int n,l,k,max,m;
srand(0);
n=(rand() % 10 +1)*pow(7,10);
int c[n],i,j;
for(i=0;i<n;i++)
{
 c[i]=0;
}
for(k=0;k<10000;k++)
{
int s[n]={0};
for(i=1;i<=n;i++)
{
  m=rand()%n;
  s[m]=s[m]+1;

}
 max=maxi(s,n)
for(l=1;l<=n;l++)
{
    if(max==l)
    c[l]=c[l]+1;
}
}
int max1;
max1=maxi(c,n);
printf("%d",max1);
return 0;
}
int maxi(int s[],int n)
{
  int j;
  int max=s[1];
for(j=2;j<=n;j++)
{
  if(s[j]>max)
  {
    max=s[j];
  }
}
  return max;
}
