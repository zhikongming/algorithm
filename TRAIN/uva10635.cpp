#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 250 * 250;
const int INF = 10000000;
int n, p, q;
int num[maxn], s[maxn], d[maxn], g[maxn];
// ����˼·�� ��lcs���⣬ ת��Ϊlis���⣬ Ȼ��lis������O(nlgn)�Ľⷨ
// lcs��̬�滮���⣬������ҪO(n^2)��ʱ�临�Ӷ� 
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &p, &q);
		memset(num, 0, sizeof(num));
		int x;
		// ��¼ԭ����x��ԭ�������������λ��Ϊ�ڼ��� 
		for (int i = 1; i <= p + 1; i++) {
			scanf("%d", &x);
			num[x] = i;
		}
		
		int n = 0;
		for (int i = 1; i <= q + 1; i++) {
			scanf("%d", &x);
			//�����������ԭ��������λ�� 
			if (num[x]) s[n++] = num[x];
		} 
		
		// ����ת��Ϊ��s�����������
		int ans = 0;
		for (int i = 1; i <= n; i++) g[i] = INF;
		for (int i = 0; i < n; i++) {
			int k = lower_bound(g+1, g+n+1, s[i]) - g;
			d[i] = k;
			g[k] = s[i];
			ans = max(ans, d[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
