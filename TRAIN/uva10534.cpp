#include <cstdio>
#include <algorithm>
using namespace std;

/*
* ˼·����d(i)Ϊ��i��β������������еĸ�����
        k(i)Ϊ��i��β�����������������еĸ�����˳���������ǵ����ݼ����ˣ�
		����Ҫ��Ľ������max(min(d(i), k(i)) | 0<=i<n) 
		�㷨Ч��Ϊ�� O(nlgn)
*/

const int maxn = 10000 + 5;
const int INF = 10000000;
int g[maxn], d[maxn], k[maxn], A[maxn];

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &A[i-1]);
			g[i] = INF;
		}
		
		// set d(i)
		for (int i = 0; i < n; i++) {
			int m = lower_bound(g+1, g+n+1, A[i]) - g;
			g[m] = A[i];
			d[i] = m;
		}
		
		// set k(i)
		for (int i = 1; i <= n; i++) g[i] = INF;
		for (int i = n-1; i >= 0; i--) {
			int m = lower_bound(g+1, g+n+1, A[i]) - g;
			g[m] = A[i];
			k[i] = m;
		}
		
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max((min(d[i], k[i])-1)*2+1, ans);
		}
		printf("%d\n", ans);
	}
	return 0;
} 
