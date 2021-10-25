#include <stdio.h>
#include <math.h>

double max(double a, double b) {
    return a>b ? a:b;
}
int main() {
    double c, n;
    scanf("%lf", &n);
    c = n*1.63 + max(0, n-120)*0.75 + max(0, n-330)*1.14 + max(0, n-500)*1.28\
        + max(0, n-700)*0.86 + max(0, n-1000)*0.75;
    printf("%.0lf\n", round(c));
    return 0;
}