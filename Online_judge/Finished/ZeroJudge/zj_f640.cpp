/*
***Recursion***
*/
#include <bits/stdc++.h>

using namespace std;

int eval() {
    string s;
    cin >> s;
    if(s == "f") {
        int x = eval();
        return 2*x - 3;
    } else if(s == "g") {
        int x = eval(), y = eval();
        return 2*x + y - 7;
    } else if(s == "h") {
        int x = eval(), y = eval(), z = eval();
        return 3*x - 2*y + z;
    } else return stoi(s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << eval() << '\n';
    
    return 0;
}