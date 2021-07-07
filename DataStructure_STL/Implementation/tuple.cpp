#include <iostream>

using namespace std;

int solution[5];	// 用來存放一組可能的情形

void print_solution()	// 印出一組可能的情形
{
	for (int i=0; i<5; i++)
		cout << solution[i] << ' ';
	cout << endl;
}

void backtrack(int n)	// n 為現在正在枚舉的維度(就是第幾個數)
{
	// it's a solution
	if (n == 5)
	{
		print_solution();
		return;
	}

	// 逐步枚舉數字1到10，並且遞迴下去，繼續枚舉之後的維度。
	for(int i=1; i<=10; i++)
	{
		solution[n] = i;
		backtrack(n+1);
	}
}

int main()
{
	backtrack(0);
	return 0;
}
