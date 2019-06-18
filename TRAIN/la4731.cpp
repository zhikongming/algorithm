#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100 + 5;
const int INF = 10000000;
int A[maxn];
int n, w;
int d[maxn][maxn];

// 记dp(i, k)为前i个分组, 一共占用了k个数字
int dp(int i, int k) {
    if (d[i][k] != INF) return d[i][k];
    if (i == 0 || k== 0 || k < i) return INF;
    for (int m = 1; m <= k - i; m++) {
        int sum = 0;
        for (int j = )
        d[i][k] = min(d[i][k], dp(i-1, k-m) + k * )
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int sum = 0;
        scanf("%d%d", &n, &w);
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
            sum += A[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = INF;
            }
        }

        sort(A, A+n);
        int res = dp(w, n);
        printf("%f", (double)res / sum);
    }
    return 0;
}
