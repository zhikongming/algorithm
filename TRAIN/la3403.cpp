#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 12;
// used��ʾ�����õĽڵ㣬  
int w[maxn], used[maxn]; 
int r, s, maxnode = 0;
double ans, lw[maxn], rw[maxn];

// ѭ��ȥ������������ ��������ֻ��n-1�� 
void build_tree(int dep) {
	if (dep == n) return;
	// ѡ�������㣬  used[i], used[j]������һ���µĵ�, i����ߣ� j���ұ� 
	for (int i = 0; i < maxn; i++) {
		if (used[i]) {
			for (int j = 0; j < maxn; j++) {
				if (i != j && used[j]) {
					double L = max(lw[i], lw[j]-1), R = max(rw[j], rw[i]-1);
					if (L + R + 1 < r) {
						// i, j����һ���µĵ�
						if (dep == n - 1) ans = max(ans, L + R + 1);
						used[i] = used[j] = 0; 
						int newnode = maxnode++;
						used[newnode] = 1;
						w[newnode] = w[i] + w[j];
						lw[newnode] = double(w[i]) / w[newnode] + L;
						rw[newnode] = double(w[j]) / w[newnode] + R;
						build_tree(dep + 1);
						maxnode--;
						used[maxnode] = 0;
						used[i] = used[j] = 1;
					} 
				}
			}
		} 
	} 
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &r, &s);
		// s���ڵ���ζ�Ŷ��� 2*s-1����ƽ 
		for (int i = 0; i < s; i++) {
			scanf("%d", &w[i]);
			used[maxnode++] = 1;
		}
		
		ans = 0;
		// ֻ��һ����׹�� ��ô��Ҳ�Ҳ�ס�ġ� 
		if (s != 1) {
			build_tree(1);
		}
		printf("%f\n", ans);
	}
	return 0;
}
