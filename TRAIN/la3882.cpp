#include <cstdio>
using namespace std;

int n, k, m;
const int maxn = 10000 + 5;
int f[maxn];

int main() {
	while (scanf("%d%d%d", &n, &k, &m) == 3 && n) {
		f[1] = 0;
		for (int i = 2; i <= n; i++) {
			f[i] = (f[i-1] + k) % i;
		}
		// reback to origin order.
		int ans = (m - k + 1 + f[n] + n) % n;
		printf("%d\n", ans);
	}
	return 0;
}
