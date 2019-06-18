#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

void resAdd(int res[], int n) {
    bool add = true;
    for (int i = 0; i < n; i++) {
        if (add) {
            if (res[i] == 0) {
                res[i] = 1;
                add = false;
            } else {
                res[i] = 0;
                add = true;
            }
        } else {
            break;
        }
    }
}

int charToInt(char c) {
    return c - 'A';
}

void swapArray(int a[], int b[], int n) {
    int tmp;
    for (int i = 0; i < n; i++) {
        tmp = a[i];
        a[i] = b[i];
        b[i] = tmp;
    }
}

int gcd(int a, int b) {
    int tmp;
    while (b) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

bool guass(char first[], char second[], char sum[], int n) {
    int a[n][n] = { 0 };
    int b[n];
    int c[n][n];// 表示当前进位的影响数组
    // 构建矩阵
    for (int row = 0; row < n; row++) {
        int firstIndex = charToInt(first[n - 1 - row]);
        int secondIndex = charToInt(second[n - 1 - row]);
        int sumIndex = charToInt(sum[n - 1 - row]);
        a[row][firstIndex]++;
        a[row][secondIndex]++;
        a[row][sumIndex]--;
        for (int column = 0; column < n; column++) {
            cout<<a[row][column]<<" ";
        }
        c[row][row] = n;
        if (row > 0) {
            c[row][row - 1] = -1;
        }
        cout<<endl;
    }
    cout<<endl;
    // 矩阵可能会出现 a[i][i] == 0, 交换一下
    int row, col;
    for (row = col = 0; row < n && col < n; row++, col++) {
        int maxp = row;
        for (int i = row + 1; i < n; i++) {
            if (abs(a[i][col]) > abs(a[maxp][col])) {
                maxp = i;
            }
        }
        if (maxp != row) {
            swapArray(a[row], a[maxp], n);
            swapArray(c[row], c[maxp], n);
        }
        for (int i = 0; i < n; i++) {
            if (i != row && a[i][col]) {
                int res = a[i][col] * a[row][col] / gcd(a[i][col], a[row][col]);
                int t1 = res / a[i][col];
                int t2 = res / a[row][col];
                for (int j = 0; j < n; j++) {
                    a[i][j] = a[i][j] * t1 - a[row][j] * t2;
                    g[i][j] = g[i][j] * t1 - g[row][j] * t2;
                }
            }
        }
    }
    return true;
}

int main() {
    // init source data
    int n;
    cin>>n;
    int res[n];
    char first[n];
    char second[n];
    char sum[n];
    for (int i = 0; i < n; i++) {
        cin>>first[i];
    }
    for (int j = 0; j < n; j++) {
        cin>>second[j];
    }
    for (int k = 0; k < n; k++) {
        cin>>sum[k];
    }
    
    // cal the data
    int data[n][n];
    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }
    guass(first, second, sum, n);
    //for (int i = 0; i < pow(2, n); i++) {
    //    if (guass) {
    //       break;
    //    }
    //    resAdd(res, n);
    //}
}
