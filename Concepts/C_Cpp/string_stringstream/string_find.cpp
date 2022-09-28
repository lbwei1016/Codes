/*
***string::find()***
    s.find(const string, from "pos")
    s.find(const char, from "pos")
    s.find(const char*, from "pos", size "n")

    Description:
        Find a string(C or Cpp) of size "n"(C-style) or char, from "pos"
         
    Return:
        The position of the first character of the first match.
        If no matches were found, the function returns string::npos.  

    Note:
        string::npos == -1 (unsigned integral type)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Have a nice day!";
    string to_find;
    cin >> to_find;

    
    int first = s.find(to_find);
    if(first != string::npos) {
        string sub(s.begin()+first, s.begin()+first+to_find.size());
        cout << sub << '\n';
    }
    
    return 0;
}