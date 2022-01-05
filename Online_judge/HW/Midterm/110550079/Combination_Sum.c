#include <stdio.h>

int arr[10005];
int t, tar, n, cnt;

void print(int lp) {
	for(int i=0; i<n; ++i) {
		if(lp & (1<<i)) putchar('O');
		else putchar('X');
	}
	puts("");
}
void rec(int d, int sum, int n_pick, int list_pick) {
	if(d == n || d == 20) {
		if(sum == tar) {
			print(list_pick);
			++cnt;
		}
		return;
	}
	if(sum+arr[d] <= tar) {
		list_pick |= (1<<d);
		rec(d+1, sum+arr[d], n_pick+1, list_pick);
		list_pick ^= (1<<d);
	}
	rec(d+1, sum, n_pick, list_pick);
}
int main() {
	scanf("%d", &t);
	while(t--) {
		cnt = 0;
		scanf("%d", &tar);
		int tmp;
		for(n=0; scanf("%d", &tmp); ++n) {
			if(tmp == 0) break;
			arr[n] = tmp;
		}
		rec(0, 0, 0, 0);
		if(cnt) puts("finish");
		else puts("no solution");
	}
	return 0;
}
