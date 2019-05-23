#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 5000 + 5;
int w[maxn], e[maxn];
int n;

bool check(int k) {
	// wno 表示前i个， w跑道最多可以起飞的飞机的数量 
	int sumw = 0, sume = 0, wno = 0, eno = 0;
	for (int i = 0; i < n; i++) {
		sumw += w[i];
		sume += e[i];
		if (sumw) wno++;
		if (sume) eno++;

		if (sumw - k > wno || sume - k > eno) {
			return false;
		}  
	} 
	return true;
}

int main() {
	int T, maxw = 0, maxe = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &w[i], &e[i]);
			maxw += w[i];
			maxe += e[i];
		}
		int l = 1, r = max(maxw, maxe), mid;
		while (l <= r) {
			mid = (l + r) / 2;
			if (check(mid)) r = mid - 1;
			else l = mid + 1; 
		}
		// 编号比实际数量少1 
		printf("%d\n", l +1 - 1);
	}
	return 0;
}
