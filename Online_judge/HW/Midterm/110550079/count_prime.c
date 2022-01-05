#include <stdio.h>
#define N 5000008
//const int N = 1e6;

int prime[N];

void sieve() {
	for(int i=2; i<N; ++i) {
		prime[i] = 1;
	}
	for(int i=2; i<N; ++i) {
		if(prime[i]) {
			for(int j=2*i; j<N; j+=i) {
				prime[j] = 0;
			}
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	sieve();
	int cnt = 0;
	for(int i=2; i<n; ++i) {
		if(prime[i]) ++cnt;
	}
	printf("%d\n", cnt);
	return 0;
}
