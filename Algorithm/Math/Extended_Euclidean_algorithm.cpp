/*
***Extended Euclidean algorithm***
    The algorithm can be used to find (x, y) that fulfills
    Bezout's identity: ax + by = 1 = gcd(a, b)

    O(log(max(a, b)))
*/
#include <iostream>
#include <cstdio>

using namespace std;

int a, b, x, y;
//ax + by = gcd(a, b) = 1
int extgcd(int a, int b, int &x, int &y)
{
    int d = a; //gcd(a, b)
    if(b != 0)
    {
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x;
        /*
            The above code is equivalent to:
                int r = extgcd(b, a%b, x, y);
                int temp = y; ------ temp = y2
                y = x - (a/b) * y; ------ y1 = x2 - (a/b) * y2
                x = temp; ------ x1 = y2
        */
    }
    else
    {
        x = 1;
        y = 0;
    }
    return d;
}
int main()
{
    cin >> a >> b;
    int d = extgcd(a, b, x, y);
    printf("gcd(a, b) = %d\n", d);
    if(d == 1)
    {
        printf("One solution for Bezout's identity is found!\n");
        printf("%d*%d + %d*%d = %d", x, a, y, b, d);
    }
        
    return 0;
}