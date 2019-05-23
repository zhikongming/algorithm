#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 5;
const int maxs = 1000000 + 5;
int A[maxn][2], S[maxs];
int w, v, n;

// 以区间为维度查看， 到每个门的时候在哪些区间里面， 如果不在区间里面， 则fail 
int check(int k) {
	double x, y, costtime, newx, newy;
	// 初始位置可选， 故区间为满区间
	x = A[0][0], y = x + w;
	for (int i = 1; i < n; i++) {
		costtime = (A[i][1] - A[i-1][1]) / (double)k;
		newx = x - v*costtime;
		newy = y + v*costtime;
		if (newx > A[i][0] + w || newy < A[i][0]) return false;
		x = newx < A[i][0] ? A[i][0] : newx;
		y = newy < A[i][0] + w ? newy : A[i][0] + w;
	}
	return true;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int x, y, s;
		scanf("%d%d%d", &w, &v, &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);
			A[i][0] = x;
			A[i][1] = y;
		}
		scanf("%d", &s);
		for (int i = 0; i < s; i++) {
			scanf("%d", &S[i]);
		}
		
		sort(S, S+s);
		int l = 0, r = s - 1, mid;
		while (l <= r) {
			mid = (l + r) / 2;
			if (check(mid)) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		printf("%d\n", S[r]);
	}
	return 0;
} 
