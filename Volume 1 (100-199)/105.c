#include <stdio.h>

int main()
{
  int height[10001];
  int li,hi,ri,i;
  int max=0;
  for(i=0;i<10001;i++)
    height[i]=0;
  while(scanf("%d %d %d",&li,&hi,&ri)>0)
  {
    for(i=li;i<ri;i++)
      if(height[i]<hi)
        height[i]=hi;
    if(max<ri)
      max=ri;
  }
  if(height[0]!=0)
      printf("%d %d ",0,height[0]);
  for(i=1;i<=max;i++)
  {
    if(height[i]==height[i-1])
      continue;
    if(i==max)
      printf("%d %d",i,height[i]);
    else
      printf("%d %d ",i,height[i]);
  }
  printf("\n");
  return 0;
}
