#include <cstdio>
#include <iostream>
#include <string> 
#include <algorithm>
using namespace std;

/*
* 思路： sum[i] 表示前i个中， 不同的位置的个数， 现在要找到i < j, 满足 sum[j]-sum[i] / j-i <= p/100
*        推倒一下， 即sum[j]*100 - p*j <= sum[i]*100-p*i, 单调递减即可 
*        本题就是LIS问题？ 
*/
const int maxn = 150000 + 5;
string A, B;
int k[maxn]; 

bool cmp(int i, int j) {
	return k[i] > k[j];
}

int main() {
	int n, p;
	while (scanf("%d%d", &n, &p) == 2 && n) {
		cin>>A;
		cin>>B;
		int sum = 0, tmp[maxn];
		for (int i = 0; i < n; i++) {
			if (A[i] != B[i]) sum++;
			k[i] = sum * 100 - p * i;
			tmp[i] = i;
		} 
		
		sort(tmp, tmp+n, cmp);
		
		int m = tmp[0], ans = 0;
		for (int i = 1; i < n; i++) {
			if (tmp[i] >= m && tmp[i] - m > ans) {
				ans = tmp[i] - m;// 这里为什么不是  tmp[i] - m + 1 呢？ 因为sum的原因， sum[i]是排除了第i个点了的， 从i+1开始计数的 
			}
			m = min(m, tmp[i]);
		}
		if (ans == 0) {
			printf("No sulution.\n");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
} 
