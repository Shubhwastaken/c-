#include <iostream>
#include <limits.h>
using namespace std;

void countsort(int *arr, int n, int pos) {
    int freq[10] = {0};

    for (int i = 0; i < n; i++) {
        freq[(arr[i] / pos) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        freq[i] += freq[i - 1];
    }

    int ans[n];
    for (int i = n - 1; i >= 0; i--) {
        ans[--freq[(arr[i] / pos) % 10]] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = ans[i];
    }
}

void radixsort(int *arr, int n) {
    int max_ele = arr[0];
    for (int i = 1; i < n; i++) {
        max_ele = max(arr[i], max_ele);
    }

    for (int pos = 1; max_ele / pos > 0; pos *= 10) {
        countsort(arr, n, pos);
    }
}

int main() {
    int n = 7;
    int arr[] = {870, 62, 2, 353, 84, 41, 199};
    radixsort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}