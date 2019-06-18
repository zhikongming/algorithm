#include <cstdio>
using namespace std;

const int maxn = 100 + 5;
const int maxm = 10000 + 5;
int happiness[maxn][maxm], walktime[maxn][maxm];

int main() {
    int n, m, k;
    while (scanf("%d%d%d", &n, &m, &k) == 3 && n) {
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m; j++) scanf("%d", &happiness[i][j]);
        }
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m; j++) scanf("%d", &walktime[i][j]);
        }

        // 题目的demo和我自己推演的结果不一样， 故放弃本题的研究
    }
    return 0;
}
