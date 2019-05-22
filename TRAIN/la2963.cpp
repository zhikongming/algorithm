#include <cstdio>
#include <cmath>
using namespace std;

struct Point {
    int x, y, z, p;
};

const int maxn = 1000 + 5;
// dis 表示每个点和其他的点之间的距离
int n, ans, minr;
double dis[maxn][maxn];
Point A[maxn];

int main() {
    while (scanf("%d", &n) == 1) {
        int x, y, z, p;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d%d", &x, &y, &z, &p);
            A[i] = (Point){x, y, z, p};
            dis[i][i] = 0;
            for (int j = 0; j < i; j++) {
                dis[i][j] = dis[j][i] = sqrt((A[i].x - A[j].x)*(A[i].x - A[j].x) + (A[i].y - A[j].y)*(A[i].y - A[j].y) + (A[i].z - A[j].z)*(A[i].z - A[j].z));
            }
        }
    }
    return 0;
}
