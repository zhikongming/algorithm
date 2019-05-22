#include <cstdio>
using namespace std;

const int maxn = 100000 + 5;
int A[maxn], sum[maxn], k[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, l;
        sum[0] = 0;
        for (int i = 1; i <= n; i++) {
            char ch = getchar();
            if (ch == '0') A[i] = 0;
            else A[i] = 1;
            sum[i] = sum[i-1] + A[i];
        }
        // 其实找的就是 (sum[j] - sum[i-1]) / (j - i + 1) 的斜率
        // 数形结合, 需要移除凸点
        for (int m = l; m <= n; m++) {
            
        }
    }
    return 0;
}
