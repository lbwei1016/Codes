/*
***Binary-Search***
    (Be careful with double!!!)

	O(N6)
*/
#include <cstdio>
#include <cmath>

#define MAX_N 10000
#define INF 100005.0

using namespace std;

int N, K;
double L[MAX_N+1];

bool C(double x) //Condition
{
	int cnt = 0;
	for(int i=0; i<N; i++)
	{
		cnt += (int)(L[i] / x);
	}
	return cnt >= K;
}

int main()
{
	scanf("%d%d", &N, &K);
	for(int i=0; i<N; i++)
		scanf("%lf", &L[i]); //lf for double, f for float
	
	double lb = 0.0, ub = INF;
	for(int i=0; i<100; i++) //do binary search for 100 times ensures accuracy to 1e-30 (2^100)
	{
		double mid = (lb+ub) / 2;
		if(C(mid)) lb = mid;
		else ub = mid;
	}
	//printf("%.2lf\n", ub); 
	//the above is not accurate, for ".2lf" takes ceiling  
	//e.g. 2.0050000 -> 2.01 (X)
    
    //Error too:
    //printf("%.2lf\n", (double)((int)(ub*100)) /100);

	printf("%.2lf\n", floor(ub*100) / 100);
	
	return 0;
}