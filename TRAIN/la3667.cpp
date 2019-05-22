#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 50 + 5;
const int maxnum = 1000000 + 5;
int A[maxn], n, id[maxnum], vis[maxnum];
set<int> ans;

/*
 * 思路: 可以利用宽度优先搜索, 如果这个宽度下能找到一个的方案, 则最优的方案一定在这个宽度下
 * 宽度这个问题, 可以和BFS联系起来, 感觉可以用宽度优先搜索来解决这个问题
 */

struct choice {
    int state;
    set<int> ans;
};

void bfs() {
    // 初始化第一个节点
    choice c;
    c.ans.clear();
    c.stat = 0;
    c.ans.insert(0);
    queue<choice> Q;
    Q.push(c);
    while (!Q.empty()) {
        choice cur = Q.front();
        Q.pop();
        // 判断是否所有的边都有了
        if (cur.state == (1<<n)-1) {
            // 找到的第一个能满足所有边的
            if (ans.size() == 0) {
                ans = cur.ans;
            } else {
                // 当前这个选择, 所用的刻度少
                if (cur.ans.size() < ans.size()) ans = cur.ans;
                else {
                    int sum1 = 0, sum2 = 0;
                    for (set<int>::iterator it = ans.begin(); it != ans.end(); it++) sum1 += *it;
                    for (set<int>::iterator it = cur.ans.begin(); it != cur.ans.end(); it++) sum2 += *it;
                    if (sum2 < sum1) ans = cur.ans;
                }
            }
        }

        // 题目要求, 输入保证 m <=7
        if (cur.ans == 7) continue;

        // 检查一下, 当前cur这个选择下, 边的选择情况
        for (int i = 0; i < n; i++) {
            if (cur.start & (1<<i)) continue;
            // 边A[i]没有找到过, 试一下以set的第i个点为起点尝试方案
            for (set<int>::iterator it = cur.ans.begin(); it != cur.ans.end(); it++) {
                // 计算差产生大小为dif的刻度
                if (*it > A[i]) {
                    int dif = *it - A[i];
                    choice p = cur;
                    for (set<int>::iterator it2 = p.ans.begin(); it2 != p.ans.end(); it2++) {
                        int dis = abs(*it2 - dif);
                        if (id[dis] == -1) continue;
                        p.state = (p.start | (1<<id[dis]));
                    }
                    p.ans.insert(dif);
                    if (!vis[p.state]) {
                        Q.push(p);
                        vis[p.state] = 1;
                    }
                }
                // 直接多一个边, 加一个新的
                if (*it + A[i] <= A[n-1]) {
                    int dif = *it + A[i];
                    choice p = cur;
                    for (set<int>::iterator it2 = p.ans.begin(); it2 != p.ans.end(); it2++) {
                        int dis = abs(*it2 - dif);
                        if (id[dis] == -1) continue;
                        p.state = (p.start | (1<<id[dis]));
                    }
                    p.ans.insert(dif);
                    if (!vis[p.state]) {
                        Q.push(p);
                        vis[p.state] = 1;
                    }
                }
            }
        }
    }
}

int main() {
    while (scanf("%d", &n) == 1 && n) {
        // 读取不同的距离的值
        int x, index = 0;
        memset(id, 0, sizeof(id));
        memset(vis, 0, sizeof(vis))
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            if (!id[x]) {
                id[x] = 1;
                A[index++] = x;
            }
        }
        n = index;
        sort(A, A+n);

        // 建立一个map, 表示某个长度的距离是第几条边
        memset(id, -1, sizeof(id));
        for (int i = 0; i < n; i++) {
            id[A[i]] = i;
        }
        bfs();
        printf("%d\n", ans.size());
        for (set<int>::iterator it = ans.begin(); it != ans.end(); it++) printf("%d ", *it);
    }
    return 0;
}
