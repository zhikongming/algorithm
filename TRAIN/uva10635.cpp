#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 250 * 250;
const int INF = 10000000;
int n, p, q;
int num[maxn], s[maxn], d[maxn], g[maxn];
// 本题思路： 将lcs问题， 转化为lis问题， 然后lis问题有O(nlgn)的解法
// lcs动态规划来解，可能需要O(n^2)的时间复杂度 
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &p, &q);
		memset(num, 0, sizeof(num));
		int x;
		// 记录原数字x在原来的序列里面的位置为第几个 
		for (int i = 1; i <= p + 1; i++) {
			scanf("%d", &x);
			num[x] = i;
		}
		
		int n = 0;
		for (int i = 1; i <= q + 1; i++) {
			scanf("%d", &x);
			//现在这个数在原来的数的位置 
			if (num[x]) s[n++] = num[x];
		} 
		
		// 问题转换为求s的最长升序序列
		int ans = 0;
		for (int i = 1; i <= n; i++) g[i] = INF;
		for (int i = 0; i < n; i++) {
			int k = lower_bound(g+1, g+n+1, s[i]) - g;
			d[i] = k;
			g[k] = s[i];
			ans = max(ans, d[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
