#include <iostream>
#include <cmath>

using namespace std;

const double EPS = 1e-10;

double add(double a, double b) {
    if(abs(a + b) < EPS * abs(a) + abs(b)) return 0;
    return a + b;
}
//a < 0
bool is_negative(double a) {
    return a < -EPS;
}
//a <= 0
bool isNot_positive(double a) {
    return a < EPS;
}
bool is_zero(double a) {
    return abs(a) < EPS;
}

int main() {

    double a = 1e-300;
    double b = 1e-300;
    int cnt1 = 0, cnt2 = 0;
    for(int i=0; i<100; i++) {
        a = sqrt(a) * sqrt(a);
        b * 1e34 * 1e-34;
        if(a-b == 0) cnt1++;
        else cnt2++;
    }
    cout << "equal: " << cnt1 << '\n';
    cout << "not equal: " << cnt2 << '\n';
    /*
        The above result is 100 : 0, for we only do easy operations.
        If more complicated operations are taken, deviations(errors) 
        may occur, and thus we should adopt above functions.
    */
    
    return 0;
}