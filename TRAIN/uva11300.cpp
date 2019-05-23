#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1000000 + 5;
long long A[maxn], C[maxn], tot, M;
int main() {
	int n;
	while (scanf("%d", &n) == 1 && n) {
		tot = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lld", &A[i]);
			tot += A[i];
		}
		
		M = tot / n;
		C[0] = 0;
		for (int i = 1; i < n; i++) {
			C[i] = A[i] - M + C[i - 1];
		}
		sort(C, C + n);
		long long x1 = C[n>>1];
		long long ans = 0;
		printf("\n");
		for (int i = 0; i < n; i++) ans += abs(x1 - C[i]);
		printf("%lld\n", ans);
	}
	return 0;
} 
