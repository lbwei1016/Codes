#include <stdio.h>
#include <math.h>

double func(double (*f)(double), double a, double b);
// or: double integrate(double f(double), double a, double b);

int main() {
    printf("%lf\n", func(sin, M_PI, 0.5));
    // without "( )", "sin" is a function pointer
    return 0;
}

double func(double f(double), double a, double b) {
    double y = f(a) + b;
    return y;
}