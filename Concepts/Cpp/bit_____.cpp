#include <iostream>
using namespace std;

void print(int comb, int n) {
    for(int i=n-1; i>=0; --i) {
        if(comb & (1<<i)) cout << '1';
        else cout << '0';
    }
    cout << '\n';
}
// 列舉長度為 n 中有 k 個 1 的子集合
void bit(int n, int k)
{
    int comb = (1 << k) - 1, cnt = 1;
    print(comb, n);
    while(comb < 1 << n)
    {
        int x = comb & -comb, //取出最低位元的 1
            y = comb + x;
        comb = (((comb & ~y)/x) >> 1) | y;

        if(comb >= 1 << n)
            break;
        print(comb, n);
        ++cnt;
    }
    cout << cnt << '\n';
}
void bit_2(int sup)
{
    int sub = sup;
    do
    {
        cout << sub << '\n';
        sub = (sub - 1) & sup;
    } while (sub != sup);
 }
int main()
{
    cout << "Input n and k\n";
    int n, k;
    cin >> n >> k;
    bit(n, k);
    // int sup;
    // cin >> sup;
    // bit_2(sup);
    // for(int i=0; i < 1<<5; i++)
    // {
    //     cout << i << '\n';
    // }
    return 0;
}