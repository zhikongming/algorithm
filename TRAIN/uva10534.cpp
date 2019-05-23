#include <cstdio>
#include <algorithm>
using namespace std;

/*
* 思路：记d(i)为以i结尾的最长上升子序列的个数，
        k(i)为以i结尾的逆序的最长上升子序列的个数（顺序来看就是单调递减的了）
		我们要求的结果就是max(min(d(i), k(i)) | 0<=i<n) 
		算法效率为： O(nlgn)
*/

const int maxn = 10000 + 5;
const int INF = 10000000;
int g[maxn], d[maxn], k[maxn], A[maxn];

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &A[i-1]);
			g[i] = INF;
		}
		
		// set d(i)
		for (int i = 0; i < n; i++) {
			int m = lower_bound(g+1, g+n+1, A[i]) - g;
			g[m] = A[i];
			d[i] = m;
		}
		
		// set k(i)
		for (int i = 1; i <= n; i++) g[i] = INF;
		for (int i = n-1; i >= 0; i--) {
			int m = lower_bound(g+1, g+n+1, A[i]) - g;
			g[m] = A[i];
			k[i] = m;
		}
		
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max((min(d[i], k[i])-1)*2+1, ans);
		}
		printf("%d\n", ans);
	}
	return 0;
} 
