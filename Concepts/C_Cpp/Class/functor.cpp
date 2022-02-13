/*
A functor is pretty much just a class which defines the "operator()"
that lets you create objects which "look like" a function
*/
#include <bits/stdc++.h>
using namespace std;

class pair_ {
    // default: private
    public:
        int fir, sec;
        pair_(int f, int s): fir(f), sec(s) {};
};

class cmp_class {
    public:
        bool operator()(const pair_ &p1, const pair_ &p2) const {
            return p1.fir == p2.fir ? p1.sec < p2.sec : p1.fir < p2.fir;
        }
} cmp_functor;

struct add_x {
    int x, y;
    add_x(int x): x(x) {};
    int operator()(int y) {
        return x + y;
    }
};

int main() {
    vector<pair_> v;
    for(int i=0; i<10; ++i) {
        // generate some data
        v.emplace_back(pair_((10*i+3)%17, i));
    }

    // use functor to sort
    // Note: the class of the functor is defined outside "pair_"!!!
    sort(v.begin(), v.end(), cmp_functor);
    cout << "elements of sorted pairs:\n";
    for(auto x: v) {
        cout << x.fir << ' ' << x.sec << '\n';
    }
    cout << '\n';

    vector<int> vv;
    for(int i=0; i<10; ++i) vv.emplace_back(i);
    // for(auto x: vv) cout << x << '\n';
    vector<int> res(vv.size());
    int x;

    add_x add3(3);
    // add 3 to each element in vv, and store them to res from res.begin()
    transform(vv.begin(), vv.end(), res.begin(), add3);
    for(auto x: res) cout << x << '\n';

    x = 102;
    // add "x" to each element in vv
    // add_x(x) first calls its constructor
    transform(vv.begin(), vv.end(), res.begin(), add_x(x));
    for(auto x: res) cout << x << '\n';
    return 0;
}