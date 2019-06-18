#include <iostream>
#include <stdlib.h>

using namespace std;

/*
 * 八皇后的问题解题思路:
 * 1. 行号和列号不能重复
 * 2. 两个点的行号和列号差的绝对值不等
 */

bool checkMatch(int arr[], int row, int column) {
    for (int i = 0; i < row; i++) {
        if (arr[i] == column || abs(i - row) == abs(arr[i] - column)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, count = 0;
    cin>>n;
    int arr[n];
    int row = 0;
    for (int k = 0; k < n; k++) {
        arr[k] = -1;
    }
    for (int i = 0; i < n; i++) {
        bool isMatch = false;
        for (int j = arr[i] + 1; j < n; j++) {
            if (checkMatch(arr, i, j)) {
                arr[i] = j;
                isMatch = true;
                break;
            }
        }
        if (!isMatch) {
            arr[i] = -1;
            i -= 2;
            continue;
        }
        if (i < 0) {
            break;
        }
        if (i == n - 1) {
            count++;
            i--;
            if (row < 3)
            for (int k = 0; k < n; k++) {
                if (k != n - 1) {
                    cout<<arr[k] + 1<<" ";
                } else {
                    cout<<arr[k] + 1<<endl;
                }
            }
            row++;
        }
    }
    cout<<count<<endl;
}
