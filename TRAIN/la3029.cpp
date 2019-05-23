#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 5;
int A[maxn][maxn], up[maxn][maxn], left[maxn][maxn], right[maxn][maxn];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int m, n;
		scanf("%d%d", &m, &n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				char c;
				scanf("%c", &c);
				A[i][j] == 'F' ? 0 : 1;
			}
		}
		
		int ans;
		for (int i = 0; i < m; i++) {
			int lo = -1;
			int ro = n;
			// from left to right
			for (int j = 0; j < n; j++) {
				if (A[i][j] == 1) {
					up[i][j] = 0;
					left[i][j] = 0;
					lo = j;
				} else {
					if (i == 0) {
						up[i][j] = 1;
						left[i][j] = lo + 1;
					} else {
						up[i][j] = up[i-1][j];
						left[i][j] = max(left[i-1][j], lo + 1);
					}
				}
			}
			// from right to left
			for (int j = n - 1; j >= 0; j--) {
				if (A[i][j] == 1) {
					right[i][j] = n;
					ro = j;
				} else {
					if (i == 0) {
						right[i][j] = ro - 1;
					} else {
						right[i][j] = min(right[i-1][j], ro - 1);
					}
					ans = max(ans, up[i][j] * (right[i][j] - left[i][j] + 1));
				}
			}
		}
		
		printf("%d\n", ans * 3);
	}
	return 0;
}
