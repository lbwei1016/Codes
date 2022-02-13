#include <bits/stdc++.h>
using namespace std;

class O {
    public:
        struct I {
            int num;
            static bool cmp(const I &a, const I &b) {
                return a.num < b.num;
            }
        } Is[10];
        int operator() (int a, int b) {
            return a + b;
        }
};
int main() {
    O tosort;
    for(int i=0; i<10; ++i) {
        cin >> tosort.Is[i].num;
    }
    sort(tosort.Is, tosort.Is+10, O::I::cmp);
    for(int i=0; i<10; ++i) {
        cout << tosort.Is[i].num << ' ';
    }
    cout << tosort(10, 20);
    return 0;
}