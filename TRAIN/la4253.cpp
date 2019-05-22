#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct area {
    int d, l, r;
    bool operator < (const area& a) const {
        return d < a.d;
    }
};

int w, n;
vector<area> A;
const double minstep = 1e-8;

// 检查m点是否可以射穿所有的靶子, 0表示可以, -1 表示偏左, 1表示偏右
// d, l, r 做计算斜率来用, 因为可能出现没有斜率的情况, 所以不能直接用斜率表示
int ok(double m) {
    double d, l, r, tmpl, tmpr;
    d = A[0].d, l = A[0].l, r = A[0].r;
    for (int i = 1; i < n; i++) {
        tmpl = (A[i].d/d)*(l-m)+m;
        tmpr = (A[i].d/d)*(r-m)+m;
        if (tmpr < A[i].l) return 1;
        else if (tmpl > A[i].r) return -1;
        else {
            d = A[i].d;
            l = A[l].l > tmpl ? A[i].l : tmpl;
            r = A[l].r < tmpr ? A[i].r : tmpr;
        }
    }
    return 0;
}

// 判断在0-w里面, 能不能找到一个点, 可以射穿所有的靶子
// 查找点可以采用二分查找的方式
bool check(double w) {
    double l = 0, r = w, m;
    while (r - l > minstep) {
        m = (l + r) / 2;
        // 检查m点是否可以射穿, 或者找出m点是偏左了还是偏右了
        int val = ok(m);
        if (val == 0) return true;
        else if (val == 1) {
            r = m;
        } else l = m;
    }
    return false;
}

int main() {
    int T, d, l, r;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &w, &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &d, &l, &r);
            area a = (area) {d, l, r};
            A.push_back(a);
        }

        sort(A.begin(), A.end());
        bool res = check(w);
        printf("%s", res ? "YES" : "NO");
    }
    
    return 0;
}
