#include <iostream>
#include <algorithm>
using namespace std;

void quick_sort(int arr[], int l, int r) {
    if(l >= r-1) return;
    int pivot = l; // 以左為基準點
    int i = l+1, j = r-1, val = arr[pivot];
    while(i <= j) {
        while(i < j && arr[j] > val) j--; // 由右往左搜尋
        while(i < j && arr[i] < val) i++; // 由左往右搜尋
        if(i == j) {
            swap(arr[i], arr[pivot]);
            pivot = i;
            break;
        }
        else swap(arr[i], arr[j]);
    }
    quick_sort(arr, l, pivot); quick_sort(arr, pivot+1, r);
}
int main() {
    int arr[10] = {9, 5, 1, 4, 7, 2, 3, 6, 8, 0};
    //random_shuffle(arr, arr+10);
    quick_sort(arr, 0, 10);
    for(int v : arr) cout << v << ' ';
    cout << '\n';
    return 0;
}