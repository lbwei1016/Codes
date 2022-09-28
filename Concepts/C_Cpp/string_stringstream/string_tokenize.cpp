#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> strtok(string s, string delim) {
    s += delim; // for consistency of the following loop
    vector<string> slice;
    int pos = 0;
    while((pos = s.find(delim)) != string::npos) {
        slice.push_back(s.substr(0, pos));
        s.erase(0, pos + delim.size());
    }
    return slice;
}

int main() {
    string s = "abc def ghi";
    string delim = " ";

    vector<string> slice = strtok(s, delim);
    for (auto x: slice) cout << x + '\n';
    return 0;
}