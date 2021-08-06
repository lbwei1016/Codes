/*
    為何要由右往左遍歷?如下:
        設測資: -1-9
        若由左往右遍歷，過程: 
            1. 0 - right
            2. 1 - 9 = -8 = right
            3. 0 - (-8) = 8 #
        此答案是錯的!!!(因為負號的問題)；
        若由右往左，過程:
            1. left - 9
            2. 0 - 1 = -1 = left
            3. -1 - 9 = -10 #
        正確!!!避免了負號問題

    結論: 由「右」往「左」，才正確!!!
*/
#include <iostream>
#include <cctype>

using namespace std;

int DFS(int, int); // left, right
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    while(getline(cin, s))
    {
        int ans = DFS(0, s.size()-1);
        cout << ans << '\n';
    } 
    return 0;
}
int DFS(int left, int right) //由右往左遞迴!!!!!重要!!!!!!
{
    int par = 0; //代表是否在括號內(0代表不在)
    //遞迴當中先呼叫加減，再呼叫乘除，因此乘除會優先被執行(Stack: FILO)
    for(int i=right; i>=left; i--)
    {
        if(s[i] == ')') par++; //因為由右往左遞迴，所以先遇到右括號；par++代表正在括號內
        if(s[i] == '(') par--; // par--使par=0，代表括號部分結束
        if(s[i] == '+' && par == 0)
            return DFS(left, i-1) + DFS(i+1, right); 
        if(s[i] == '-' && par == 0)
            return DFS(left, i-1) - DFS(i+1, right);
    }
    for(int i=right; i>=left; i--)
    {
        if(s[i] == ')') par++; //因為由右往左遞迴，所以先遇到右括號；par++代表正在括號內
        if(s[i] == '(') par--; // par--使par=0，代表括號部分結束
        if(s[i] == '*' && par == 0)
            return DFS(left, i-1) * DFS(i+1, right);
        if(s[i] == '/' && par == 0)
            return DFS(left, i-1) / DFS(i+1, right);
        if(s[i] == '%' && par == 0)
            return DFS(left, i-1) % DFS(i+1, right);
    }

    if(s[left] == '(' && s[right] == ')') return DFS(left+1, right-1); //去除括號
    if(s[left] == ' ' && s[right] == ' ') return DFS(left+1, right); //去除左右空格
    if(s[left] == ' ') return DFS(left+1, right); //去除左空格
    if(s[right] == ' ') return DFS(left, right-1); //去除右空格

    int num = 0;
    if(isdigit(s[left]) && isdigit(s[right])) //字元轉數字
    {
        for(int i=left; i<=right; i++)
            num  = num*10 + s[i]-'0';
        return num;
    }
}
