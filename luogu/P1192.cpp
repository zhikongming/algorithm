#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100000 + 5;
const int modnum = 100003;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int step[maxn];
    memset(step, 0, sizeof(step));
    for (int i = 1; i <= k; i++) step[i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = i - 1; j >= 0 && i - j <= k; j--) {
            step[i] += step[j];
            step[i] %= modnum;
        }
        //printf("step[%d] = %d\n", i, step[i]);
    }
    printf("%d\n", step[n]);
    return 0;
}
