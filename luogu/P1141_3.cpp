#include <iostream>
#include <queue>

using namespace std;

const int MAXROW = 1000;
char matrix[MAXROW][MAXROW];
int flag[MAXROW][MAXROW];
int n, m;


bool checkDirec(int row, int col, pair<int, int> parent) {
    if (row >= 0 && row < n && col >= 0 && col < n && flag[row][col] == 0 && matrix[row][col] != matrix[parent.first][parent.second]) {
        //cout<<"push "<<row<<", "<<col<<endl;
        return true;
    }
    return false;
}

// 广度优先搜索比较适合解决该问题
int dfs(int row, int col) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            flag[i][j] = 0;
        }
    }
    flag[row][col] = 1;

    int length = 1;
    pair<int, int> tmpPair(row, col);
    queue< pair<int, int> > queue;
    queue.push(tmpPair);
    while (!queue.empty()) {
        pair<int, int> topPair = queue.front();
        if (checkDirec(topPair.first - 1, topPair.second, topPair)) {
            flag[topPair.first - 1][topPair.second] = 1;
            tmpPair.first = topPair.first - 1;
            tmpPair.second = topPair.second;
            queue.push(tmpPair);
            length++;
        }
        if (checkDirec(topPair.first, topPair.second + 1, topPair)) {
            flag[topPair.first][topPair.second + 1] = 1;
            tmpPair.first = topPair.first;
            tmpPair.second = topPair.second + 1;
            queue.push(tmpPair);
            length++;
        }
        if (checkDirec(topPair.first + 1, topPair.second, topPair)) {
            flag[topPair.first + 1][topPair.second] = 1;
            tmpPair.first = topPair.first + 1;
            tmpPair.second = topPair.second;
            queue.push(tmpPair);
            length++;
        }
        if (checkDirec(topPair.first, topPair.second - 1, topPair)) {
            flag[topPair.first][topPair.second - 1] = 1;
            tmpPair.first = topPair.first;
            tmpPair.second = topPair.second - 1;
            queue.push(tmpPair);
            length++;
        }
        queue.pop();
    }

    return length;
}

int main() {
    // init source data
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        for (int col = 0; col < n; col++) {
            cin>>matrix[i][col];
        }
    }
    int a, b, length[m];
    pair<int, int> ques[m];
    for (int i = 0; i < m; i++) {
        cin>>a>>b;
        pair<int, int> tmpPair;
        tmpPair.first = a - 1;
        tmpPair.second = b - 1;
        ques[i] = tmpPair;
        length[i] = -1;
    }

    /*
     * 这里有一个可以优化的地方, A -> B, 意味着B->A
     */

    for (int i = 0; i < m; i++) {
        if (length[i] == -1) {
            length[i] = dfs(ques[i].first, ques[i].second);
            for (int j = i + 1; j < m; j++) {
                if (flag[ques[j].first][ques[j].second] == 1) {
                    length[j] = length[i];
                }
            }
        }
        cout<<length[i]<<endl;
    }

    return 0;
}
