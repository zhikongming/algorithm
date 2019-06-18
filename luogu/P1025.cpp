#include <cstdio>
using namespace std;

int cnt = 0;
int n, k;

void choose(int step, int left, int maxn) {
    if (step == k) {
        if (left >= maxn) cnt++;
    } else {
        int chooseMax = (left - maxn * (k - step));
        for (int i = maxn; i <= chooseMax; i++) {
            choose(step + 1, left - i, i);
        }
    }
}

int main() {
    scanf("%d%d", &n, &k);
    // 后面的数字顺序>=前面一个, 这样就永远不会出现重复的了
    choose(1, n, 1);
    printf("%d\n", cnt);
    return 0;
}
