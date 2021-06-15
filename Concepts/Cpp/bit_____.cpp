#include <iostream>

using namespace std;


void bit(int n, int k)
{
    int comb = (1 << k) - 1;
    while(comb < 1 << n)
    {
        int x = comb & -comb, //取出最低位元的 1
            y = comb + x;
        comb = ((comb & ~y)/x >> 1) | y;
        if(comb > 1 << n)
            break;
        cout << comb << '\n';
    }
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