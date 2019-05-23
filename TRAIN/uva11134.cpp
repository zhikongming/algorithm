#include <cstdio>
using namespace std;

// 这个问题是八皇后问题的变形 
struct Rect {
	int xl, yl, xr, yr;
};

const int maxn = 5000 + 5;
int x[maxn], y[maxn];
Rect A[maxn];
int point[maxn][2];
int n; 
bool flag = false;

void solve(int k) {
	if (k == n + 1) {
		// success
		flag = true;
		for (int i = 1; i <= n; i++) {
			printf("%d %d\n", point[i][0], point[i][1]);
		}
	} else {
		for (int i = A[k].xl; i <= A[k].xr; i++) {
			if (!x[i]) {
				x[i] = 1;
				for (int j = A[k].yl; j <= A[k].yr; j++) {
					if (!y[j]) {
						y[j] = 1;
						point[k][0] = i;
						point[k][1] = j;
						solve(k+1);
						y[j] = 0;
					}
				}
				x[i] = 0;
			}
		}
	}
	
}

int main() {
	while (scanf("%d", &n) == 1 && n) {
		int xl, yl, xr, yr;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d%d", &xl, yl, xr, yr);
			A[i] = (Rect) {xl, yl, xr, yr};
		}
		solve(1);
		if (!flag) printf("IMPOSSIBLE");
	}
	return 0;
}
