#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

struct Ant {
	int id;
	int p;
	int d;
	bool operator < (const Ant& b) const {
		return p < b.p;
	}
};

const int maxn = 10000 +5;
Ant before[maxn];
Ant after[maxn];
const char dirStatus[][8] = {"L", "Turning", "R"};

int main() {
	int kase;
	scanf("%d", &kase);
	for (int i = 0; i < kase; i++) {
		int L, T, n;
		scanf("%d%d%d", &L, &T, &n);
		for (int j = 0; j < n; j++) {
			int p, intd;
			char d;
			scanf("%d %c", &p, &d);
			intd = d == 'L' ? -1 : 1;
			before[j] = (Ant) {j, p, intd};
			after[j] = (Ant) {0, p + T * intd, intd};
		}
		sort(before, before + n);
		// 输入第 before[j].id 的位置现在是j。 
		int order[maxn]; 
		for (int j = 0; j < n; j++) {
			order[before[j].id] = j;
		}
		
		sort(after, after + n);
		// 方向里面引入了一个turning, 处理一下
		for (int j = 1; j < n; j++) {
			if (after[j-1].p == after[j].p) {
				after[j-1].d = 0;
				after[j].d = 0;
			}
		} 
		
		// print all the ant info.
		printf("Case #%d:", i+1);
		for (int j = 0; j < n; j++) {
			int orderOfId = order[j];
			if (after[orderOfId].p < 0 || after[orderOfId].p > L) {
				printf("Fell off\n");
			} else {
				printf("%d %s\n", after[orderOfId].p, dirStatus[after[orderOfId].d+1]);
			}
		}
		printf("\n");
	} 
	return 0;
} 
