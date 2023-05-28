#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;

const int MAXN = 5005;
const double EPS = 1e-7;

inline double dcmp(double x) {
    if (fabs(x) < EPS) return 0;
    return x > 0 ? 1 : -1;
}

struct P {
    double x, y;
    double det(const P &p) {
        return x*p.y - y*p.x;
    }
    double dis(const P &p) { 
        return (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y);
    }
    P operator - (const P &p) {
        return {x-p.x, y-p.y};
    }
    bool operator < (const P &p) const {
        return dcmp(x - p.x) == 0 ? y < p.y : x < p.x;
    }
    bool operator == (const P &p) const {
        return dcmp(x - p.x) == 0 && dcmp(y - p.y) == 0;
    }
    bool operator != (const P &p) const {
        return !(*this == p);
    }
};

vector<P> ps(MAXN), cov(MAXN);

void convex_hull(int n) {
    sort(ps.begin(), ps.begin() + n); // x 遞增；ps[0] 和 ps[n-1] 必定在凸包內
    n = unique(ps.begin(), ps.begin() + n) - ps.begin();

    cov.resize(n);  
    int k = 0;
    for(int i=0; i<n; ++i) {
        while(k>1 && (cov[k-1]-cov[k-2]).det(ps[i]-cov[k-1]) < EPS) --k;
        cov[k++] = ps[i];
    }

    for(int i=n-2, t=k; i>=0; --i) {
        while(k>t && (cov[k-1]-cov[k-2]).det(ps[i]-cov[k-1]) < EPS) --k;
        cov[k++] = ps[i];
    }
    if (k - 1 >= 0)
        cov.resize(k-1);
}

double area(P a, P b, P c) {
    return abs((a - b).det(a - c));
}

int main() {
    io;
	int n; cin >> n;

	for(int i=0; i<n; ++i) {
		cin >> ps[i].x >> ps[i].y;
	}
	convex_hull(n);

    n = cov.size();
	if (n < 3) {
		cout << "0\n";
		return 0;
	}

    double ans = 0;
    for(int i = 0; i < n; ++i) {
        int k = i + 2;
        for(int j = i + 1; j < n; ++j) {
            while(k + 1 < n && area(cov[i], cov[j], cov[k]) < area(cov[i], cov[j], cov[k + 1])) {
                ++k;
            }
            ans = max(ans, area(cov[i], cov[j], cov[k]));
        }
    }

    cout << fixed << setprecision(5) << ans * 0.5 << '\n';
	
    return 0;
}