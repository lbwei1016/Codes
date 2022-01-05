#include <stdio.h>
#define N 1005
typedef long long ll;

void print(int a, int f) {
	for(int i=1; i<=a; ++i) {
		for(int j=1; j<=i; ++j) 
			printf("%d", i);
		puts("");
	}
	for(int i=a-1; i>0; --i) {
		for(int j=1; j<=i; ++j) 
			printf("%d", i);
		puts("");
	}
}
int main() {
	int w, a, f;
	scanf("%d", &w);
	while(w--) {
		scanf("%d %d", &a, &f);
		while(f--) print(a, f);
		puts("");
	}
	
	return 0;
}
