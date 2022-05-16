#include <iostream>

using namespace std;

template <typename T>
T sum(T a, T b)
{
	return a+b;
}

template<class A>
class Price
{
	private:
		A price;
	public:
		void print()
		{
			cout << price << endl;
		}
		void set_price(A a)
		{
			price = a;
		}

};
int main()
{
	//cout << sum<int>(10 , 5) << '\n' << sum<double>(5.5, 6.5);
	Price<int> p;
	p.set_price(10);
	p.print();

	Price<double> p_d;
	p_d.set_price(25.6);
	p_d.print();
	return 0;
}