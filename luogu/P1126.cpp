#include <iostream>
#include <queue>
#include <map>

using namespace std;

#define PointStatus pair< pair<int, int>, char >
int N, M;
const int MAXINDEX = 50;
int matrix[MAXINDEX][MAXINDEX];
int sourceX, soueceY, desX, desY;
char direc;
queue<queue<pair<pair<int, int>,char> > > wholeQueue;
int passedPath[MAXINDEX][MAXINDEX][4];

/*
 * 广度优先搜索来处理该问题比较合适, 每个状态下, 都有五种选择
 * 每个状态都是一个位置, 有坐标的信息和方向
 */

int gitIntByChar(char direc) {
    switch(direc) {
        case 'E': return 0;
        case 'W': return 1;
        case 'N': return 2;
        case 'S': return 3;
    }
}

bool checkPathExist(int row, int col) {
    if (row >= 0 && row < N - 1 && col >=0 && col < M - 1) {
        if (matrix[row][col] == 0 && matrix[row + 1][col] == 0 && matrix[row][col + 1] == 0 && matrix[row + 1][col + 1] == 0) {
            return true;
        }
    }
    return false;
}

bool checkPointPassed(int row, int col, char direc) {
    if (passedPath[row][col][gitIntByChar(direc)] == 1) {
        return true;
    }
    return false;
}

bool checkOperate(PointStatus pointStatus, string operate, queue<pair<pair<int, int>,char> > &nextQueue) {
    pair<int, int> point = pointStatus.first;
    int row = point.first;
    int col = point.second;
    char direc = pointStatus.second;
    bool found = false;
    bool checkStatus = true;
    if (operate == "Creep") {
        switch(pointStatus.second) {
            case 'E' : col++; break;
            case 'W' : col--; break;
            case 'N' : row--; break;
            case 'S' : row++; break;
        }
        if (checkPathExist(row, col) && !checkPointPassed(row, col, direc)) {
            pair<int, int> newPoint(row, col);
            PointStatus newPointStatus(newPoint, direc);
            nextQueue.push(newPointStatus);
            //cout<<"go to "<<row<<", "<<col<<endl;
        } else {
            checkStatus = false;
        }
    } else if (operate == "Walk") {
        for (int i = 1; i <= 2; i++) {
            switch(pointStatus.second) {
                case 'E' : col++; break;
                case 'W' : col--; break;
                case 'N' : row--; break;
                case 'S' : row++; break;
            }
            if (!checkPathExist(row, col)) {
                checkStatus = false;
            }
        }
        if (checkStatus  && !checkPointPassed(row, col, direc)) {
            pair<int, int> newPoint(row, col);
            PointStatus newPointStatus(newPoint, direc);
            nextQueue.push(newPointStatus);
            //cout<<"go to "<<row<<", "<<col<<endl;
        } else {
            checkStatus = false;
        }
    } else if (operate == "Run") {
        for (int i = 1; i <= 3; i++) {
            switch(pointStatus.second) {
                case 'E' : col++; break;
                case 'W' : col--; break;
                case 'N' : row--; break;
                case 'S' : row++; break;
            }
            if (!checkPathExist(row, col)) {
                checkStatus = false;
            }
        }
        if (checkStatus && !checkPointPassed(row, col, direc)) {
            pair<int, int> newPoint(row, col);
            PointStatus newPointStatus(newPoint, direc);
            nextQueue.push(newPointStatus);
            //cout<<"go to "<<row<<", "<<col<<endl;
        } else {
            checkStatus = false;
        }
    } else if (operate == "Left") {
        switch(pointStatus.second) {
            case 'E' : direc = 'N'; break;
            case 'W' : direc = 'S'; break;
            case 'N' : direc = 'W'; break;
            case 'S' : direc = 'E'; break;           
        }
        if (!checkPointPassed(row, col, direc)) {
            pair<int, int> newPoint(row, col);
            PointStatus newPointStatus(newPoint, direc);
            nextQueue.push(newPointStatus);
            //cout<<"turn left"<<endl;
        } else {
            checkStatus = false;
        }
    } else if (operate == "Right") {
        switch(pointStatus.second) {
            case 'E' : direc = 'S'; break;
            case 'W' : direc = 'N'; break;
            case 'N' : direc = 'E'; break;
            case 'S' : direc = 'W'; break;           
        }
        if (!checkPointPassed(row, col, direc)) {
            pair<int, int> newPoint(row, col);
            PointStatus newPointStatus(newPoint, direc);
            nextQueue.push(newPointStatus);
            //cout<<"turn right"<<endl;
        } else {
            checkStatus = false;
        }
    }
    if (checkStatus) {
        passedPath[row][col][gitIntByChar(direc)] = 1;
    }
    if (row == desX && col == desY && checkStatus) {
        //cout<<"found "<<desX<<", "<<desY<<endl;
        found = true;
    }
    return found;
}

void bfs() {
    int level = 0;
    bool found = false;
    if (sourceX == desX && soueceY == desY) {
        found = true;
    } else {
        pair<int, int> point(sourceX, soueceY);
        PointStatus sourceStatus(point, direc);
        queue<pair<pair<int, int>,char> > que;
        que.push(sourceStatus);
        passedPath[sourceX][soueceY][gitIntByChar(direc)] = 1;

        wholeQueue.push(que);

        while (!wholeQueue.empty()) {
            //cout<<"level = "<<level<<endl;
            level++;
            queue< pair< pair<int, int>, char> > que = wholeQueue.front();
            queue<pair<pair<int, int>,char> > nextQueue;
            while (!que.empty()) {
                PointStatus pointStatus = que.front();
                // do creep
                if (checkOperate(pointStatus, "Creep", nextQueue)) {
                    found = true;
                    break;
                }
                if (checkOperate(pointStatus, "Walk", nextQueue)) {
                    found = true;
                    break;
                }
                if (checkOperate(pointStatus, "Run", nextQueue)) {
                    found = true;
                    break;
                }
                if (checkOperate(pointStatus, "Left", nextQueue)) {
                    found = true;
                    break;
                }
                if (checkOperate(pointStatus, "Right", nextQueue)) {
                    found = true;
                    break;
                }
                que.pop();
            }
            wholeQueue.pop();
            if (!nextQueue.empty()) {
                wholeQueue.push(nextQueue);
            }
            if (level > N * M || found) {
                break;
            }
        }
    }
    if (found) {
        cout<<level;
    } else {
        cout<<"-1";
    }
}

int main() {
    // init source data
    cin>>N>>M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin>>matrix[i][j];
            for (int k = 0; k < 4; k++) {
                passedPath[i][j][k] = 0;
            }
        }
    }
    cin>>sourceX>>soueceY>>desX>>desY;
    sourceX--;
    soueceY--;
    desX--;
    desY--;
    cin>>direc;
    bfs();

    return 0;
}
