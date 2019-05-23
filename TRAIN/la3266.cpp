#include <cstdio>
#include <algorithm>
using namespace std;
// 田忌每次找比齐王里面比当前马小的最大的号 

const int maxn = 1000 + 5;
int tj[maxn], qw[maxn];
int n; 

int main() {
	while (scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++) scanf("%d", &tj[i]);
		for (int i = 0; i < n; i++) scanf("%d", &qw[i]);
		sort(tj, tj+n);
		sort(qw, qw+n);
		int i = n - 1, j = n - 1, ans = 0;
		while (i >= 0 && j >= 0) {
			if (tj[i] > qw[j]) {
				ans++;
				i--;
				j--;
			} else {
				j--;
			}
		}
		ans = ans - i - 1;
		printf("%d\n", ans * 200);
	}
	return 0;
}
