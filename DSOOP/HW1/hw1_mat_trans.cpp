#include <bits/stdc++.h>
using namespace std;
using Mat = vector<vector<int> >;

const int N = 5, M = 3;

Mat transpose(Mat &m, int Row, int Col) {
    Mat trans(Col, vector<int>(Row));
    for (int i=0; i<Row; ++i)
        for (int j=0; j<Col; ++j)
            trans[j][i] = m[i][j];
    return trans;
} 

int main() {
    Mat m(N, vector<int>(M));
    for (int i=0; i<N; ++i) 
        for (int j=0; j<M; ++j)
            cin >> m[i][j];

    Mat trans = transpose(m, N, M);
    for (auto &row: trans) {
        for (auto &x: row)
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}