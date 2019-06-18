#include <iostream>
#include <queue>

using namespace std;

#define point pair<int, int>
int n, m, sourceX, sourceY;
const int MAX = 400;
int data[MAX][MAX];
queue<point> pointQueue;

void checkPoint(int row, int col, point cur) {
    if (row >= 0 && row < n && col >= 0 && col < m && data[row][col] == -1) {
        data[row][col] = data[cur.first][cur.second] + 1;
        point tmp(row, col);
        pointQueue.push(tmp);
    }
}

void dfs() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            data[i][j] = -1;
        }
    }

    point source(sourceX, sourceY);
    pointQueue.push(source);
    data[sourceX][sourceY] = 0;
    while (!pointQueue.empty()) {
        point cur = pointQueue.front();
        checkPoint(cur.first - 2, cur.second - 1, cur);
        checkPoint(cur.first - 2, cur.second + 1, cur);
        checkPoint(cur.first - 1, cur.second + 2, cur);
        checkPoint(cur.first + 1, cur.second + 2, cur);
        checkPoint(cur.first + 2, cur.second + 1, cur);
        checkPoint(cur.first + 2, cur.second - 1, cur);
        checkPoint(cur.first + 1, cur.second - 2, cur);
        checkPoint(cur.first - 1, cur.second - 2, cur);
        pointQueue.pop();
    }
}

void printDfs() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<data[i][j];
            if (j != m - 1) {
                if (data[i][j] == -1) {
                    cout<<"   ";
                } else if (data[i][j] < 10) {
                    cout<<"    ";
                } else if (data[i][j] < 100) {
                    cout<<"   ";
                } else {
                    cout<<"  ";
                }
            }
        }
        cout<<endl;
    }
}

int main() {
    cin>>n>>m>>sourceX>>sourceY;
    sourceX--;
    sourceY--;
    dfs();
    printDfs();

    return 0;
}
