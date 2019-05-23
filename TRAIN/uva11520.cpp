#include <cstdio>
using namespace std;

const int maxn = 10 + 5;
int n;
char be[maxn][maxn];

int main() {
	int T;
	scnaf("%d", &T);
	for (int kase = 0; kase < T; kase++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", be[i]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (be[i][j] == '.') {
					for (char c = 'A'; c <= 'Z'; c++) {
						bool ok = true;
						// check conflict.
						if (i>0 && be[i-1][j] == c) ok = false;
						if (i<n-1 && be[i+1][j] == c) ok = false;
						if (j>0 && be[i][j-1] == c) ok = false;
						if (j<n-1 && be[i][j+1] == c) ok = false;
						if (ok) {
							be[i][j] = c;
						}
					}
				}
			}
			printf("Case %d:\n", kase);
			for (int i = 0; i < n; i++) printf("%s\n", be[i]);
		}
	}
	return 0;
} 
