#include <iostream>

using namespace std;

const int MAX = 100;
const int PATHMIN = 0;
int data[MAX][MAX];
int path[MAX][MAX];
int row, col, maxPath = 0;

int getPath(int mrow, int mcol) {
    //cout<<"----------"<<mrow<<", "<<mcol<<"------------"<<endl;
    if (path[mrow][mcol] != PATHMIN) {
        return path[mrow][mcol];
    } else {
        int max = 0;
        int tmp;
        int tmpRow = mrow - 1, tmpCol = mcol;
        if (tmpRow >= 0 && tmpRow < row && tmpCol >= 0 && tmpCol < col && data[mrow][mcol] > data[tmpRow][tmpCol]) {
            tmp = getPath(tmpRow, tmpCol);
            //cout<<tmpRow<<", "<<tmpCol<<" t= "<<tmp<<endl;
            if (tmp > max) {
                max = tmp;
            }
        }
        tmpRow = mrow, tmpCol = mcol + 1;
        if (tmpRow >= 0 && tmpRow < row && tmpCol >= 0 && tmpCol < col && data[mrow][mcol] > data[tmpRow][tmpCol]) {
            tmp = getPath(tmpRow, tmpCol);
            //cout<<tmpRow<<", "<<tmpCol<<" r= "<<tmp<<endl;
            if (tmp > max) {
                max = tmp;
            }
        }
        tmpRow = mrow + 1, tmpCol = mcol;
        if (tmpRow >= 0 && tmpRow < row && tmpCol >= 0 && tmpCol < col && data[mrow][mcol] > data[tmpRow][tmpCol]) {
            tmp = getPath(tmpRow, tmpCol);
            //cout<<tmpRow<<", "<<tmpCol<<" b= "<<tmp<<endl;
            if (tmp > max) {
                max = tmp;
            }
        }
        tmpRow = mrow, tmpCol = mcol - 1;
        if (tmpRow >= 0 && tmpRow < row && tmpCol >= 0 && tmpCol < col && data[mrow][mcol] > data[tmpRow][tmpCol]) {
            tmp = getPath(tmpRow, tmpCol);
            //cout<<tmpRow<<", "<<tmpCol<<" l= "<<tmp<<endl;
            if (tmp > max) {
                max = tmp;
            }
        }
        path[mrow][mcol] = max + 1;
        //cout<<mrow<<", "<<mcol<<" f= "<<path[mrow][mcol]<<endl;
        return path[mrow][mcol];
    }
}

int main() {
    int max = 0, tmp;
    cin>>row>>col;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin>>data[i][j];
            path[i][j] = PATHMIN;
        }
    }
    // 本题解决可以使用动态规划加上深度优先搜索
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            tmp = getPath(i, j);
            if (tmp > max) {
                max = tmp;
            }
        }
    }
    cout<<max<<endl;
    return 0;
}
