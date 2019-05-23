#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 15 + 1;
const int maxxy = 100 + 5;
int A[maxn], sum[1<<maxn], vis[1<<maxn][maxxy], d[1<<maxn][maxxy];
int n, x, y;

int bitcount(int x) {
	return x == 0 ? 0 : bitcount(x/2) + (x & 1);
}

int dp(int s, int r) {
	if (vis[s][r]) return d[s][r];
	vis[s][r] = 1;
	if (bitcount(s) == 1) {
		d[s][r] = 1;
		return d[s][r];
	}
	int c = sum[s] / r;
	// 获取s的子集
	for (int s0 = (s-1)&s; s; s0 = (s0-1)&s) {
		int s1 = s - s0;
		if (sum[s0]%x == 0 && dp(s0, min(sum[s0]/x, x)) && dp(s1, min(x, sum[s1]/x))) {
			d[s][r] = 1;
			return d[s][r];
		}
		if (sum[s0]%y == 0 && dp(s0, min(sum[s0]/y, y)) && dp(s1, min(y, sum[s1]/y))) {
			d[s][r] = 1;
			return d[s][r];
		}
	}
	d[s][r] = 0;
	return d[s][r];
}

int main() {
	while (scanf("%d", &n) == 1 && n) {
		scanf("%d%d", &x, &y);
		for (ini i = 0; i < n; i++) scanf("%d", &A[i]);
		
		memset(sum, 0, sizeof(sum));
		for (int s = 0; s < (1<<n); i++) {
			for (int i = 0; i < n; i++) {
				if (s & (1<<n)) sum[s] += A[i];
			}
		}
		
		int all = (1<<n) - 1;
		int ans = 0;
		if (sum[all] != x * y || sum[all] % x != 0) ans = 0;
		else {
			ans = dp(all, min(x, y));
		}
		if (ans) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
} 
