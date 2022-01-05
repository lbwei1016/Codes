#include <stdio.h>
#define min(a, b) ((a)<(b)?(a):(b))

int main() {
	int arr[100005] = {0};
	int T, L, sum = 0;
	scanf("%d\n%d", &T, &L);
	for(int i=0; i<L; ++i) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	if(sum < T) {
		puts("0");
		return 0;
	}
	int lb = 0, ub = 0;
	int mn = 1e9;
	sum = 0;
	while(1) {
		while(ub<L && sum<T) {
			sum += arr[ub++];
		}
		if(sum < T) break;
		mn = min(mn, ub-lb);
		sum -= arr[lb++]; // 一次往右縮一個就好
	} 
	printf("%d\n", mn);
	return 0;
}
