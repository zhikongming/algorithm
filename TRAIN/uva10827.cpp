#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 75 + 5;
const int INF = 1000000000;
int n, A[maxn][maxn], S[maxn][maxn];
// S[i][j] ��ʾ��i�У� ��j��Ϊ����ǰ׺�� 

int main() {
	int T;
	while (T--) {
		scanf("%d", &n);
		memset(S, 0, sizeof(S));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &A[i][j]);
				S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A[i][j];
			}
		}
		
		// ö����ʼ����յ�, ��ʼ��Ϊ(r1, c1), �յ�Ϊ(r2, c2) 
		int r1, c1, r2, c2, maxans = -INF, temp;
		for (r1 = 1; r1 <= n; r1++) {
			for (c1 = 1; c1 <=n; c1++) {
				for (r2 = 1; r2 <= n; r2++) {
					for (c2 = 1; c2 <= n; c2++) {
						if (r1 <= r2) {
							if (c1 <= c2) {
								temp = S[r2][c2] - S[r2][c1] - S[r1][c2] + S[r1][c1];
							} else {
								temp = S[r2][c2] - S[r1][c2] + S[r2][n] - S[r2][c1] - S[r1][n] + S[r1][c1];
							}
						} else {
							if (c1 <= c2) {
								temp = S[r2][c2] - S[r2][c1] + S[n][c2] - S[n][c1] - S[r1][c2] + S[r1][c1];
							} else {
								temp = S[n][n] - S[n][c1] - S[r1][n] + S[r1][c1] + S[r2][c2] + S[n][c2] - S[r1][c2] + S[r1][n] - S[r1][c1];
							}
						}
						maxans = max(maxans, temp);
					}
				}
			}
		}
		
		printf("%d\n", maxans);
	}
	return 0;
