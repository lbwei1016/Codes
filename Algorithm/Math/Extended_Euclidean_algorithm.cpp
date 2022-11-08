/*
***Extended Euclidean algorithm***
    Description:
        The algorithm can be used to find a solution pair: 
            {(x, y): x, y belong to Z} 
        that fulfills Bezout's identity: ax + by = 1 = gcd(a, b).
        gcd(a, b) must equal to 1；if not, no integer solution can
        be found.
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
    // 當輾轉相除法尚未結束
    if(b != 0)
    {
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x; // 這裡的 x, y 已經互換，所以: y = y(x2) - (a/b) * x(y2)
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
        y = 0; // 此時 y 為任意整數，可以設為 0 
    }
    return d;
}

// 另一種實作法
pair<int, int> extgcd2(int a, int b) {
    if (b == 0) return {1, 0};
    int k = a / b;
    pair<int, int> p = extgcd2(b, a - k*b);
    return {p.second, p.first - k*p.second};
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