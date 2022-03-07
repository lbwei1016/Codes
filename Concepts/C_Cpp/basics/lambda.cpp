#include <bits/stdc++.h>
using namespace std;

int main() {
    int x = 1, y = 5;

    // "lambda" is closure type, so declare it with "auto"
    /*
        []("param") -> "type" {}; 
            type 為 return type，若無定義則自動推斷。
            param 為參數。
            [=]：lambda 運算式本體可以取用外部變數。
            [&]：lambda 運算式本體可以參考外部變數。
            [x, y]：以 = 的方式取用外部的 x、y。
            [x, &y]：以 = 取用外部的 x，以 & 的方式參考外部的 y。
            [=, &y]：以 & 的方式參考外部的 y，其餘外部變數取用時都是 = 的方式。
            [&, y]：以 = 的方式參考外部的 y，其餘外部變數以 & 的方式參考。 

        mutable: 可以修改取得自外部的變數
            但若為 [=]，外部變數實際上是複製一份到 lambda 內，因此若要確實修改
            外部變數，必須使用 [&]

        reference:
            https://openhome.cc/Gossip/CppGossip/Lambda.html
    */

    // demo 1:
    auto func = [&]() mutable -> int {
        x *= 2, y*= 2;
        return x + y;
    };
    printf("x was: %d\n", x);
    cout << func() << '\n' << func() << '\n';
    printf("x is: %d\n", x);

    // demo 2:
    vector<int> v = {2, 5, 9, 1, 43, 6, 23};
    sort(v.begin(), v.end(), [](int a, int b) -> bool { return a<b; });
    for(auto x: v) cout << x << ' ';

    // demo 3:
    // call the lambda at once
    int add = [](int a, int b) { return a+b; }(10, 25);
    printf("\n%d\n", add);
    return 0;
}