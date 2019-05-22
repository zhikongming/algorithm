#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int p = 4, m = 3;
int data[p][m][m];
set<int> choice;

struct Choose {
	vector<int> ans;
	int state;
};

void init_data() {
	data[0] = {20, 25, 11, 20, 6, 2, 1, 15, 23};
	data[1] = {5, 21, 3, 12, 23, 17, 7, 26, 2};
	data[2] = {8, 18, 4, 22, 13, 27, 16, 5, 11};
	data[3] = {19, 9, 24, 2, 11, 5, 14, 28, 16};
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < m; k++) {
				choice.insert(data[i][j][k]);
			}
		}
	}
} 

bool checkChoose(Choose& ch) {
	// 前ch.state - 1 个已经bingo了
	for (int i = ch.state + 1; i < p; i++) {
        // 检查这个矩形有没有bingo
        set<int> row, col, dig;
        for (vector<int>::iterator it = ch.ans.begin(); it != ch.ans.end(); it++) {
            // 检查这个选择是否符合规律
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < m; c++) {
                    if (data[i][r][c] == *it) {
                        row.insert(r);
                        col.insert(c);
                        if (r == c || r + c == m - 1) dig.insert(r);
                        // 判断是否bingo
                        if (row.size() == m || col.size() == m || dig.size() == m) {
                            if (i != ch.state + 1) return false;
                            ch.state++;
                        }
                    }
                }
            }
        }
	}
    return true;
}

void bfs() {
	queue<Choose> Q;
	for (set<int>::iterator it = choice.begin(); it != choice.end(); it++) {
		Choose ch;
		ch.ans.clear();
        ch.ans.push_back(*it);
		ch.state = -1;
		if (checkChoose(ch)) {
			Q.push(ch);
		}
	}
    while (!Q.empty()) {
        Choose ch = Q.front();
        Q.pop();
        for (set<int>::iterator it = choice.begin(); it != choice.end(); it++) {
            Choose pc = ch;
            if (find(pc.ans.begin(), pc.ans.end(), *it) == pc.ans.end()) {
                pc.ans.push_back(*it);
                if (checkChoose(pc)) {
                    if (pc.state == p -1) {
                        for (vector<int>::iterator it = pc.ans.begin(); it != pc.ans.end(); it++) {
                            printf("%d ", *it);
                            printf("\n");
                            return;
                        }
                    }
                    Q.push(pc);
                }
            }
        }
    }
}

int main() {
	// 本题目里面，我们不要求输入数据， 就用一个测试数据， 主要是为了测试算法 
	init_data();
	bfs();
	return 0;
}
