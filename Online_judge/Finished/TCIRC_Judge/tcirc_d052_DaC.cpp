/*
***Divide and Conquer***

    O(N * log N)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll subarray(ll a[], int l, int r) {
    if(l >= r) return 0;
    if(l+1 == r) return a[l];
    int m = (l+r) / 2;
    ll sep_max = max(subarray(a, l, m), subarray(a, m, r));

    //suffix sum from middle to left part
    ll l_max = 0, r_max = 0;
    for(ll i=m-1, sum=0; i>=l; i--) {
        sum += a[i];
        l_max = max(l_max, sum);
    }
    //prefix sum from middle to right part
    for(ll i=m, sum=0; i<r; i++) {
        sum += a[i];
        r_max = max(r_max, sum);
    }
    return max(l_max+r_max, sep_max);
}
int main() {
    int n;
    ll a[100004];
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%lld", &a[i]);
    }
    printf("%lld\n", subarray(a, 0, n));
    return 0;
}
/*
//P-5-2 max subarray, DaC, O(n)
#include <bits/stdc++.h>
#define N 200020
using namespace std;
typedef long long LL;
LL psum[N]; // prefix-sum
struct Rdata {
    //整個區間的 max-sum, max prefix-sum, max suffix-sum
    LL msum, lmax, rmax;
};

// return max in [le, ri),
Rdata subarr(LL a[], int le, int ri) {
    if (le+1 == ri) {
        LL t = max(a[le],(LL)0);
        return {t, t, t};
    }
    int mid=(le+ri)/2;
    // recursively solve left and right parts
    Rdata left=subarr(a, le, mid), right=subarr(a, mid, ri);
    Rdata my;
    //max( 只記左方的最大前綴和, 包含整個左方以及右方最大後綴和的新前綴和 )
    my.lmax=max(left.lmax, psum[mid-1]-psum[le-1]+right.lmax);
    my.rmax=max(right.rmax, psum[ri-1]-psum[mid-1]+left.rmax);
    //單邊的和
    my.msum=max(left.msum, right.msum);
    // find largest sum cross middle
    //左後綴和加右前綴和，才是一連續區段
    my.msum=max(my.msum, left.rmax+right.lmax);
    return my;
}

int main() {
	LL n, a[N];
	scanf("%lld",&n);
	a[0]=0, psum[0]=0;
	for (int i=1; i<=n; i++) {
		scanf("%lld", &a[i]);
		psum[i]=psum[i-1]+a[i];
	}
	printf("%lld\n", subarr(a, 1, n+1).msum);
	return 0;
}

*/