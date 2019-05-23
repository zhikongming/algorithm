#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 1000 + 5;
int n, m;
vector<int> edge[maxn];
int vis[maxn][2], d[maxn][2];

// f Ϊ r �ĸ��ڵ� , p ��ʾ�ýڵ�ĸ��ڵ��Ƿ�ŵ� 
int dp(int r, int p, int f) {
	if (vis[r][p])  return d[r][p];
	vis[r][p] = 1;
	
	d[r][p] = 2000;
	for (int i = 0; i < edge[r].size(); i++) {
		if (edge[r][i] != f) {
			d[r][p] += dp(edge[r][i], 1, r);
		}
	}
	if (f >= 0 && !p)  d[r][p]++;
	
	if (p || f < 0) {// rΪ���ڵ����r�ĸ��ڵ���ˣ� r�ڵ���ܲ��� 
		int sum = 0;
		for (int i = 0; i < edge[r].size(); i++) {
			if (edge[r][i] != f) {
				sum += dp(edge[r][i], 0, r);
			}
		}
		if (f >= 0) sum++;// r, f �ߴ��ڵ� 
		d[r][p] = min(d[r][p], sum);
	}
	
	return d[r][p];
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		int x, y;
		for (int i = 0; i < n; i++) edge[i].clear();
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &x, &y);
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		
		int ans = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++) {
			if (!vis[i][0]) { // i be the new root of the tree.
				ans += dp(i, 0, -1); 
			}
		}
		printf("%d %d %d", ans / 2000, m - ans % 2000, ans % 2000) 
	}
	return 0;
} 
