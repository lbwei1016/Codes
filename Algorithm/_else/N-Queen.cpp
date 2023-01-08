#include <iostream>

using namespace std;

//"k": currnet row；p[i]: at which column the queen at row i is
int nqr(int n, int k, int p[]) {
    if(k >= n) return 1;

    int total = 0;
    bool valid[n]; //which column is valid
    for(int i=0; i<n; i++) valid[i] = true;
    //to invalidate the cols that would be attacked by previous queens
    for(int i=0; i<k; i++) {
        valid[p[i]] = false;
        /* To check whether pos "j" will be attacked diagonally
            Current A(k, j), mark positions attacked by B(i, p[i]).
            If A, B are on the same diagonal, (k, j) = (i+m, p[i]+m).
            Let k = i+m:
            I:
                Define j = k - i + p[i] = p[i] + m;
                if j exists, j is on the same diagonal with i.
            II:
                Define j' = p[i] - (k-i) = p[i] - m；
                same as above.
        */
        int j = k - i + p[i];
        if(j < n) valid[j] = false;
        j = p[i] - (k-i);
        if(j >= 0) valid[j] = false;
    }
    for(int i=0; i<n; i++) {
        if(valid[i]) {
            p[k] = i;
            total += nqr(n, k+1, p);
        }
    }
    return total;
}

int main() {
    int p[15];
    int n = 12;
    printf("Total %d ways\n", nqr(n, 0, p));
    return 0;
}