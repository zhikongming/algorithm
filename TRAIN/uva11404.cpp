#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 5;
char str[maxn], strv[maxn], res[maxn];
int d[maxn][maxn], n;

/*
 * 鎬濊矾: 鎶婃簮瀛楃涓插�掑簭涔嬪悗, 姹傚嚭鏈�闀垮叕鍏卞瓙搴忓垪灏辨槸婧愬瓧绗︿覆鐨勬渶闀垮洖鏂囦簡
 */

int dp(int i, int j) {
    if (d[i][j]) return d[i][j];
    if (i < 0 || j < 0) return 0;
    if (str[i] == strv[j]) {
        d[i][j] = dp(i-1, j-1) + 1;
    }
    else d[i][j] = max(dp(i-1, j), dp(i, j-1));
    return d[i][j];
}

int main() {
    while (scanf("%s", str)) {
        memset(d, 0, sizeof(d));
        n = strlen(str);
        for (int i = 0; i < n; i++) {
            strv[n-i-1] = str[i];
        }
        int i = n - 1, j = n - 1, index = 0;
        int ans = dp(i, j);
        printf("ans = %d\n", ans);
        // 这里有个小bug， 就只管顺序，而不按照字典顺序了 
        while (i >= 0 && j >= 0) {
        	if (str[i] == strv[j]) {
        		res[index++] = str[i];
        		i--;
        		j--;
			}
        	else if (dp(i, j) == dp(i-1, j)) i--;
        	else j--;
		}
		for (int i = strlen(res)-1; i >= 0; i--) printf("%c", res[i]);
        printf("\n");
    }
    return 0;
}
