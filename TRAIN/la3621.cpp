#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 5;
int n, dep = 0, temp[maxn], top = 0;

// 表示最大深度dep下， 当前深度cur的深度优先搜索算法
// x表示当前的数值 

bool checkin(int k) {
	for (int i = 0; i <= top; i++) {
		if (temp[i] == k) return true;
	}
	return false;
}

bool dfs(int cur, int x) {
	//printf("try: cur = %d, x = %d, dep = %d, n = %d\n", cur, x, dep, n);
	if (cur > dep) return false;
	if (x == n) return true;
	int maxp = 0;
	for (int i = 0; i <= top; i++) {
		maxp = max(maxp, temp[i]);
	}
	if (x + maxp<<(dep - cur) < n) return false;
	// x与i之间的操作为+ 或者 - 
	for (int i = 0; i <= top; i++) {
		// 必须保证x比较大才能用减法 
		if (x > temp[i] && !checkin(x - temp[i])) {
			temp[++top] = x - temp[i];
			if (dfs(cur + 1, x - temp[i])) return true;
			top--;
		} 
		// 尝试一下加法
		if (!checkin(x + temp[i])) {
			temp[++top] = x + temp[i];
			if (dfs(cur + 1, x + temp[i])) return true;
			top--;
		}
	}
	return false;
}

int main() {
	// 本地和x没什么关系， 只需要指数的加减即可
	// 本体将采用迭代加深搜索的算法来进行计算 
	scanf("%d", &n);
	if (n != 1) {
		while (true) {
			memset(temp, 0, sizeof(temp));
			temp[0] = 1;
			top = 0;
			dep++;
			bool res = dfs(0, 1);
			if (res) {
				break;
			}
		}
	}
	printf("%d\n", dep);
	return 0;
} 
