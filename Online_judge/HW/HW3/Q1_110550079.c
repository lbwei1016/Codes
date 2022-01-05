#include <stdio.h>
#define N 1005

void rec(int d, int sum, const int n, int a[N], int pre) {
	if(sum == n) {
		for(int i=1; i<=d; ++i) {
			printf("%d%c", a[i], i!=d?'+':'\n');
		}
		return;
	}
	for(int i=pre; i<=n-sum; ++i) {
		a[d+1] = i;
		rec(d+1, sum+i, n, a, i);
	}
}
int main() {
	int n, a[N] = {0};
	scanf("%d", &n);
	rec(0, 0, n, a, 1);
	return 0;
}
