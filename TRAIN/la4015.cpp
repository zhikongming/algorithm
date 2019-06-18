#include <cstdio>
#include <vector>
#include <pair>
using namespace std;

const int maxn = 500 + 5;
const int INF = 10000000;
vector< pair<int, int> > edges[maxn];
int dp[maxn][maxn][2], int vis[maxn], int sum[maxn];

/*
 * 记dp(u, k, flag)为从u出发，遍历了k个点，flag=1表示回到了u， flag=0表示没有回到u 的最小距离
 *
 */

void dfs(int root) {
    vis[root] = 1;
    sum[root] = 1;
    dp[u][1][0] = dp[u][1][1] = 0;
    for (int i = 0; i < edges[root].size(); i++) {
        int child = edges[root][i].first;
        int dis = edges[root][i].second;
        if (!vis[child]) {
            dfs(child);
            sum[root] += sum[child];
            for (int j = sum[root]; j > 1; j--) {
                for (int k = 0; k <= j && k <= sum[child]; k++) {
                    dp[root][j][1] = min(dp[root][j][1], dp[root][j-k][1] + dp[child][k][1] + 2 * dis);
                    dp[root][j][0] = min(dp[root][j][0], dp[u][j-k][1] + dp[child][k][0] + dis);
                    dp[root][j][0] = min(dp[root][j][0], dp[u][j-k][0] + dp[child][k][1] + 2 * dis);
                }
            }
        }
    }
}

int main() {
    int n;
    int kase = 1;
    while (scanf("%d", &n) == 1 && n) {
        printf("Case %d:\n", kase++);
        int par, cur, dis;
        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d%d", cur, par, dis);
            pair<int, int> p1 = make_pair(cur, dis);
            pair<int, int> p2 = make_pair(par, dis);
            edges[cur].push_back(p2);
            edges[par].push_back(p1);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k <= 1; k++) dp[i][j][k] = INF;
            }
        }
        memset(vis, 0, sizeof(vis));
        memset(sum, 0, sizeof(sum));
        dfs(0);

        int q;
        scanf("%d", &q);
        while (q--) {
            int x;
            scanf("%d", &x);
            for (int i = n; i >= 1; i--) {
                if (dp[0][i][1] <= x || dp[0][i][0] <= x) {
                    printf("%d\n", i);
                    break;
                }
            }
        }
    }
    return 0;
}
