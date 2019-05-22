#include <cstdio>
#include <cmath>
using namespace std;

int n;

// 贪心算法即可
int main() {
    while (scanf("%d", &n) == 1 && n) {
        int v;
        long long int sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &v);
            sum += v;
            ans += abs(sum);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
