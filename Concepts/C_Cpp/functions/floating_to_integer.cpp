#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    double d = 2.36;
    printf("Original: %.2lf\n", d);
    printf("round: %.2lf, ceil: %.2lf, floor: %.2lf, trunc: %.2lf\n",\
        round(d), ceil(d), floor(d), trunc(d));    
    // round(d): 四捨五入
    return 0;
}