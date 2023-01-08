#include <iostream>

using namespace std;

bool adj[6][6] = 
{
	{0, 1, 1, 0, 0, 0}, 
	{1, 0, 0, 1, 0, 0},
	{1, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 1},
	{0, 0, 1, 0, 0, 0},
	{0, 0, 0, 1, 0, 0}
};
int p[6]; //p[n]的值相當於: parent of n

void DFS(int x)
{
	for(int y=0; y<6; y++)
	{
		if(adj[x][y] && y != p[x])
		{
			p[y] = x;
			DFS(y);
		}
	}
}

bool x_is_parent_of_y(int x, int y)
{
	return x == p[y];
}

int main()
{
	int root;
	cin >> root;
	p[root] = -1; //避免x=y時出錯

	int x, y;

	DFS(root);

	while(cin >> x >> y)
	{
		if(x_is_parent_of_y(x, y))
			cout << "x is parent of y" <<'\n';
		else if(x_is_parent_of_y(y, x))
			cout << "y is parent of x" <<'\n';
		else
			cout << "Not a parent and a child" << '\n';
	}
}