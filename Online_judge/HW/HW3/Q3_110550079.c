#include <stdio.h>
#define N 1005
typedef long long ll;
const int MOD = 1e9+7;

ll mul(ll q) {
	ll num = (1<<q) - 2;
	ll res = 1;
	for(int i=0; i<q-1; ++i) {
		res = res * num % MOD;
		num = num * num % MOD;
	}	
//	num = num * tmp2 % M4OD;
	res = res * ((1<<(q))-1) % MOD;
	return res;
}
int main() {
	ll q;
	scanf("%lld", &q);
	if(q == 1) {
		puts("1");
		return 0;
	}
	if(q == 2) {
		puts("6");
		return 0;
	}
	printf("%lld\n", mul(q));
	return 0;
}
