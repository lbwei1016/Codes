#include <iostream>
#include <string>
#include <sstream> //for stringstream

using namespace std;

int main()
{
    stringstream ss;
    string s1, s2;
    int n1, n2;
    getline(cin, s1);

    ss << s1;
    ss >> n1;
    cout << "string is converted to integer:" << n1 << '\n';

    //clear out for the other input
    ss.str("");
    ss.clear();
    
    getline(cin, s2);
    ss << s2;
    ss >> n2;
    cout << "string is converted to integer:" << n2 << '\n';
    ss.str("");
    ss.clear();

    //continue extracting strings from stringstream until EOF
    string s3;
    getline(cin, s3);
    for(ss << s3; !ss.eof();) {
        int num;
        ss >> num;
        cout << num << ' ';
    }
    cout << '\n';

    return 0;
}