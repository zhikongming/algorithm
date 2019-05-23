#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 5;
char str[maxn];
int data[maxn][maxn];

// l is left, r is right.
int dp(int l, int r) {
	if (data[l][r]) return data[l][r];
	// check the whole string, including l == r
	int a = l, b = r;
	bool isPa = true;
	while (a <= b) {
		if (str[a] != str[b]) {
			isPa = false;
			break;
		}
		a++;
		b--;
	}
	if (isPa) {
		data[l][r] = 1;
		return data[l][r];
	}
	// divide the string to two string.
	data[l][r] = maxn;
	for (int k = l; k < r; k++) {
		data[l][r] = min(dp(l, k) + dp(k+1, r), data[l][r]);
	}
	return data[l][r];
}

/*
* 思路： 计d(i, j)为i~j的划分最少回文字符串的个数，则d(i, j)=min(d(i, k)+d(k+1,j)), i<=k<=j. 
*/

int main() {
	scanf("%s", str);
	int ans = dp(0, strlen(str) - 1);
	printf("%d\n", ans);
	return 0;
} 
