#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "William says hello!";
    string sub1 = s.substr(0, 7); //s.substr(start_pos, lenth_of_substring)
    string sub2(s.begin()+8, s.begin()+12); //[iter1, iter2)
    cout << sub1+' ' << sub2 << '\n';
    return 0;
}