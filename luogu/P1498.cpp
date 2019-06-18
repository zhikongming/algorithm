#include <iostream>
#include <math.h>

using namespace std;

int n;

int main() {
    cin>>n;
    int maxRows = pow(2, n);
    int maxCols = 2 * maxRows;
    char res[maxRows][maxCols];
    // init the array
    for (int i = 0; i < maxRows; i++) {
        for (int j = 0; j < maxCols; j++) {
            res[i][j] = ' ';
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            res[0][1] = '/';
            res[0][2] = '\\';
            res[1][0] = '/';
            res[1][1] = '_';
            res[1][2] = '_';
            res[1][3] = '\\';
        } else {
            // generate the graph of i by i-1's
            int nowRows = pow(2, i);
            int nowCols = nowRows * 2;
            for (int row = nowRows / 2; row < nowRows; row++) {
                // copy the graph to next two and rejust the origin graph.
                for (int col = 0; col < nowCols; col++) {
                    int tcol = col % (nowCols / 2);
                    res[row][col] = res[row - nowRows / 2][tcol];
                }

                int moveRow = row - nowRows / 2;
                int moveSteps = nowRows / 2;
                for (int moveCol = nowRows - 1; moveCol >= 0; moveCol--) {
                    res[moveRow][moveCol + moveSteps] = res[moveRow][moveCol];
                    res[moveRow][moveCol] = ' ';
                }
            }
        }
    }

    for (int i = 0; i < maxRows; i++) {
        for (int j = 0; j < maxCols; j++) {
            cout<<res[i][j];
        }
        cout<<endl;
    }
    return 0;
}
