#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 4, MOD = 1e9+7;

struct matrix {
    int m[SIZE][SIZE];
    matrix() {
        memset(m, 0, sizeof(m));
    }

    matrix operator*(const matrix &x) {
        matrix res;
        for(int i=0; i<SIZE; ++i)
            for(int j=0; j<SIZE; ++j)
                for(int k=0; k<SIZE; ++k)
                    res.m[i][j] = (res.m[i][j] + m[i][k] * x.m[k][j] % MOD) % MOD;
        return res;
    }

    matrix power(int n) {
        matrix res;
        for(int i=0; i<SIZE; ++i)
            res.m[i][i] = 1;
        for(auto x=*this; n; n>>=1, x=x*x) {
            if(n & 1) res = res * x;
        }
        return res;
    }
};

int main() {
    int n;
    matrix fib;
    fib.m[0][0] = fib.m[0][1] = fib.m[1][0] = 1;
    for(int i=0; i<10; ++i) {
        cout << fib.power(i).m[0][0] << '\n';
    }
    return 0;
}