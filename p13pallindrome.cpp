#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    char arr[n + 1];
    cin >> arr;

    bool isPalindrome = true;
    for (int i = 0; i < n ; i++) {
        if (arr[i] != arr[n - i - 1]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not a Palindrome" << endl;
    }

    return 0;
}