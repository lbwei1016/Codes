#include <iostream>
#include <complex>

using namespace std;

int main() {
    
    complex<double> c(3.0, 4.0);
    printf("Real part: %lf\nImaginary part: %lf\n", c.real(), c.imag());
    cout << "absolute of c is: " << abs(c) << '\n';
    return 0;
}