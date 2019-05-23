#include <cstdio>
using namespace std;

int temp[10];
int result[10000][10];
int ans = 0;

int f(int i, int k) {
	if (i == 10) {
		if (k == 0) {
			// success
			for (int m = 0; m < 10; m++) {
				result[ans][m] = temp[m];
			}
			ans++;
		}
	} else {
		for (int j = 1; j <= 3 && j <= k; j++) {
			temp[i] = j;
			f(i+1, k - j);
		}
	}
} 

int main() {
	int n;
	scanf("%d", &n);
	f(0, n);
	printf("%d\n", ans);
	for (int i = 0; i < ans; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
