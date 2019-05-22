#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 5;
const int INF = 10000000;
char str[maxn];
int d[maxn][26];
int g[maxn][26];

/*
 * 思路: 记d(i, j)为前i个分组达到块最小的数量, 并且最后一个字符为j(因为j会相应下一个分组的块的数量), 就可以实现状态转移
 *       一个组里面块最小, 那么同样的字符一定是排在一起的, 可以用前缀和的方式来记一下, 使用数组g
 */
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int k, groupn;
		scanf("%d %s", &k, str);
		groupn = strlen(str) / k;
        for (int i = 0; i < groupn; i++) {
            for (int j = 0; j < 26; j++) {
                g[i][j] = 0;
                d[i][j] = INF;
            }
        }

        // 遍历每个分组, 生成每个分组里面, 每个单词出现的次数的一个数组
        for (int i = 0; i < groupn; i++) {
            for (int j = i*k; j < (i+1)*k; j++) {
                int tmp = str[j] - 'a';
                g[i][tmp]++;
            }
        }

        // 开始计算d(i, j)
        for (int i = 0; i < groupn; i++) {
            int cnt = 0;
            for (int j = 0; j < 26; j++) {
                if (g[i][j] > 0) cnt++;
            }
            // 判断是不是前面有分组
            if (i > 0) {
                for (int j = 0; j < 26; j++) {
                    if (g[i-1][j] > 0) {
                        for (int m = 0; m < 26; m++) {
                            if (g[i][m] > 0) {
                                d[i][m] = min(d[i][m], d[i-1][j] + cnt + 1);
                                // 这一段很巧妙:
                                // 1. 如果j是上一个d的最后一个字符, 并且这个分组也有的话, 那么j排首位,剩下的字符排末尾, 均可以是的d[i][m]-1
                                // 2. 如果只有一个字符的话, j可以排在末尾,并且是的d[i][m]-1
                                if (g[i][j] > 0 && (m != j || (m == j && cnt == 1))) d[i][m]--;
                            }
                        }
                    }
                }
            } else {
                for (int j = 0; j < 26; j++) {
                    if (g[i][j] > 0) d[i][j] = cnt;
                }
            }
        }

        int ans = INF;
        for (int j = 0; j < 26; j++) {
            ans = min(d[groupn-1][j], ans);
        }

        printf("%d\n", ans);
	}
	return 0;
}
