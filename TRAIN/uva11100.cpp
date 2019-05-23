#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 5;
int A[maxn], n, used[maxn];

int main() {
	while (scanf("%d", &n) == 1 && n) {
		int ans = 1;
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
		}
		sort(A, A+n);
		int c = 0;
		for (int i = 0; i < n; i++) {
			if (i == 0 || A[i] != A[i-1]) c = 1;
			else {
				c++;
				ans = max(ans, c);
			}
		}
		printf("%d\n", ans);
		for (int i = 0; i < ans; i++) {
			int last = -1;
			for (int j = 0; j < n; j++) {
				if (!used[j] && (last == -1 || A[j] != last)) {
					printf("%d ", A[j]);
					used[j] = 1;
					last = A[j];
				}
			}
			printf("\n");
		}
	}
	return 0;
}
