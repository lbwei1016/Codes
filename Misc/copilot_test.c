#include <stdio.h>

// implement quicksort
void quicksort(int *arr, int start, int end) {
    if (start >= end) return;
    int pivot = arr[start];
    int i = start, j = end;
    while (i < j) {
        while (i < j && arr[j] >= pivot) j--;
        arr[i] = arr[j];
        while (i < j && arr[i] <= pivot) i++;
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    quicksort(arr, start, i - 1);
    quicksort(arr, i + 1, end);
}

// implement mergesort
void mergesort(int *arr, int start, int end) {
    if (start >= end) return;
    int mid = (start + end) / 2;
    mergesort(arr, start, mid);
    mergesort(arr, mid + 1, end);
    int i = start, j = mid + 1, k = 0;
    int *tmp = (int *)malloc(sizeof(int) * (end - start + 1));
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) tmp[k++] = arr[i++];
        else tmp[k++] = arr[j++];
    }
    while (i <= mid) tmp[k++] = arr[i++];
    while (j <= end) tmp[k++] = arr[j++];
    for (i = start, k = 0; i <= end; i++, k++) arr[i] = tmp[k];
    free(tmp);
}


int main() {
    
    return 0;
}