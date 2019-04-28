#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 20 + 5;
long long int S[maxn][maxn][maxn];
const long long INF = 1LL << 60;

long long getArea(int x1, int x2, int y1, int y2, int z1, int z2) {
    long long res = 0;
    res = S[x2][y2][z2] - S[x1][y1][z1] - S[x2][y1][z2] + S[x2][y1][z1] - S[x1][y1][z2] + S[x1][y1][z2] - S[x2][y2][z1] + S[x1][y2][z1];
    return s;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b, c;
        memset(S, 0. sizeof(S));
        for (int x = 1; x <= a; x++) {
            for (int y = 1; y <= b; y++) {
                for (int z = 1; z <= c; z++) {
                    scanf("%lld", &S[x][y][z]);
                }
            }
        }


        for (int x = 1; x <= a; x++) {
            for (int y = 1; y <= b; y++) {
                for (int z = 1; z <= c; z++) {
                    S[x][y][z] = S[x-1][y-1][z-1] + S[x][y-1][z] - S[x][y-1][z-1] + S[x-1][y][z] - S[x-1][y-1][z] + S[x][y][z-1] - S[x-1][y][z-1];
                }
            }
        }

        long long int ans = 0;
        for (int x1 = 1; x1 <= a; x1++) {
            for (int x2 = x1; x2 <= a; x2++) {
                for (int y1 = 1; y1 <= b; y1++) {
                    for (int y2 = y1; y2 <= b; y2++) {
                        long long temp = 0;
                        for (int z = 1; z <= c; z++) {
                            // 这里是 顺序最大差值问题, O(n)可以实现
                            long long res = getArea(x1, x2, y1, y2, 1, z);
                            ans = max(ans, res - temp);
                            temp = min(temp, res);
                        }
                    }
                }
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}
