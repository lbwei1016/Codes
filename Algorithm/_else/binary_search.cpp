#include <iostream>
#include <algorithm>

using namespace std;

int arr[5] = {2, 5, 1, 9, 4}; //1, 2, 4, 5, 9
int n = 5;

void binary_search(int x)
{
    int lb = -1, ub = n; //(lb, ub] : 若 x 大於最大元素，則答案為 n，因此範圍是前開後閉

    //在解答範圍大於 1 的期間反覆執行
    while((ub-lb) > 1)
    {
        int mid = (ub+lb) / 2;

        //lower_bound
        //若為 "arr[k] > x" 則為 "upper_bound"(因為不包含相等)
        if(arr[mid] >= x)
            ub = mid;
        else 
            lb = mid;
    }
    //此時 lb+1 = ub
    //因為要找的是 arr[k] >= x，所以選ub
    cout << ub << '\n';
}

int main()
{
    int x; //number to find
    cin >> x; 
    sort(arr, arr+5);
    binary_search(x);
    return 0;
}