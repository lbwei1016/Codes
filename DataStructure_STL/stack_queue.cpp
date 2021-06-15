#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	stack <int> s;
	queue <int> q;
	for(int i=0; i<10; i++)
	{
		s.push(i);
		q.push(i);
	}
	sort(s, s+10);
	for(int i=0; i<10; i++)
	{
		cout << "Stack: " << s.top() << ' '; 
		s.pop();
		cout << "Queue: " << q.front() << ' ' << '\n';
		q.pop();
	}

	return 0;
}