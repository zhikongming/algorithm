#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 3000 + 5;
int A[maxn], dex[maxn];

/*
* 思路：1. 枚举A的所有子序列， 查看B里面有没有 O(n^2)
* 
*/

int main() {
	int n;
	while (scanf("%d", &n) && n) {
		int b;
		for (int i = 0; i < n; i++) scanf("%d", &A[i]);
		for (int i = 0; i < n; i++) {
			scanf("%d", &b);
			dex[b] = i;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int minv = dex[A[i]], maxv = dex[A[i]];
			for (int j = i + 1; j < n; j++) {
				// 判断A[i] ~ A[j]在B中是不是连续的。
				minv = min(minv, dex[A[j]]);
				maxv = max(maxv, dex[A[j]]);
				if (maxv - minv == j - i) {
					ans++; 
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
