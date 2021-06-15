#include <iostream>

using namespace std;

int abs(int x)
{
	if(x < 0)
		return -x;
	else
		return x;
}
int main()
{
	int h, x, y, ans;
	cin >> h >> x >> y;

	int zone_x, zone_y;
	if(abs(x - (x/15)*15) > 7) // each time zone crosses from -7.5 ~ +7.5
		zone_x = x > 0 ? (x/15)+1 : (x/15)-1;
	else
		zone_x = (x/15);
	if(abs(y - (y/15)*15) > 7) // each time zone crosses from -7.5 ~ +7.5
		zone_y = y > 0 ? (y/15)+1 : (y/15)-1;
	else
		zone_y = (y/15);

	int diff = zone_y - zone_x;
	if(diff < -h)
		ans = 24 + h + diff;
	else
		ans = h + diff;

	cout << (ans%24) << " o'clock\n";
	return 0;
}