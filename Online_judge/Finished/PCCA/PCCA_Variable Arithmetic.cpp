/*
***String***
    Description:
        Two operations: Assignment and Addition.
        Assignment is to assign an integer to a string: 
            [string] = [int]
        Addition is to add several strings or/and integers together, and string 
        should be substituted by assigned integer if was once assigned.
        Finally, print the result with the format:
            [sum of value] + [str1] [str2] + .... 
    Solution:
        Read once a char, not a line; be careful when evaluating the ending situation
        (a single "0").
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

int readnum(char &c) {
    int num = c-'0';
    while(1) {
        c = getchar();
        if(c==' ' || c=='\n') break;
        num *= 10; num += c-'0';
    }
    return num;
}
void readstring(char s[], char &c) {
    for(int i=0; i<20; ++i) s[0] = '\0';
    s[0] = c;
    for(int i=1; ; ++i) {
        c = getchar();
        if(c==' ' || c=='\n') break;
        s[i] = c;
    }
}
int main() {
    char c;
    int sum = 0;
    //string buffer; in map, I use "std::string", for "map<char *, int>" stores a pointer and is not convenient
    char s[20]; 
    bool all_num = true, assign = false, has_pre = false;
    vector<string> ss; // strore all non-substituted strings and print them together later
    memset(s, 0, sizeof(s));
    while(1) {
        c = getchar();
        if(c == '0') {
            c = getchar();
            // ending
            if(!has_pre && c=='\n') break;
        }
        if(c == ' ') continue;
        has_pre = true;
        if('0'<=c && c<='9') {
            sum += readnum(c);
        }
        else if('a'<=c && c<='z') {
            memset(s, 0, sizeof(s)); // remember to clear the buffer
            readstring(s, c);
            if(!mp.count(s)) {
                ss.push_back(string(s));
                all_num = false;
            }
            else {
                sum += mp[s];
            }
        }
        else if(c == '=') {
            c = getchar(); //eat ' '
            c = '0';
            int num = readnum(c);
            string tmp = s;
            // there are probably multiple updates
            if(!mp.count(tmp))
                mp.emplace(tmp, num);
            else mp[tmp] = num;
            assign = true;
        }
        if(c == '\n') {
            if(!assign) {
                if(all_num) {
                    printf("%d\n", sum);
                }
                else {
                    if(sum != 0) printf("%d + ", sum);
                    for(int i=0, len=ss.size(); i<len-1; ++i) {
                        cout << ss[i] + " + ";
                    }
                    cout << ss.back() + '\n';
                }
            }
            all_num = true;
            assign = has_pre = false;
            ss.clear();
            sum = 0;
            memset(s, 0, sizeof(s));
        }
    }
    return 0;
}