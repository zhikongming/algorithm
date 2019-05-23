#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 100 + 5;
const int pmaxn = 200 + 5;
const int INF= 1000000;
int edge[maxn][maxn];
int path[pmaxn];
int d[pmaxn][pmaxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(edge, 0, sizeof(edge));
        int vc, ec;
        scanf("%d%d", &vc, &ec);
        int v1, v2;
        for (int i = 0; i < ec; i++) {
            scanf("%d%d", &v1, &v2);
            edge[v1][v2] = 1;
            edge[v2][v1] = 1;
        }
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &path[i]);
        }

        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= vc; j++)
                d[i][j] = INF;

        // set i = 0
        int k = 1;
        for (int j = 1; j <= vc; j++) {
        	if (path[k] == j) d[k][j] = 0;
        	else d[k][j] = 1;
		}
		k++;
		// d[i][j] 表示前i个， 并且第i个为j满足path的最小的个数 
		while (k <= n) {
			for (int i = 1; i <= vc; i++) {
				// d[k-1][i] to make d[k][j]
				for (int j = 1; j <= vc; j++) {
					if (j == i || edge[i][j]) {
						if (j == path[k]) d[k][j] = min(d[k-1][i], d[k][j]);
						else d[k][j] = min(d[k-1][i] + 1, d[k][j]);
					}
				}
			}
			k++;
		}
		int ans = INF;
		for (int i = 1; i <= vc; i++) {
			ans = min(d[n][i], ans);
		}
		
        printf("%d\n", ans);
    }
    return 0;
}
