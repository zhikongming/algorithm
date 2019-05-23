#include <cstdio>
using namespace std;

const int maxn = 60 + 5;
int n, start[maxn], finish[maxn];

// 把P中， 前k个挪到final去 
long long f(int* P, int k, int final) {
	if (k == 0) return 0;
	if (P[k] == final) return f(P, k - 1, final);
	return f(P, k - 1, 6 - P[k] - final) + (1LL << (k - 1)) - 1 + 1; // 最后这个是， 经典的汉诺塔的k-1层挪到一个上去， 2^n - 1, 加上最后一个move的操作。 
} 

int main() {
	int kase = 0;
	while (scanf("%d", &n) == 1 && n) {
		for (int i = 0; i < n; i++) scanf("%d", &start[i]);
		for (int i = 0; i < n; i++) scanf("%d", &finish[i]);
		int k = n;
		while (k >= 0 && start[k] == finish[k]) k--;

		long long ans = 0;
		if (k >= 0) {
			int other = 6 - start[k] - finish[k];// 借助于other这个柱子
			ans +=  f(start, k - 1, other) + 1 + f(finish, k - 1, other);// finish 这个其实是反着来的， 其实是参考状态变成目标状态 
		}
		printf("Case %d: %lld\n", ++kase, ans);
	}
}
