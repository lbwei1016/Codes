#include <bits/stdc++.h>
using namespace std;

struct SparseMatrix {
    int row, col, val;
};

vector<SparseMatrix> transpose(vector<SparseMatrix> &M) {
    int sz = M.size();
    vector<int> nonzero(sz+1);
    for (int i=0; i<sz; ++i) {
        ++nonzero[M[i].col];
    }
    vector<int> presum(sz+1);
    for (int i=1; i<sz; ++i) {
        presum[i+1] = presum[i] + nonzero[i];
    }
    vector<SparseMatrix> Transposed(sz);
    for (int i=0; i<sz; ++i) {
        int &id = presum[M[i].col];
        Transposed[id] = M[i];
        swap(Transposed[id].row, Transposed[id].col);
        ++id;
    }
    return Transposed;
}

int main() {
    vector<SparseMatrix> M;
    int num_of_elements;
    cin >> num_of_elements;
    for (int i=0; i<num_of_elements; ++i) {
        int row, col, val;
        cin >> row >> col >> val;
        M.push_back(SparseMatrix{row, col, val});
    }
    puts("-----------------------------");
    auto Transposed = transpose(M);
    for (auto &x: Transposed) {
        printf("row: %d, col: %d, val: %d\n", x.row, x.col, x.val);
    }
    return 0;
}
/*
input:
6
1 3 3
1 5 4
2 3 5
2 4 7
4 2 2
4 3 6
*/