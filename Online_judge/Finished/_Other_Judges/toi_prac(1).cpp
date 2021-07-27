#include <iostream>

using namespace std;

int main()
{
	int a[3], b[3];

	for(int i=0; i<3; ++i)
		cin >> a[i] >> b[i]; //3 2 /5 3 /7 2

	int i = 0, ans = 0;
	while(true)
	{
		
		for(++i;; ++i)
		{
			ans = a[0]*i + b[0]; //2 23
			if((ans-b[1])%a[1] == 0) //
				break;
		}
		if((ans-b[2])%a[2] == 0)
			break;
	}

	cout << ans << '\n';
	
	return 0;
}
