#include <bits/stdc++.h>
using namespace std;

class Entry {
    public:
        int row, col, val;
        Entry() {}
        Entry(int &r, int &c, int &v): row(r), col(c), val(v) {}
};
class SparseMatrix {
    public:
        int size;
        Entry *entries;
        SparseMatrix(const int &sz): size(sz) {
            entries = new Entry[sz]();
        }
        SparseMatrix(SparseMatrix &M) {
            entries = new Entry[M.size];
            for (int i=0; i<M.size; ++i) {
                entries[i] = M.entries[i];
            }
        }
};

double time_measure(int N, int Time, SparseMatrix &M1) {
    time_t start, end;
    int cnt = 0;
    start = clock();
    do {
        ++cnt;
        SparseMatrix M2(M1);
        end = clock();
    } while (end - start < Time);
    return (end-start) / (double)cnt;
}

int main() {
    const int N = 100000, Time = 1000;
    SparseMatrix M1(N);
    for (int i=0; i<N; ++i) {
        M1.entries[i] = Entry(i, i, i);
    }
    printf("Time for copying a sparse matrix with %d entries:\n%lf ms\n", N, time_measure(N, Time, M1));
    return 0;
}