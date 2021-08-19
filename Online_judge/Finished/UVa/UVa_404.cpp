#include <bits/stdc++.h>
using namespace std;

typedef pair<string, int> pst;
const double T = 5.0; // 5 sec, 10 miles
struct P { double ang, dis, spd; };
int n;
unordered_map<string, P> n1, n2;
vector<pst> st;

double speed(P p0, P p1) {
    double d = sqrt(p0.dis*p0.dis + p1.dis*p1.dis - \
        2*p0.dis*p1.dis*abs(cos((p0.ang-p1.ang)*M_PI/360)));
    return d * 3600 / T;
}
bool equip(P bef, P aft) {
    double v = speed(bef, aft), avg = (bef.spd+aft.spd)/2;
    if(avg < 0.9*v || avg > 1.1*v) return 1;
    else return 0;
}
bool intru(P aft) {
    double v = (10-aft.dis) * 3600 / T;
    if(aft.spd*1.1 > v) return 1; // new intrusion
    else return 0; // new aloft
}
bool domain(P bef) {
    double v = (10-bef.dis) * 3600 / T;
    if(bef.spd*1.1 > v) return 1; // domain exited
    else return 0;
}
inline bool cmp(pst a, pst b) {
    int num1 = 0, num2 = 0;
    for(int l=a.first.size(), i=l-1, t=1; i>=0; --i, t*=10) {
        num1 += (a.first[i]-'0') * t;
    }
    for(int l=b.first.size(), i=l-1, t=1; i>=0; --i, t*=10) {
        num2 += (b.first[i]-'0') * t;
    }
    return num1 < num2;
}
int main() {
    int cnt = 0;
    while(cin >> n) {
        st.clear(); n1.clear(), n2.clear();
        string no; P p;
        while(n--) {
            cin >> no >> p.ang >> p.dis >> p.spd;
            n1[no] = p;
        }
        cin >> n;
        while(n--) {
            cin >> no >> p.ang >> p.dis >> p.spd;
            if(!n1.count(no)) {
                if(intru(p)) st.push_back({no, 0});
                else st.push_back({no, 1});
            }
            else {
                if(equip(n1[no], p)) st.push_back({no, 2});
                n1.erase(no);
            }
            n2[no] = p;
        }
        for(auto m : n1) {
            no = m.first;
            if(!n2.count(no)) {
                if(domain(m.second)) st.push_back({no, 3});
                else st.push_back({no, 4});
            }
        }
        sort(st.begin(), st.end(), cmp);
        cout << "Scenario # " << ++cnt << '\n';
        for(auto x : st) {
            int wa = x.second;
            cout << setw(5) << x.first;
            if(wa == 0) cout << " -- new intrusion\n";
            else if(wa == 1) cout << " -- new aloft\n";
            else if(wa == 2) cout << " -- equipment warning\n";
            else if(wa == 3) cout << " -- domain exited\n";
            else cout << " -- domain loss\n";
        }
        cout << '\n';
    }
    return 0;
}