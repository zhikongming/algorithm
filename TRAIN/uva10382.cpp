#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, l, w;
struct Point {
    double start, end;
    bool operator < (const Point& a) {
        return start < a.start;
    }
};
const int maxn = 10000 + 5;
Point A[maxn];

void f(int p, int r, double& x, double& y) {
    double halfv = w / 2.0, valx;
    if (r <= halfv) {
        x = y = 0;
    } else {
        valx = sqrt(r * r - halfv * halfv);
        x = p - valx >= 0 ? p - valx : 0;
        y = p + valx <= l ? p + valx : l;
    }
}

int main() {
    int p, r;
    double x, y;
    scanf("%d%d%d", &n, &l, &w);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &p, &r);
        f(p, r, x, y);
        A[i] = (Point) {x, y};
    }

    sort(A, A + n);

    bool flag = true;
    int ans = 0;
    double tend = 0;
    double maxe = -100;
    for (int i = 0; i < n;) {
        int j = i;
        while (A[j].start <= tend && j < n) {
            maxe = max(maxe, A[j].end);
            j++;
        }
        // discontinuous, set flag false
        if (j == i) {
            flag = false;
            break;
        }
        ans++;
        tend = maxe;
        i = j;
    }
    if (tend < l) flag = false;

    printf("%d\n", flag ? ans : -1);
    
    return 0;
}
