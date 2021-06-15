#include <bits/stdc++.h>

using namespace std;

void solve(double y) {
    double a = asin(y);
    if(a > 1.0 || a < -1.0) {
        printf("FAIL!\n");
        return;
    }
    double b = acos(a);
    double res = b * 180.0 / M_PI; //<cmath>
    if(res < 0 || res > 180)
        printf("FAIL!\n");
    else
        printf("%.2lf\n", res);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double y; //y =  sin(cos(X*PI/180))
    while(scanf("%lf", &y) != EOF) {
        if(y > 1.0 || y < -1.0)
            printf("FAIL!\n");
        else 
            solve(y);
    }
    
    return 0;
}