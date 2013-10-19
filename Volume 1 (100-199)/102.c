#include <stdio.h>
#include <string.h>
int main()
{
  int b[3];
  int g[3];
  int c[3];
  int iter;
  int total;
  int numMoves;
  char config[4];
  while(scanf("%d %d %d %d %d %d %d %d %d",
              &b[0],&g[0],&c[0],&b[1],&g[1],&c[1],&b[2],&g[2],&c[2])==9)
  {
    total=0;
    for(iter=0;iter<3;iter++)
    {
      total+=b[iter];
      total+=g[iter];
      total+=c[iter];
    }
    numMoves = total-b[0]-g[2]-c[1];
    strcpy(config,"BCG\0");
    if(numMoves > total-b[0]-g[1]-c[2])
    {
      numMoves=total-b[0]-g[1]-c[2];
      strcpy(config, "BGC\0");
    }
    if(numMoves > total-b[1]-g[2]-c[0])
    {
      numMoves = total-b[1]-g[2]-c[0];
      strcpy(config,"CBG\0");
    }
    if(numMoves > total-b[2]-g[1]-c[0])
    {
      numMoves = total-b[2]-g[1]-c[0];
      strcpy(config,"CGB\0");
    }
    if(numMoves > total-b[1]-g[0]-c[2])
    {
      numMoves = total-b[1]-g[0]-c[2];
      strcpy(config,"GBC\0");
    }
    if(numMoves > total-b[2]-g[0]-c[1])
    {
      numMoves = total-b[2]-g[0]-c[1];
      strcpy(config,"GCB\0");
    }

    printf("%s %d\n",config,numMoves);
  }
return 0;
}
