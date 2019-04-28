#include <cstdio>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
    bool operator < (const Point& m) const {
        return x < m.x;
    }
};

int n;
const int maxn = 100 + 5;
int y[maxn], on[maxn], left[maxn], on2[maxn];
Point p[maxn];

int solve() {
    sort(y, y + n);
    sort(p, p + n);
    // set the up & down line
    int m = unique(y, y + n) - y;
    printf("m = %d\n", m);
    int ans = 0;
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            // scan the p
            int ymin = y[i], ymax = y[j];
            printf("ymin = %d, ymax = %d\n", ymin, ymax);
            int temp = 0;
            int a = 0;
            for (int k = 0; k < n; k++) {
                 if (k == 0) {
                    a++;
                    on[a] = 0;
                    on2[a] = 0;
                    left[a] = 0;
                 } else if (p[k].x != p[k - 1].x) {
                    a++;
                    on[a] = 0;
                    on2[a] = 0;
                    left[a] = left[a-1] + on2[a-1] - on[a-1];
                 }
                 if (p[k].y > ymin && p[k].y < ymax) {
                    on[a]++;
                    on2[a]++;
                 }
                 if (p[k].y == ymin || p[k].y == ymax) {
                    on2[a]++;
                 }
            }
            
            int maxtemp = 0;
            // count = on2[j] + left[j] + on[i] - left[i]
            for (int k = 1; k <= a; k++) {
                printf("on[%d] = %d, left[%d] = %d, on2[%d] = %d\n", k, on[k], k, left[k], k, on2[k]);
                ans = max(ans, on2[k] + left[k] + maxtemp);
                maxtemp = max(maxtemp, on[k] - left[k]);
            }
            printf("ans = %d\n", ans);
        }
    }
    return ans;
}

int main() {
    int kase = 0;
    while (scanf("%d", &n) == 1 && n) {
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &p[i].x, &p[i].y);
            y[i] = p[i].y;
        }
        printf("Case %d: %d", kase++, solve());
    }
    return 0;
}
