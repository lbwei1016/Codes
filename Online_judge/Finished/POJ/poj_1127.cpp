/*
***Geometry*** -- An example of dealing with EPS

    Description:
        Check whether two given rods (line segments) are "connected".
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const double EPS = 1e-10; //for precision
const int MAX_N = 20;
const int MAX_M = 1000000;
//prevent error
double _abs(double a) {
    return a > 0 ? a : -a;
}
//for precision
double add(double a, double b) {
    if(_abs(a + b) < EPS * (_abs(a) + _abs(b))) return 0;
    return a + b;
}
//Points
struct P {
    double x, y;
    P() {}
    P(double x, double y) : x(x), y(y) {}
    P operator + (P p) {
        return P(add(x, p.x), add(y, p.y));
    }
    P operator - (P p) {
        return P(add(x, -p.x), add(y, -p.y));
    }
    P operator * (double d) {
        return P(x * d, y * d);
    }
    double dot(P p) {
        return add(x*p.x, y*p.y);
    }
    //determinant
    double det(P p) {
        return add(x*p.y, -y*p.x);
    }
};
//whether "q" is on the line segment of "p1, p2"
bool on_seg(P p1, P p2, P q) {
    return (p1-q).det(p2-q) == 0 && (p1-q).dot(p2-q) <= 0;
}
//whether "p1, p2" has an intersection with "q1, q2"
P intersection(P p1, P p2, P q1, P q2) {
    return p1 + (p2-p1) * ((q2-q1).det(q1-p1) / (q2-q1).det(p2-p1));
}

int n, m;
P p[MAX_N], q[MAX_N];
int a[MAX_M], b[MAX_M];
bool G[MAX_N][MAX_N]; //G[i][j]: whether "rod i" is CONNECTED to "rod j"

void solve() {
    for(int i=0; i<n; i++) {
        G[i][i] = true;
        for(int j=0; j<i; j++) {
            //if two rods are parallel
            if((p[i] - q[i]).det(p[j] - q[j]) == 0) {
                //whether they overlap each other
                G[i][j] = G[j][i] = on_seg(p[i], q[i], p[j]) 
                                    || on_seg(p[i], q[i], q[j])
                                    || on_seg(p[j], q[j], p[i])
                                    || on_seg(p[j], q[j], q[i]);
            }
            else {
                P inter = intersection(p[i], q[i], p[j], q[j]);
                //whether the intersection is on both segments
                G[i][j] = G[j][i] = on_seg(p[i], q[i], inter) && on_seg(p[j], q[j], inter);
            }
        }
    }

    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                /*
                    if "i" and "k" is CONNECTED and "k" and "j" is as well, 
                    "i" and "j" is CONNECTED
                */
                G[i][j] |= G[i][k] && G[k][j];
            }
        }
    }
    for(int i=0; i<m; i++) {
        puts(G[a[i]-1][b[i]-1] ? "CONNECTED" : "NOT CONNECTED");
    }
}

int main() {
    while(scanf("%d", &n)) {
        if(n == 0) break;
        for(int i=0; i<n; i++) {
            double x, y, x2, y2;
            scanf("%lf%lf%lf%lf", &x, &y, &x2, &y2);
            p[i] = {x, y};
            q[i] = {x2, y2};
        }
        for(m=0; scanf("%d%d", &a[m], &b[m]); m++) {
            if(a[m] == 0) break;
        }
        solve();
    }
    return 0;
}