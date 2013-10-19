#include <stdio.h>

int min(int a, int b)
{
  if (a>b)
    return b;
  return a;
}
int maxi(int a, int b)
{
  if (a<b)
    return b;
  return a;
}

int main()
{
  int start,stop,max,i,temp;
  for(;scanf("%d",&start)>0&&start!=EOF&&scanf("%d",&stop)>0;printf("%d %d %d\n",start,stop,max))
  {
    max=1;
    for(i=min(stop,start);i<=maxi(start,stop);i++)
    {
      int tempMax=1;
      temp=i;
      while(temp!=1)
      {
        if(temp%2==0)
          temp /=2;
        else
          temp = 3*temp+1;
        tempMax++;
      }
      max = max>tempMax? max:tempMax;
    }
  }
return 0;
}
