#include <stdio.h>
#include <math.h>

int main(void)
{
  int i, j, w, l, x, y, side_c = 1, count = 0, side;
  char patt[20][20];
  scanf("%d%d", &w, &l);
  for(i=0; i<l; i++)
    fgets(patt[i], 20, stdin);

  scanf("%d%d", &x, &y);
  for(i=1; x-i>=0; i++)
  {
    if(patt[x-i][y] == patt[x][y])
    {
      side_c++;
    }
    else
      break;
  }
  for(i=x-(side_c-1); i<=x+(side_c-1); i++)
  {
    for(j=y-(side_c-1); j<=y+(side_c-1); j++)
    {
      if(i < 0 || j < 0)
      {
        side_c--;
        i = x-(side_c-1)-1;
        break;
      }
      if(patt[i][j] == patt[x][y])
        count++;
      else
      {
        count = 0;
        side_c--;
        i = x-(side_c-1)-1;
        break;
      }
    }
  }
  side = sqrt(count);
  printf("%d", side);
  return 0;
}
