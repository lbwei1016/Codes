#include <iostream>

using namespace std;

typedef struct num_mon
{
	int num;
	int mon;
}num_mon;

int main()
{
	num_mon prize[5];
	int luc[3];
	int sum = 0;

	cin >> luc[0] >> luc[1] >> luc[2];

	for(int i=0; i<5; ++i)
		cin >> prize[i].num;
	for(int i=0; i<5; ++i)
		cin >> prize[i].mon;

	for(int i=0; i<2; ++i)
	{
		for(int j=0; j<5; ++j)
		{
			if(luc[i] == prize[j].num)
				sum += prize[j].mon;
		}
	}

	bool is_third = false;
	for(int j=0; j<5; ++j)
	{
		if(luc[2] == prize[j].num)
		{
			sum += -(prize[j].mon);
			is_third = true;
		}
	}	

	if(!is_third)
		sum *= 2;

	if(sum < 0)
		cout << '0' << '\n';
	else
		cout << sum << '\n';

	return 0;
}
