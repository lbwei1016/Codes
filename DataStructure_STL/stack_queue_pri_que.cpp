#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	stack<int> s;
	queue<int> q;
	priority_queue<int> pq1; //???æ¸?
	priority_queue<int, vector<int>, greater<int> > pq2; //store by increasing value 
	priority_queue<int> pq3; //ä¹?ä»?-1ä¾??????????å¢?

	int val[10] = {10, 30, 58, 45, 71, 100, 25, 6, 999, 50};

	for(int i=0; i<10; ++i)
	{
		s.push(val[i]);
		q.push(val[i]);
		pq1.push(val[i]);
		pq2.push(val[i]);
		pq3.push(-val[i]);
	}

	for(int i=s.size(); i>0; --i)
	{
		cout << "stack: " << s.top() << '\n';
		s.pop();
		cout << "queue: " << q.front() << '\n'; //??¦æ??back()
		q.pop();
		cout << "priority_queue: " << pq1.top() << '\n';
		pq1.pop();
		cout << "priority_que(greater): " << pq2.top() << '\n';
		pq2.pop();
		cout << "priority_que(to be greater): " << -pq3.top() << '\n';
		pq3.pop();

		cout << '\n';
	}
}