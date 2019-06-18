#include <iostream>
#include <stack>

using namespace std;

const int MAXROW = 1000;
char matrix[MAXROW][MAXROW];
int flag[MAXROW][MAXROW];
bool used[MAXROW][MAXROW];
int n, m;


bool checkDirec(int row, int col, pair<int, int> parent) {
    if (row >= 0 && row < n && col >= 0 && col < n && used[row][col] == false && matrix[row][col] != matrix[parent.first][parent.second]) {
        //cout<<"push "<<row<<", "<<col<<endl;
        used[row][col] = true;
        return true;
    }
    return false;
}

// 深度优先搜索比较适合解决该问题
void dfs(int row, int col) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            flag[i][j] = 0;
            used[i][j] = false;
        }
    }

    int length = 0, maxLenght = 0;
    stack< pair<int, int> > stack;
    pair<int, int> tmpPair(row, col);
    stack.push(tmpPair);
    //cout<<"now "<<row<<", "<<col<<endl;

    while (!stack.empty()) {
        pair<int, int> topPair = stack.top();
        // check top
        if (flag[topPair.first][topPair.second] == 0) {
            flag[topPair.first][topPair.second] = 1;
            if (checkDirec(topPair.first - 1, topPair.second, topPair)) {
                tmpPair.first = topPair.first - 1;
                tmpPair.second = topPair.second;
                stack.push(tmpPair);
                length++;
                continue;
            }
        }
        // checl right
        if (flag[topPair.first][topPair.second] == 1) {
            flag[topPair.first][topPair.second] = 2;
            if (checkDirec(topPair.first, topPair.second + 1, topPair)) {
                tmpPair.first = topPair.first;
                tmpPair.second = topPair.second + 1;
                stack.push(tmpPair);
                length++;
                continue;
            }
        }
        // checl bottom
        if (flag[topPair.first][topPair.second] == 2) {
            flag[topPair.first][topPair.second] = 3;
            if (checkDirec(topPair.first + 1, topPair.second, topPair)) {
                tmpPair.first = topPair.first + 1;
                tmpPair.second = topPair.second;
                stack.push(tmpPair);
                length++;
                continue;
            }
        }
        // checl right
        if (flag[topPair.first][topPair.second] == 3) {
            flag[topPair.first][topPair.second] = 4;
            if (checkDirec(topPair.first, topPair.second - 1, topPair)) {
                tmpPair.first = topPair.first;
                tmpPair.second = topPair.second - 1;
                stack.push(tmpPair);
                length++;
                continue;
            }
        }

        stack.pop();
        //cout<<"pop "<<topPair.first<<", "<<topPair.second<<endl;
        flag[topPair.first][topPair.second] = 0;
    }

    cout<<maxLenght<<endl;
}

int main() {
    // init source data
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        for (int col = 0; col < n; col++) {
            cin>>matrix[i][col];
        }
    }
    int a, b;
    pair<int, int> ques[m];
    for (int i = 0; i < m; i++) {
        cin>>a>>b;
        pair<int, int> tmpPair;
        tmpPair.first = a - 1;
        tmpPair.second = b - 1;
        ques[i] = tmpPair;
    }
    for (int i = 0; i < m; i++) {
        dfs(ques[i].first, ques[i].second);
    }

    return 0;
}
