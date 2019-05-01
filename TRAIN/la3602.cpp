#include <cstdio>
#include <algorithm>
using namespace std;

const int maxm = 50 + 5;
const int maxn = 1000 + 5;
int p[maxn][4];
int v[maxm][maxn];
int c[maxm];
int m, n;
char mapt[4] = {'A', 'C', 'G', 'T'};

int chartoint(char c) {
    for (int i = 0; i < 4; i++) {
        if (mapt[i] == c) return i;
    }
}

void readstring(int k) {
    int i = 0, t;
    char c = getchar();
    while (i < n) {
        if (c >= 'A' && c <= 'Z') {
            t = chartoint(c);
            v[k][i] = t;
            p[i][t]++;  
            i++;
        }
        c = getchar();
    }
}

void genscore(int k) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (m - p[i][v[k][i]]);
    }
    c[k] = sum;
    printf("sum[k] = %d\n", sum);
}

bool cmp(int i, int j) {
    return c[i] < c[j];
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) {
        readstring(i);
    }

    // generate the Hamming distance.
    for (int i = 0; i < m; i++) {
        genscore(i);
    }

    int key[n];
    for (int i = 0; i < m; i++) {
        key[i] = i;
    }
    sort(key, key + m, cmp);

    int ans = -1;
    for (int i = 0; i < m; i++) {
        if (c[key[0]] == c[i]) {
            if (ans == -1) ans = i;
            else {
                for (int j = 0; j < n; j++) {
                    if (v[i][j] < v[ans][j]) {
                        ans = i;
                        break;
                    }
                }
            }
        }
    }

    // print the ans
    for (int i = 0; i < n; i++) {
        printf("%c", mapt[v[ans][i]]);
    }
    printf("\n%d\n", ans);
    return 0;
}
