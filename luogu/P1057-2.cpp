#include <cstdio>
#include <cstring>
using namespace std;

int n, m;
const int maxn = 31;
int d[maxn][maxn];

int main() {
    scanf("%d%d", &n, &m);
    memset(d, 0, sizeof(d));
    // d[i][k] 表示第k次传递之后, 球在i的手里, 所以 d[i][k] = d[i-1][k-1] + d[i+1][k-1]
    d[1][0] = 1;
    for (int i = 1; i <= m; i++) {
        d[1][i] = d[n][i-1] + d[2][i-1];
        for (int j = 2; j <= n - 1; j++) {
            d[j][i] = d[j-1][i-1] + d[j+1][i-1];
        }
        d[n][i] = d[n-1][i-1] + d[1][i-1];
    }
    printf("%d\n", d[1][m]);
    return 0;
}
