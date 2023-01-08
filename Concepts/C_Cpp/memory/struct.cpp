#include <bits/stdc++.h>

using namespace std;

typedef struct as
{
    int a;
    int *p;

}as;
typedef struct
{
    //do something
}A;
struct B
{
    //do something 
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int x = 10;

    as str;
    as *pstr = &str;

    str.a = 9;
    cout << str.a << '\n';
    str.p = &x;
    cout << *(str.p) << '\n';
    (*pstr).a = 87;
    cout << pstr->a << '\n';
          //(*pstr).a
    cout << str.a << '\n';

	return 0;
}

