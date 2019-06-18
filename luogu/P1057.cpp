#include <cstdio>
using namespace std;

int n, m;
const int maxn = 31;
int d[maxn][maxn];

int choose(int step, int pos) {
    if (d[step][pos] != -1) return d[step][pos];
    if (step == 0) {
        if (pos == 0) {
            d[step][pos] = 1;
            return d[step][pos];
        }
        else {
            d[step][pos] = 0;
            return d[step][pos];
        }
    }
    if (pos >= step + 1 && pos <= n - step - 2) {
        d[step][pos] = 0;
        return d[step][pos];
    }
    return choose(step - 1, (pos + 1) % n) + choose(step - 1, (pos + n - 1) % n);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) d[i][j] = -1;
    }
    int cnt = choose(m, 0);
    printf("%d\n", cnt);
    return 0;
}
