#include<stdio.h>
int main ()
{
  int n;
  double s=0;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
     s=s+1/double(i);
  }
  printf("tong la: %f",s);
  return 0;
  
}
