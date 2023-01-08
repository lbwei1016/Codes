/*
***Math / Divide and Conquer*** -- Strassen algorithm
    Description:
        將原先 O(n^3) 次的矩陣乘法降低至 O(n^log(2)7)；但因為遞迴加上常數過大，
        實際計算其實不比天真算法快。
    T(N) = 7T(N/2) +  O(N^2) => O(n^log(2)7) ~= O(n^2.807)
*/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
int N;

vector<vec> dac(vector<vec> &a, vector<vec> &b, int n) {
    if(n == 2) {
        vector<vec> mul(N, vec(N));
        mul[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
        mul[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
        mul[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
        mul[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1];
        return mul;
    }
    int k = n / 2;
    vector<vec> res(N, vec(N));
    // Strassen algorithm 的精隨
    vector<vec> a11a22(N, vec(N)), b11b22(N, vec(N)), a21a22(N, vec(N)), b12b22(N, vec(N)),\
    b21b11(N, vec(N)), a11a12(N, vec(N)), a21a11(N, vec(N)), b11b12(N, vec(N)), a12a22(N, vec(N)),\
    b21b22(N, vec(N)), a22(N, vec(N)), b22(N, vec(N));
    for(int i=0; i<k; ++i) {
        for(int j=0; j<k; ++j) {
            a11a22[i][j] = a[i][j]+a[i+k][j+k];
            b11b22[i][j] = b[i][j]+b[i+k][j+k];
            a21a22[i][j] = a[i+k][j]+a[i+k][j+k];
            b12b22[i][j] = b[i][j+k]-b[i+k][j+k];
            b21b11[i][j] = b[i+k][j]-b[i][j];
            a11a12[i][j] = a[i][j]+a[i][j+k];
            a21a11[i][j] = a[i+k][j]-a[i][j];
            b11b12[i][j] = b[i][j]+b[i][j+k];
            a12a22[i][j] = a[i][j+k]-a[i+k][j+k];
            b21b22[i][j] = b[i+k][j]+b[i+k][j+k];
            a22[i][j] = a[i+k][j+k];
            b22[i][j] = b[i+k][j+k];
        }
    }
    vector<vec> M1 = dac(a11a22, b11b22, k), M2 = dac(a21a22, b, k),\
    M3 = dac(a, b12b22, k), M4 = dac(a22, b21b11, k), M5 = dac(a11a12, b22, k),\
    M6 = dac(a21a11, b11b12, k), M7 = dac(a12a22, b21b22, k);
    // O(n^2) 合併
    for(int i=0; i<k; ++i) {
        for(int j=0; j<k; ++j) {
            res[i][j] = M1[i][j]+M4[i][j]-M5[i][j]+M7[i][j];
            res[i][j+k] = M3[i][j]+M5[i][j];
            res[i+k][j] = M2[i][j]+M4[i][j];
            res[i+k][j+k] = M1[i][j]-M2[i][j]+M3[i][j]+M6[i][j];
        }
    }
    return res;
}
int main() {
    cin >> N;
    vector<vec> A(2*N, vec(2*N)), B(2*N, vec(2*N));
    for(int i=0; i<N; ++i) 
        for(int j=0; j<N; ++j)
            cin >> A[i][j];
    for(int i=0; i<N; ++i) 
        for(int j=0; j<N; ++j)
            cin >> B[i][j];
    int to2 = 1, rec = N;
    // 擴大至二的冪次
    while(to2 < N) to2 <<= 1;
    N = to2;
    vector<vec> C = dac(A, B, N);
    for(int i=0; i<rec; ++i) {
        for(int j=0; j<rec; ++j)
            cout << setw(2) << C[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}