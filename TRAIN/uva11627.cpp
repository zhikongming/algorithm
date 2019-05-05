#include <cstdio>
using namespace std;

const int maxn = 100000 + 5;
int w, v, n;
int A[maxn][2];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int x, y, s;
        scanf("%d%d%d", &w, &v, &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &x, &y);
            A[i][0] = x;
            A[i][1] = y;
        }
        scanf("%d", &s);
        for (int i = 0; i < s; i++) {
            
        }
    }
    return 0;
}
