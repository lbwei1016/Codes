#include <bits/stdc++.h>

using namespace std;

struct car
{
    int model, horse_power;
};

bool operator<(car a, car b)
{
    //less
    return a.horse_power > b.horse_power;
}
bool comp(car a, car b); //can be defined as above

int main()
{
    vector<car> v;
    car a = {.horse_power = 899},
        b = {.horse_power = 19},
        c = {.horse_power = 1},
        d = {.horse_power = 99999};
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);

    //The elements are compared using operator< for the first version, and comp for the second.
    //Equivalent elements are not guaranteed to keep their original relative order (see stable_sort).
    sort(v.begin(), v.end());
    sort(v.begin(), v.end(), comp);
    for(car i : v)
        cout << i.horse_power << '\n';
    
    return 0;
}