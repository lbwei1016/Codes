#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Time complexity:
    //     Unspecified, but generally linear in the length of the returned object.
    string s = "William says hello!";
    string sub1 = s.substr(0, 7); //s.substr(start_pos, lenth_of_substring)
    string sub2(s.begin()+8, s.begin()+12); //[iter1, iter2)
    string sub3 = s.substr(13); // form pos 13 to the end
    cout << sub1+'\n'+sub2+'\n'+sub3+'\n';
    return 0;
}