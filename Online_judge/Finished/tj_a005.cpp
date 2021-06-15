#include <iostream>
#include <cstdio> 

using namespace std;

int main() 
{ 
	int c, w, count = 0;
    scanf("%d%d", &c, &w); //c: candy; w: 獨角蟲+鐵殼蛹

    while(c+w >= 12 && w > 0)
    {
        while(c >= 12)
        {
            int ev = c/12;
            c %= 12;
            c += ev;
            count += ev;
        }
        
        if(c+w-12 > 0)
        {
            int temp = 12-c;
            w -= temp;
            c += temp;
        }
        else
            break;
    }

    printf("%d\n", count);
	return 0; 
} 
