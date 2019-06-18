#include <iostream>
#include <stack>

using namespace std;

const int MAXINDEX = 30;
int data[MAXINDEX][MAXINDEX];
int path[MAXINDEX][MAXINDEX];
int n;

bool check_dir(int row, int col, pair<int, int> parent) {
    if (row >= 0 && row < n && col >= 0 && col < n && data[row][col] == 1 && path[row][col] == 0) {
        path[row][col] = 1;
        //cout<<"push "<<row<<", "<<col<<endl;
        return true;
    }
    return false;
}

void print_pic() {
    pair<int, int> row_index[n];
    pair<int, int> col_index[n];
    for (int i = 0; i < n; i++) {
        int row_start = -1;
        int row_end = -1;
        int col_start = -1;
        int col_end = -1;
        for (int j = 0; j < n; j++) {
            if (path[i][j] == 1) {
                if (row_start == -1) {
                    row_start = j;
                }
                if (j > row_end) {
                    row_end = j;
                }
            }
            if (path[j][i] == 1) {
                if (col_start == -1) {
                    col_start = j;
                }
                if (j > col_end) {
                    col_end = j;
                }
            }
        }
        pair<int, int> row_tmp(row_start, row_end);
        row_index[i] = row_tmp;
        pair<int, int> col_tmp(col_start, col_end);
        col_index[i] = col_tmp;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pair<int, int> row_tmp = row_index[i];
            pair<int, int> col_tmp = col_index[j];
            if (data[i][j] == 0 && i >= col_tmp.first && i <= col_tmp.second && j >= row_tmp.first && j <= row_tmp.second) {
                data[i][j] = 2;
            }
            cout<<data[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool bfs(int row, int col) {
    int direc[n][n]; // 记录节点当前的走向, 上下左右
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            path[i][j] = 0;
            direc[i][j] = 0;
        }
    }
    pair<int, int> source(row, col);
    stack< pair<int, int> > stack;
    stack.push(source);

    bool founded = false;
    int count = 1; // 一个圈里面至少需要四个点
    while(!stack.empty()) {
        pair<int, int> pointer = stack.top();
        //cout<<"search "<<pointer.first<<", "<<pointer.second<<endl;
        if (pointer.first == row && pointer.second == col && count >= 4) {
            founded = true;
            break;
        }
        // check top
        if (direc[pointer.first][pointer.second] == 0) {
            direc[pointer.first][pointer.second] = 1;
            //cout<<"check top"<<endl;
            if (check_dir(pointer.first - 1, pointer.second, pointer)) {
                pair<int, int> tmp(pointer.first - 1, pointer.second);
                stack.push(tmp);
                count++;
                continue;
            }
        }
        // check right
        if (direc[pointer.first][pointer.second] == 1) {
            direc[pointer.first][pointer.second] = 2;
            //cout<<"check right"<<endl;
            if (check_dir(pointer.first, pointer.second + 1, pointer)) {
                pair<int, int> tmp(pointer.first, pointer.second + 1);
                stack.push(tmp);
                count++;
                continue;
            }
        }
        // check bottom
        if (direc[pointer.first][pointer.second] == 2) {
            direc[pointer.first][pointer.second] = 3;
            if (check_dir(pointer.first + 1, pointer.second, pointer)) {
                pair<int, int> tmp(pointer.first + 1, pointer.second);
                stack.push(tmp);
                count++;
                continue;
            }
        }
        // check left
        if (direc[pointer.first][pointer.second] == 3) {
            direc[pointer.first][pointer.second] = 4;
            if (check_dir(pointer.first, pointer.second - 1, pointer)) {
                pair<int, int> tmp(pointer.first, pointer.second - 1);
                stack.push(tmp);
                count++;
                continue;
            }
        }
        // can not add at all.
        stack.pop();
        count--;
        path[pointer.first][pointer.second] = 0;
    }

    if (founded) {
        print_pic();
        return true;
    }
    return false;
}

int main() {
    // init source data
    cin>>n;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cin>>data[row][col];
        }
    }

    // 找到闭合圈中的一个点
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (data[row][col] == 1 && bfs(row, col)) {
                return 0;
            }
        }
    }
    
    return 0;
}
