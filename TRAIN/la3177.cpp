#include <cstdio>
using namespace std;

const int maxn = 100000 + 5;

int n;
int r[maxn];
int left[maxn], right[maxn];

bool ok(int m) {
	int x = r[1];
	// left 为左边占用的最大的ID 
	left[1] = x;
	right[1] = 0;
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 1) {
			// 奇数偏右 
			right[i] = 
		} else {
			// 偶数偏左 
			left[i] = 
		}
	}
}

int main() {
	// 如果为偶数的话， ans=max(r[i]+r[i+1]), 如果为计数， 则第一个取1~r[0], 后面偶数往前， 奇数往后， 这样第n个和第一个就错开了 
	while(scanf("%d"), &n == 1 && n) {
		for (int i = 1; i <= n; i++) scanf("%d", &r[i]);
		r[n+1] = r[1];
		int L = 0, R = 0;
		for (int i = 1; i <= n; i++) L = max(L, r[i] + r[i+1]);
		if (n % 2 == 1) {
			for (int i = 1; i < n; i++) {
				R = max(R, 3 * r[i]);
			}
			while (L < R) {
				int M = (L + R) / 2;
				if (ok(M)) {
					L = M + 1;
				} else {
					R = M;
				}
			}
		}
		printf("%d\n", L);
	}
	return 0;
}
