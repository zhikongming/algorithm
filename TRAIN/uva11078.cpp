#include <cstdio>
#include <algorithm>
using namespace std;

int n, A[100000];

int solve() {
	int ans = A[0] - A[1];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ans = max(ans, A[i] - A[j]);
		}
	}
	return ans;
}

int solve2(int i, int j) {
	if (i == j) return -10000000;
	int m = (i + j) / 2;
	int maxn = max(solve2(i, m), solve2(m+1, j));
	int left = A[m], right = A[m+1];
	for (int k = m; k >= i; k--) left = max(A[k], left);
	for (int k = m + 1; k <= j; k++) right = min(A[k], right);
	maxn = max(maxn, left - right);
	return maxn;
}

int solve3() {
	int ans = A[0] - A[1];
	int maxi = A[0];
	for (int j = 1; j < n; j++) {
		ans = max(ans, maxi - A[j]);
		maxi = max(maxi, A[j]);
	}
	return maxi;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &A[i]);
		//int ans = solve();
		//int ans = solve2(0, n - 1);
		int ans = solve3();
		printf("%d\n", ans);
	}
	return 0;
}
