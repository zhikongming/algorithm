#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 15 + 5;
const int INF = 1000000;
int n;
int A[maxn][maxn], B[maxn][maxn];

// Check the change times when the first line known. 
int check(int i) {
	int step = 0;
	memset(B, 0, sizeof(B));
	for (int j = 0; j < n; j++) {
		if (i & (1<<j)) {
			B[0][j] = 1;
			if (A[0][j] == 0) step++;
		} else if (A[0][j] == 1) {
			return INF;// conflict
		}
	}
	// Calculate the next line by this line.
	for (int row = 0; row < n - 1; row++) {
		for (int col = 0; col < n; col++) {
			int flag = 0;
			if (row > 0) flag = flag ^ B[row-1][col];
			if (col > 0) flag = flag ^ B[row][col-1];
			if (col < n-1) flag = flag ^ B[row][col+1];
			if (flag ^ A[row+1][col]) {
				if (A[row+1][col] == 1) return INF;
				B[row+1][col] = 1;
				step++;
			} else {
				B[row+1][col] = A[row+1][col];
			}
		}
	}
	return step;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		// Begin the test data input.
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				scanf("%d", &A[j][k]);
			}
		}
		// We can get the next line by this line
		// loop the first line.
		int ans = INF;
		bool flag = false;
		for (int j = 0; j < (1<<n); j++) {
			ans = min(ans, check(j));
		}
		if (ans == INF) ans = -1;
		printf("Case %d: %d\n", i, ans);
	}
	return 0;
} 
