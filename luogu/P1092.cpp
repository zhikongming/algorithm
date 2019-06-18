#include <iostream>
#include <unistd.h>

using namespace std;

bool checkMatch(char first[], char second[], char sum[], int order[], int n) {
    bool passOne = false;
    for (int i = n - 1; i >= 0; i--) {
        int firstIndex = first[i] - 'A';
        int secondIndex = second[i] - 'A';
        int sumIndex = sum[i] - 'A';
        int tmpSum = order[firstIndex] + order[secondIndex];
        int nowSum = order[sumIndex];
        if (passOne) {
            tmpSum++;
        }
        if (tmpSum >= n) {
            passOne = true;
            tmpSum %= n;
            if (tmpSum != nowSum) {
                return false;
            }
        } else {
            passOne = false;
            if (tmpSum != nowSum) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // init source data.
    int n;
    cin>>n;
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
    int order[n];
    for (int i = 0; i < n; i++) {
        order[i] = i;
    }

    while (true) {
        bool res = checkMatch(first, second, sum, order, n);
        if (res) {
            break;
        }
        for (int i = n - 1; i >= 0; i--) {
            int tmp = n;
            int tmpIndex;
            for (int k = i; k < n; k++) {
                if (order[k] > order[i] && order[k] < tmp) {
                    tmp = order[k];
                    tmpIndex = k;
                }
            }
            if (tmp != n) {
                //sort the next item.
                tmp = order[tmpIndex];
                order[tmpIndex] = order[i];
                order[i] = tmp;
                for (int k = i + 2; k < n; k++) {
                    int t = k;
                    while (t > i + 1 && order[t] < order[t - 1]) {
                        tmp = order[t - 1];
                        order[t - 1] = order[t];
                        order[t] = tmp;
                        t--;
                    }
                }
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout<<order[i]<<" ";
    }
    return 0;
}
