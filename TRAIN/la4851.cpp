#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

/*
* Ѱ����A����ľ��룬 ��B����ľ��룬 Ȼ��ͳ���������ж��ٸ�. �뷨�Ǵ�ģ����� 
*/ 

const int maxn = 60000 + 5;
int du[maxn];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int m, n, x, y, Ax, Ay, Bx, By;
		scanf("%d%d", &m, &n);
		scanf("%d%d%d%d", &Ax, &Ay, &Bx, &By);
		// to make Ax < Bx
		if (Bx < Ax) {
			int tmp = Ax;Ax = Bx;Bx = tmp;
		}
		n -= 2;
		for (int i = Ax + 1; i < Bx; i++) {
			du[i] = m; 
		}
		du[Ax] = du[Bx] = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);
			du[x] = min(du[x], abs(y - Ay));
		}

		// from right to left.
		for (int i = Bx - 1; i > Ax; i--) {
			du[i] = min(du[i], du[i+1] + 1);
		}
		// from left to right
		for (int i = Ax + 1; i < Bx; i++) {
			du[i] = min(du[i], du[i-1] + 1);
		}

		int ans = 0;
		for (int i = Ax + 1; i < Bx; i++) {
			if (du[i] > 0) {
				ans++;
				ans += (du[i] - 1) * 2;
			}
		}
		printf("%d\n", ans);
	} 
	return 0;
}

/*
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int m, n, x, y, minl, minr, Ax, Ay, Bx, By;
		scanf("%d%d", &m, &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);
			if (i == 0) {
				Ax = x;Ay = y;
			} else if (i == 1) {
				Bx = x;By = y;
				// ��֤Ax < Bx 
				if (Bx < Ax) {
					int tmp = Ax;
					Ax = Bx;
					Bx = tmp;
				}
				minl = minr = abs(Bx-Ax);
			} else {
				minl = min(minl, abs(x-Ax) + abs(y-Ay));
				minr = min(minr, abs(x-Bx) + abs(y-By));
			}
		}
		// �鿴���ٵ�����minl ���� minr�� ��Ϊ�����ظ����㣬 ������Ҫ�ų���
		int hl, hr, ans = 0, h;
		for (int i = 1; i < Bx - Ax; i++) {
			hl = min(minl - i - 1, i - Ax - 1); // ����߶Աȣ� ������Ҫ����A�㣬 ���� 
			hr = min(minr - (Bx - i) - 1, Bx - i - 1);// ͬ�� 
			if (hl < 0 && hr < 0) {
				continue;
			} else if (hl >= 0 && hr < 0) {
				ans += hl * 2 + 1;
			} else if (hr >= 0 && hl < 0) {
				ans += hr * 2 + 1;
			} else {
				h = max(hl, hr);
				ans += h * 2 + 1; 
			}
			printf("%d = %d\n", i, ans);
		} 
		printf("%d\n", ans); 
	} 
	return 0;
} */ 
