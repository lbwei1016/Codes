#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
	vector<int> v = {10, 15, 20, 21, 20, 45}; 
	//before calling upper or lower_bound, an array should be sorted
	sort(v.begin(), v.end());
	auto up_it = upper_bound(v.begin(), v.end(), 20); //find i for a[i]> 20(here is 21；i=3)
	cout << "The element > 20 is at pos: " << (up_it - v.begin()) << '\n';
	auto low_it = lower_bound(v.begin(), v.end(), 20); //find i for a[i]>= 20(here is 20；i=2)
	cout << "The element >= 20 is at pos: " << (low_it - v.begin()) << '\n';
	cout << "The number of asked element(here 20) is: " << (up_it-low_it) << '\n';

	int arr[] = {1, 2, 3, 4, 5, 8, 10};
	//lower_bound returns pointer
	cout << lower_bound(arr, arr+7, 5)-arr << '\n';

	pair<int, int> p[5] = {
		{2, 5},
		{5, 4},
		{98, 12},
		{2, 34},
		{2, -2}
	};
	sort(p, p+5);

	//compare first element, then the second
	auto p_lb = lower_bound(p, p+5, make_pair(2, 999999));
	cout << (*p_lb).first << ' ' <<(*p_lb).second << '\n';

	return 0;
}