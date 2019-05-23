#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 4;
const int maxOrder = 24;
int order[maxOrder][6];
int A[maxn][6];
int n;
int up[] = {2, 1, 5, 0, 4, 3};
int left[] = {4, 0, 2, 3, 5, 1};
int ans;
vector<string> names;
int r[maxn], color[maxn][6];// r for rotate time, color for the color after rotating. 

void rot(int* T, int* p) {
	int q[6];
	memcpy(q, p, sizeof(p));
	for (int i = 0; i < 6; i++) {
		p[i] = T[q[i]];
	}
}

void generate_order() {
	int p0[6] = {0, 1, 2, 3, 4, 5};
	int k = 0;
	for (int i = 0; i < 6; i++) {
		int p[6];
		memcpy(p, p0, sizeif(p0));
		if (i == 0) rot(up, p);
		if (i == 1) { rot(left, p);rot(up, p); }
		if (i == 3) { rot(up, p);rot(up, p); }
		if (i == 4) { rot(left, p);rot(left, p);rot(left, p);rot(up, p); }
		if (i == 5) { rot(left, p);rot(left, p);rot(up, p); }
		for (int j = 0; j <= 3; j++) {
			for (int m = 0; m < 6; m++) {
				order[k][m] = p[m];
			}
			m++;
			rot(left, p);
		}
	}
}

int getId(const char* name) {
	string s(name);
	int n = names.size();
	for (int i = 0; i < n; i++) {
		if (names[i] == s) return i;
	} 
	names.push_back(s);
	return n;
}

void check() {
	for (int i = 0; i < n; i++) {
		for (j = 0; j < 6; j++) {
			color[i][order[r[i]][j]] = A[i][j];
		}
	}
	// 这个顺序下面的颜色已经确定了。
	int tot = 0;
	for (int i = 0; i < 6; i++) {
		int cnt[maxn * 6];
		memset(cnt, 0, sizeof(cnt));
		int maxface = 0;
		for (int j = 0; j < n; j++) {
			maxface = max(maxface, ++cnt[color[j][i]]);
		}
		tot += n - maxface;
	} 
	ans += min(ans, tot);
}

void dfs(int d) {
	if (d == n) check();
	else {
		for (int i = 0; i < 24; i++) {
			r[d] = i;
			dfs[d + 1];
		}
	}
}

int main() {
	while (scanf("%d", &n) == 1 && n) {
		names.clear();
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < 6; c++) {
				char name[30];
				scanf("%s", name);
				A[r][c] = getId(name);
			} 
		}
		generate_order();
		// use the 
		ans = n * 6;
		r[0] = 0;// the first not rotate.
		dfs(1);
		printf("%d\n", ans);
	}
	return 0;
} 
