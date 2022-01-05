#include <stdio.h>
typedef long long ll;
const ll MOD = 1e9;

void mul(ll A[][2], ll B[][2]) {
	ll res[2][2] = {0};
	for(int i=0; i<2; ++i) {
		for(int j=0; j<2; ++j) {
			for(int k=0; k<2; ++k) {
				res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD;
			}
		}
	}
	for(int i=0; i<2; ++i) {
		for(int j=0; j<2; ++j) A[i][j] = res[i][j];
	}
}
void _pow(ll n, ll M[][2]) {
	ll B[2][2] = {{1, 1}, {1, 0}};
	while(n > 0) {
		if(n & 1) {
			mul(M, B);
		}
		n >>= 1;
		mul(B, B);
	}
}

int main() {
	ll n;
	ll M[2][2] = {{1, 1}, {1, 0}};
	scanf("%lld", &n);
	_pow(n-1, M);
	printf("%lld\n", M[0][0]);
	return 0;
}
