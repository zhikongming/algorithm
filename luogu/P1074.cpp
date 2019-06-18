#include <iostream>
#include <queue>

using namespace std;

#define point pair<int, int>
const int n = 9;
int data[n][n];
int tem[n][n];
int maxScore = 0;
int path[3][3][9];// 小九宫格的数字
int myrow[n][n];
int mycol[n][n];
point myStack[n * n];
int unFillCount;
queue<point> que[n];


// 这里可以优化一下, 用数组把结果存储下来
bool checkNumberValid(int row, int col, int val) {
    // 检查行列是否重复
    if (myrow[row][val-1] == 1 || mycol[col][val-1] == 1) {
        return false;
    }
    // 检查小九宫格数字是否重复
    int r = row / 3;
    int c = col / 3;
    if (path[r][c][val-1] == 1) {
        return false;
    }
    return true;
}

void initTem() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0 || n - i == 1 || n - j == 1) {
                tem[i][j] = 6;
            } else if (i == 1 || j == 1 || n - i == 2 || n - j == 2) {
                tem[i][j] = 7;
            } else if (i == 2 || j == 2 || n - i == 3 || n - j == 3) {
                tem[i][j] = 8;
            } else if (i == 3 || j == 3 || n - i == 4 || n - j == 4) {
                tem[i][j] = 9;
            } else if (i == 4 || j == 4 || n - i == 5 || n - j == 5) {
                tem[i][j] = 10;
            }
        }
    }
}

void addLittle(int row, int col) {
    int r = row / 3;
    int c = col / 3;
    path[r][c][data[row][col]-1] = 1;
    myrow[row][data[row][col]-1] = 1;
    mycol[col][data[row][col]-1] = 1;
}

void rmLittle(int row, int col) {
    int r = row / 3;
    int c = col / 3;
    path[r][c][data[row][col]-1] = 0;
    myrow[row][data[row][col]-1] = 0;
    mycol[col][data[row][col]-1] = 0;
}

int getScore() {
    int score = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            score += tem[i][j] * data[i][j];
        }
    }
    return score;
}

void dfs(int in) {
    int row = myStack[in].first;
    int col = myStack[in].second;
    if (in == unFillCount) {
        /*for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout<<data[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;*/
        int score = getScore();
        //cout<<"score = "<<score<<endl;
        if (score > maxScore) {
            maxScore = score;
        }
    } else {
        if (data[row][col] == 0) {
            for (int i = 1; i <= 9; i++) {
                if (checkNumberValid(row, col, i)) {
                    data[row][col] = i;
                    //cout<<"("<<row<<", "<<col<<") = "<<i<<endl;
                    addLittle(row, col);
                    dfs(in+1);
                    rmLittle(row, col);
                    data[row][col] = 0;
                }
            }
        }
    }
}

int main() {
    // init source data.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>data[i][j];
            myrow[i][j] = 0;
            mycol[i][j] = 0;
            if (data[i][j] == 0) {
                unFillCount++;
            }
        }
    }
    //cout<<"unFillCount = "<<unFillCount<<endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 9; k++) {
                path[i][j][k] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (data[i][j] != 0) {
                addLittle(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num = 0;
            for (int k = 1; k <= 9; k++) {
                int r = i / 3;
                int c = j / 3;
                //if (i == 4 && j == 0) {
                //    cout<<"data[i][j] = "<<data[i][j]<<endl;
                //    cout<<"path[r][c][k-1] = "<<path[r][c][k-1]<<endl;
                //    cout<<"myrow[i][k-1] = "<<myrow[i][k-1]<<endl;
                //    cout<<"mycol[j][k-1] = "<<mycol[j][k-1]<<endl;
                //}
                if (data[i][j] == 0 && path[r][c][k-1] == 0 && myrow[i][k-1] == 0 && mycol[j][k-1] == 0) {
                    num++;
                }
            }
            if (data[i][j] == 0) {
                point s(i, j);
                que[num-1].push(s);
            }
        }
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        while (!que[i].empty()) {
            myStack[index] = que[i].front();
            //cout<<"("<<myStack[index].first<<", "<<myStack[index].second<<") = "<<i<<endl;
            que[i].pop();
            index++;
        }
    }
    //cout<<"--------------"<<index<<"--------------"<<endl;

    initTem();
    // dfs 计算所有的数独, 然后计算总和, 求出最大的一个
    // 时间复杂度太高了, 打算参考一下洛谷大神的思路, 对可选的顺序做一个排序.
    index = 0;
    dfs(index);
    if (maxScore == 0) {
        cout<<-1<<endl;
    } else {
        cout<<maxScore<<endl;
    }
    return 0;
}
