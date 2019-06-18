#include <iostream>

using namespace std;

int used[10005] = {0};
int check[10005] = {0};

int main() {
    int N, M;
    cin>>N>>M;
    int originNums[N];
    for (int i = 0; i < N; i++) {
        cin>>originNums[i];
        used[originNums[i]] = 1;
        int x = originNums[i];
        for (int j = 1; j < originNums[i]; j++) {
            x -= used[j];
        }
        originNums[i] = x - 1;
    }

    // add M
    originNums[N - 1] += M;
    for (int i = N - 1; i >= 0; i--) {
        // 计算进几位
        originNums[i - 1] += originNums[i] / (N - i);
        originNums[i] = originNums[i] % (N - i);
    }

    // generate the data
    for (int i = 0; i < N; i++) {
        int tmp = -1;
        int m = 1;
        while (tmp < originNums[i]) {
            if (check[m] == 0) {
                tmp++;
            }
            m++;
        }
        m--;
        check[m] = 1;
        cout<<m<<" ";
    }

    return 0;
}
