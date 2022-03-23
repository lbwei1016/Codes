#include <iostream>

using namespace std;

int n, k, arr[20];
bool DFS(int i, int sum)
{
	if(i == n) return arr[i] == sum;
		
	if(DFS(i+1, sum)) return true;
		
	if(DFS(i+1, sum+arr[i])) return true;

	return false;
}
int main()
{
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	cin >> k;

	if(DFS(0, 0)) 
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}