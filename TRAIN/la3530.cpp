#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 500 + 5;
int n, m;
int A[maxn][maxn], B[maxn][maxn], SA[maxn][maxn], SB[maxn][maxn];
int d[maxn][maxn];

int dp(int row, int col) {
    if (d[row][col]) return d[row][col];
    int bottom = 0, right = 0;
    bottom = row > 0 ? SA[row][col] + dp(row-1, col) : SA[row][col];
    right = col > 0 ? SB[row][col] + dp(row, col-1) : SB[row][col];
    d[row][col] = max(bottom, right);
    return d[row][col];
}

int main() {
    while (scanf("%d%d", &n, &m) == 2 && n) {
        memset(SA, 0, sizeof(SA));
        memset(SB, 0, sizeof(SB));
        memset(d, 0, sizeof(d));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &A[i][j]);
                SA[i][j] = j == 0 ? A[i][j] : A[i][j] + SA[i][j-1];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &B[i][j]);
                SB[i][j] = i == 0 ? B[i][j] : B[i][j] + SB[i-1][j];
            }
        }

        int res = dp(n-1, m-1);
        printf("%d\n", res);
    }
    return 0;
}
