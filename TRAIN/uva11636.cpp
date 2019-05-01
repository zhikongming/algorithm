#include <cstdio>
using namespace std;

int main() {
    int n, ans = 0, x = 1;
    scanf("%d", &n);
    while (x < n) {
        ans++;
        x *= 2;
    }
    printf("%d\n", ans);
    return 0;
}
