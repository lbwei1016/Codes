#include <bits/stdc++.h>
using namespace std;

typedef long double lb;
int main() {
    // string s; 
    double D[4];
    char c;
    double /*D[0], D[1], D[2], D[3], */ss, tt, nt, nb, nv1, nv2, t, ns;
    scanf("%lf %c %lf %c %lf %c %lf", &D[0], &c, &D[1], &c, &D[2], &c, &D[3]);
    // cin >> s; s += ',';
    // for(int i=0, j=0; j<4; ++i) {
    //     if(s[i] == ',') {
    //         D[j++] = stod(s);
    //         s = s.substr(i+1);
    //         i = -1;
    //     }
    // }
    ss = D[0]*D[0] + 1*1; ;
    tt = D[1]*D[1] + ss; t = sqrt(tt);
    nt = atan(D[0]) + D[2];
    nb = atan(D[1]/sqrt(ss)) + D[3]; // degree
    ns = t * cos(nb);
    nv2 = t*sin(nb);
    nv1 = ns*sin(nt);
    printf("%.2lf,%.2lf,%.2lf\n", t, nv1, nv2);
    return 0;
}