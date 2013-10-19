#include "stdio.h"
#include "math.h"
#include "string.h"
#include "stdlib.h"
int gcd(int x, int y) {
  if (x==1)
    return 1;
  else if (y%x==0)
    return x;
  else {
    return gcd(y%x,x);
  }
}
int main (int argc, char** argv) {
  int N;
  while (scanf("%d",&N)>0) {
    int count=0;
    int *history = (int*)malloc(sizeof(int)*(N+1));
    memset(history,0,sizeof(int)*(N+1));
    int m,n;
    for (m=2;m*m<=N-1;m++) {
      for (n=1;n<m&&m*m+n*n<=N;n++) {
        int x_t = m*m-n*n;
        int y_t = 2*m*n;
        int z = m*m+n*n;
        int x = x_t>y_t?y_t:x_t;
        int y = x_t>y_t?x_t:y_t;
        int mult;
        for (mult=1;mult*z<=N;mult++) {
          history[x*mult]=1;
          history[y*mult]=1;
          history[z*mult]=1;
        }
      if (gcd(gcd(x,y),z)==1) {
        count++;
       }
      }
    }
    int i,count2=0;
    for(i=1;i<N+1;i++) {
      if(history[i]==0) {
        count2++;
      }
    }
    printf("%d %d\n",count,count2);  
  }
}
