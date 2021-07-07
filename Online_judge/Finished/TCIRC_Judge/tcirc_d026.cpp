/*
***Stack*** -- char mapping
*/
#include <bits/stdc++.h>
using namespace std;

char table[7] = "([{)]}";
char in[200];

int main() {
    while(scanf("%s", in) != EOF) {
        stack<char> S;
        int len = strlen(in);
        bool yes = true;
        for(int i=0; i<len; i++) {
            int p = strchr(table, in[i]) - table;
            if(p > 2) {
                char ch = S.top(); S.pop();
                int q = strchr(table, ch) - table;
                if(q != p-3) {
                    yes = false;
                    break;
                }
            } else {
                S.push(in[i]);
            }
        }
        if(!S.empty()) yes = false;

        if(yes) printf("yes\n");
        else printf("no\n");
    }
    
    return 0;
}