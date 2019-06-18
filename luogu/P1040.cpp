#include <iostream>
#include <stack>

using namespace std;

int main() {
    // init source data.
    int n;
    cin>>n;
    int score[n];
    for (int i = 0; i < n; i++) {
        cin>>score[i];
    }

    // cal the data
    /*
     * 使用动态规划来解决这个问题
     */
    long int data[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            data[i][j] = 0;
        }
    }
    int root[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
             data[i][j] = score[i];
             cout<<"data["<<i<<"]["<<j<<"] = "<<data[i][j]<<endl;
             for (int k = i; k <= j; k++) {
                if (k == i && k < j && data[i][j] < (score[k] + data[k + 1][j])) {
                    root[i][j] = k;
                    data[i][j] = score[i] + data[k + 1][j];
                } else if(k > i && k < j && data[i][j] < (score[k] + data[i][k - 1] * data[k + 1][j])) {
                    root[i][j] = k;
                    data[i][j] = score[k] + data[i][k - 1] * data[k + 1][j];
                } else if (k > i && k == j && data[i][j] < (score[k] + data[i][k - 1])) {
                    root[i][j] = k;
                    data[i][j] = score[k] + data[i][k - 1];
                } else if (i == j && data[i][j] < score[k]) {
                    root[i][j] = k;
                    data[i][j] = score[k];
                }
             }
        }
    }
    cout<<data[0][n - 1]<<endl;


    return 0;
}
