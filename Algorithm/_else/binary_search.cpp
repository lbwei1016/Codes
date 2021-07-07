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

/* Sol II: jumping binary search */
int arr[100]; //sorted array

//search for "x"
int jump_search(int x) {
    //因 arr[0] 在之後不被檢查，所以先檢查
    if(arr[0] >= x) return 0;
    int p0 = 0;
    for(int jump=n/2; jump>0; jump/=2) {
        while(p0+jump<n && arr[p0+jump]<x) p0 += jump;
    }
    //arr[p0+1] >= x
    return p0+1;
}

int main()
{
    int x; //number to find
    cin >> x; 
    sort(arr, arr+5);
    binary_search(x);
    return 0;
}