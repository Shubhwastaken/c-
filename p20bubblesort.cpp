#include <iostream>
using namespace std;

int main() {
    int n;
    
    cout << "Enter the size of the array: ";
    cin >> n;
    int array[n];

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    for(int i = 0;i<n-1;i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        
    }

    for (int i = 0; i < n; i++) {
        cout << array[i] << endl;
    }

    return 0;
}