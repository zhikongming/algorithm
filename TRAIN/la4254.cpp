#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

struct Point {
    int r, d, w;
    // 给优先队列用
    bool operator < (const Point& a) const {
        return d > a.d;
    }
};

const int maxn = 10000 + 5;
Point A[maxn];
int n;

bool check(int k) {
    priority_queue<Point> qu;
    int i = 0;
    double nowtime = 0, nexttime;
    while (i < n) {
        if (qu.empty()) {
            qu.push(A[i]);
            nowtime = A[i].r;
            i++;
        }
        else {
            // 获取上一个开始的时间
            while (!qu.empty()) {
                Point now = qu.top();
                qu.pop();
                nexttime = i >= n ? (1<<20) : A[i].r;
                double costtime = (double)now.w / k;
                if (now.d < nowtime || nowtime + costtime > now.d) {
                    return false;
                }
                if (nowtime + costtime <= nexttime) {
                    nowtime += costtime;
                }
                else {
                    now.w -= (A[i].r - nowtime) * k;
                    nowtime = A[i].r;
                    qu.push(now);
                    if (i < n) {
                        qu.push(A[i++]);
                    }
                }
            }
        }
    }
    return true;
}

// 出现的顺序, 会影响资源的分配
bool cmp(Point a, Point b) {
    return a.r < b.r;
}

int main() {
    int T, r, d, w;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int maxw = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &r, &d, &w);
            A[i] = (Point) {r, d, w};
            maxw += w;
        }
        // 此类最大值最小/最小值最大的问题, 常用解法是二分法, 先预设一个x值, 看看x能不能满足需求, 再看x/2....
        // 本题可能还需要做一次贪心, , end时间越早的, 就应该先占用资源.
        
        sort(A, A+n, cmp);

        int start = 1, end = maxw;
        int mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (check(mid)) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        printf("%d\n", end+1);
    }

    return 0;
}
