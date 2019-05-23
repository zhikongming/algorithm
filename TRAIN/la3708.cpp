#include <cstdio>
#include <cmath>
using namespace std;

const double maxn = 10000;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) == 2) {
		// 换句话说， 我们知道新的点的坐标， 只要把老的不在坐标上的点挪到坐标上就行了
		// 就近挪就行了 
		double ans = 0;
		for (int i = 0; i < n; i++) {
			double pos = (double)i / n * (n + m);
			ans += abs(pos - floor(pos + 0.5));
		}
		printf("%.4lf", ans * maxn / (n + m));
	}
	return 0;
}
