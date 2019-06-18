#include <cstdio>
#include <set>
#include <cstring>
using namespace std;

const int maxn = 100000;
const int maxw = 16 + 1;
int n, d[maxn], cnt;
int weapon[maxw][maxw];

void startChoose(int pick, int step) {
    if (step == n + 1) {
        cnt++;
        return;
    }
    if (step == 1) {
        for (int i = 0; i < n; i++) {
            if (weapon[0][i]) {
                int k = i == 0 ? 1 : (i<<1);
                startChoose(k, step+1);
            }
        }
    } else {
        // get the picked num.
        set<int> picked;
        set<int> nextPick;
        for (int i = 0; i < n; i++) {
            int k = i == 0 ? 1 : ((i)<<1);
            if (pick & k) {
                picked.insert(i);
                for (int j = 0; j < n; j++) {
                    if (weapon[i+1][j]) {
                        nextPick.insert(j);
                    }
                }
            }
        }
        for (set<int>::iterator ite = nextPick.begin(); ite != nextPick.end(); ite++) {
            if (picked.find(*ite) == picked.end()) {
                int k = *ite == 0 ? 1 : (*ite)<<1;
                startChoose(pick ^ k, step+1);
            }
        }
    }
}

int main() {
    int T, kase = 1;
    scanf("%d", &T);
    while (kase <= T) {
        memset(d, 0, sizeof(d));
        scanf("%d", &n);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &weapon[i][j]);
            }
        }
        cnt = 0;
        startChoose(0, 1);
        printf("Case %d: %d\n", kase, cnt);
        kase++;
    }
    return 0;
}
