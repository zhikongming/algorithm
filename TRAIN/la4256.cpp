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

bool checkMatch(int x, int y) {
    for (vector<int>::iterator it = edge[x].begin(); it != edge[x].end(); it++) {
        if (*it == y) return true;
    }
    return false;
}

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
        for (int i = 0; i < n; i++) {
            scanf("%d", &path[i]);
        }

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < vc; j++)
                d[i][j] = INF;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < vc; j++) {
                if (i == 0) {
                    if (path[i] == j) d[i][j] = 0;
                    else d[i][j] = 1;
                } else {
                    
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
