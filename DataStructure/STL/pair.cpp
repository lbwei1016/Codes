#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> P; //good
int main()
{
	P p1, p2, p3;
	queue<P> q;
	q.push(P(1, 2)); //可以直接丟pair進去
	q.push(make_pair(3, 4)); //也可以_make_pair()
	q.push(pair<int, int>(5, 6)); //too

	p1 = q.front(); q.pop();
	p2 = q.front(); q.pop();
	p3 = q.front(); q.pop();
	cout << p1.first << '\n' << p2.first << '\n' << p3.first;

	return 0;
}