#include <iostream>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
// #pragma message("Hi")

// _Pragma (string literal) = #pragma string literal
/*
    利用 _Pragma 就可以在 preprocessor 期間指定 _Pragma 的參數，因為 _Pragma 不是
    "directive" 而是 "operator"。(directive cannot generate another directive)
*/
#define SAY_HI(X) _Pragma (#X)
#ifdef SAY_HI
SAY_HI(message("Hi"));
#endif
using namespace std;

int main() {
    SAY_HI(message("Hi"));
    return 0;
}