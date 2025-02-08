#include <iostream>
using namespace std;

void merge(int *arr, int sdx, int mid, int edx) {
    int an = mid - sdx + 1;
    int bn = edx - mid;
    int a[an], b[bn];

    for (int i = 0; i < an; i++) {
        a[i] = arr[sdx + i];
    }
    for (int j = 0; j < bn; j++) {
        b[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = sdx;
    while (i < an && j < bn) {
        if (a[i] < b[j]) {
            arr[k++] = a[i++];
        } else {
            arr[k++] = b[j++];
        }
    }
    while (i < an) {
        arr[k++] = a[i++];
    }
    while (j < bn) {
        arr[k++] = b[j++];
    }
}

void mergesort(int *arr, int sdx, int edx) {
    if (sdx < edx) { // Check if subarray size is greater than 1
        int mid = (sdx + edx) / 2;
        mergesort(arr, sdx, mid);
        mergesort(arr, mid + 1, edx);
        merge(arr, sdx, mid, edx);
    }
}

int main() {
    int n = 8;
    int arr[] = {10, 28, 24, 6, 34, 38, 87, 76};
    mergesort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}