#include <iostream>
#include <iomanip> //for setw(): set field width

using namespace std;

int main()
{
    //用來對齊輸出
    cout << setw(8) << "Hi" << setw(11) << "COll\n"; 
    cout << setw(8) << "Wiwi\n";
    
    return 0;
}