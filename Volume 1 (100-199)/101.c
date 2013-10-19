#include <stdio.h>

void return_blocks(int b,int n,int array[],int index[],int top[])
{
  int a,iter,iteri=index[b]*n;
  for(iter=top[index[b]]-1;iter>=0;iter--)
  {
    if(array[iteri+iter]==b)
      break;
    else
    {
      a=array[iteri+iter];
      array[a*n+top[a]]=a;
      top[a]++;
      top[index[b]]--;
      index[a]=a;
    }
  }
}
void move(int a, int b, int n, int array[], int index[], int top[])
{
  int temp[n];
  int size = 0;
  int iter;
  for(iter=top[index[a]]-1;iter>=0;iter--)
  {
    temp[top[index[a]]-1-iter]=array[index[a]*n+iter];
    size++;
    if(array[index[a]*n+iter]==a)
      break;
  }
  top[index[a]] -= size;
  for(iter=0;iter<size;iter++)
  {
    index[temp[size-iter-1]]=index[b];
    array[index[b]*n+top[index[b]]+iter] = temp[size-iter-1];
  }
  top[index[b]] += size;
}
int main()
{
int n;
int iter,iter2,iteri;
scanf("%d",&n);
int array[n*n];
int index[n];
int top[n];
for(iter=0;iter<n;iter++)
{
  int iteri = iter*n;
  array[iteri]=iter;  
  index[iter]=iter;
  top[iter]=1;
}
int a,b;
char comm1[5], comm2[5];
while(scanf("%s",comm1)>0&&comm1!="quit" )
{
  scanf("%d",&a);
  scanf("%s",comm2);
  scanf("%d",&b);
  if(index[a]==index[b])
    continue;
  if(strcmp(comm1,"move\0")==0)
   return_blocks(a,n,array,index,top);
  if(strcmp(comm2,"onto\0")==0)
    return_blocks(b,n,array,index,top);
  move(a,b,n,array,index,top);
}

for(iter=0; iter<n; iter++)
{
  printf("%d:",iter);
  iteri=iter*n;
  for(iter2=0; iter2<top[iter]; iter2++)
  {
    printf(" %d",array[iteri+iter2]);
  }
  printf("\n");
}
return 0;
}
