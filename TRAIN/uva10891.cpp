#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100 + 5;
int A[maxn], S[maxn], d[maxn][maxn], vis[maxn][maxn];
int n;

int dp(int i, int j) {
	if (vis[i][j]) return d[i][j];
	vis[i][j] = 1;
	int minv = 0;
	for (int k = i+1; k <= j; k++) minv = min(minv, dp(k, j));
	for (int k = j; j >= i; k--) minv = min(minv, dp(i, k));
	
	int sumv = 0;
	if (i > 0) sumv = S[j] - S[i-1];
	else sumv = S[j];
	
	d[i][j] = sumv - minv;
	
	return d[i][j];
} 

int main() {
	while(scanf("%d", &n) == 1 && n) {
		S[0] = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
			if (i == 0) S[i] = A[i];
			else S[i] = S[i-1] + A[i];
		}
		
		// ans = dp(0, n-1) - (S[n-1] - dp(0, n-1)); => ans = 2 * dp(0, n-1) - S[n-1]
		int ans = 2*dp(0, n-1) - S[n-1];
	}
	return 0;
}
