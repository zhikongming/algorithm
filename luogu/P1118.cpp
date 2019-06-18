#include <iostream>

using namespace std;

/*
 * 本题解题过程分为两块: 求解各个参数使用的次数, dfs求解参数
 */

int n, sum;
const int MAX = 12;
int times[MAX];
int tmparr[MAX];
int mark[MAX];

void getTimes() {
    // 计算杨辉三角
    int tmp[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                tmp[i][j] = 1;
            } else {
                tmp[i][j] = tmp[i-1][j] + tmp[i-1][j-1];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        times[i] = tmp[n-1][i];
    }
}

bool checkSequence() {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += times[i] * tmparr[i];
    }
    if (s == sum) {
        return true;
    }
    return false;
}

// 这里想做一点优化, 如果当前的序列已经超过了sum, 后面再dfs就没意义了啊
bool checkSum(int k) {
    int s = 0;
    for (int i = 0; i <= k; i++) {
        s += times[i] * tmparr[i];
    }
    if (s > sum) {
        return false;
    }
    return true;
}

bool dfs(int i) {
    if (i < n) {
        for (int j = 0; j < n; j++) {
            if (mark[j] == 0) {
                tmparr[i] = j + 1;
                mark[j] = 1;
                if (!checkSum(i)) {
                    mark[j] = 0;
                    continue;
                }
                bool res = dfs(i+1);
                if (res) {
                    return true;
                }
                mark[j] = 0;
            } 
        }
    } else {
        if (checkSequence()) {
            for (int j = 0; j < n; j++) {
                cout<<tmparr[j]<<" ";
            }
            return true;
        }
    }
    return false;
}

int main() {
    cin>>n>>sum;
    getTimes();
    // try with dfs
    int i = 0;
    for (int j = 0; j < n; j++) {
        mark[j] = 0;
    }
    dfs(i);
    return 0;
}
