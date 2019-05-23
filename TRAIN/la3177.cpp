#include <cstdio>
using namespace std;

const int maxn = 100000 + 5;

int n;
int r[maxn];
int left[maxn], right[maxn];

bool ok(int m) {
	int x = r[1];
	// left Ϊ���ռ�õ�����ID 
	left[1] = x;
	right[1] = 0;
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 1) {
			// ����ƫ�� 
			right[i] = 
		} else {
			// ż��ƫ�� 
			left[i] = 
		}
	}
}

int main() {
	// ���Ϊż���Ļ��� ans=max(r[i]+r[i+1]), ���Ϊ������ ���һ��ȡ1~r[0], ����ż����ǰ�� �������� ������n���͵�һ���ʹ��� 
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
