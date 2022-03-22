#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int len) {
    for (int i=1; i<len; ++i) {
        int at = arr[i], j;
        for (j=i-1; j>=0; --j) {
            if (arr[j] > at) 
                arr[j+1] = arr[j];
            else break;
        }
        arr[j+1] = at;
    }
}

int main() {
    int arr[] = {3, 2, 4, 1, 5};    
    insertion_sort(arr, 5);
    for (int i=0; i<5; ++i) 
        cout << arr[i] << ' ';
    return 0;
}