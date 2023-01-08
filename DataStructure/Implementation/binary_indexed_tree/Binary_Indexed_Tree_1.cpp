/*
***Binary Indexed Tree (BIT) -- 又稱樹狀數組、Fenwick Tree***
    Description:
        比線段數更簡便的求取區間和的資料結構（藉由前綴和相減）；所能進行的操作：
            1. 建構 O(n logn) 或 O(n)
            2. (單點)增加／修改數值 O(log n) (區間修改見BIT_2)
            3. 計算前綴和 O(log n)
        空間複雜度: O(n)
*/
#include <iostream>
#include <cstring>

using namespace std;

int bit[100+1], n;
int arr[100+1];

//(單點)增加／修改數值(O(log n))，同時用來建構(O(n logn))BIT
void add(int i, int x)
{
    while (i <= n)
    {
        bit[i] += x;
        i += i & -i;
    }
}
//計算[1, i]的前綴和(O(log n))
int sum(int i)
{
    int s = 0;
    while (i > 0)
    {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}
//另一個較快的建構方法(O(n))
void build()
{
    memcpy(bit+1, arr, n*sizeof(int));

    for(int i=1; i<=n; i++)
    {
        //j 是 i(或i父節點)的右兄弟節點
        int j = i + (i & -i); 
        if(j > n) break;
        bit[j] += bit[i];
    }
}

int main()
{
    n = 5;
    for(int i=0; i<n; i++)
        arr[i] = i+1;

    // for (int i=1; i<=n; i++)
    //     add(i, arr[i-1]);
    build();

    for(int i=1; i<=n; i++)
        cout << bit[i] << ' ';
    cout << '\n';
    for(int i=1; i<=n; i++)
        cout << sum(i) << ' ';
    return 0;
}