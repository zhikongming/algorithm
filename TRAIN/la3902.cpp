#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 1000 + 5;

int n, s, k;
vector<int> edge[maxn], tree[manx];
int parent[maxn]; 
bool server[maxn];

// build the tree by root
void build_tree(int root, int par, int depth) {
	parent[root] = par;
	int child_num = edge[root].size();
	if (child_num == 1 && depth > k) tree[depth].push_back(root);
	for (int i = 0; i < child_num; i++) {
		int v = edge[root][i];
		if (v != par) build_tree(v, root, depth+1);
	}
}

void dfs(int root, int par) {
	server[root] = true;
	for (int i = 0; i < edge[root].size(); i++) {
		int v = edge[root][i];
		if (v != par) dfs(v, u);
	}
}

int solve() {
	int ans = 0;
	memset(server, 0, sizeof(server));
	for (int i = n - 1; i > k; i--) {
		for (int j = 0; j < tree[i].size(); j++) {
			int u = tree[i][j];
			if (server[u]) continue;
			int v = u;
			for (int k = 0; k < j; k++) {
				v = fa[v];
			}
			dfs(v, -1);
			ans++;
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%d%d", &s, &k);
		int a, b;
		for (int i = 0; i < n; i++) {
			edge[i].clear();
		}
		for (int i = 0; i < n - 1; i++) {
			scanf("%d%d", &a, &b);
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		build_tree(s, -1, 0);
		int ans = solve();
		printf("%d\n", ans);
	} 
	return 0;
}
