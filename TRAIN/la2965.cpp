#include <cstdio>
#include <map>
using namespace std;

const int maxn = 24;
map<int, int> tab;

// 返回二进制中的1的个数
int bitcount(int x) {
    return x == 0 ? 0 : bitcount(x / 2) + (x & 1);
}

int main() {
    int n, A[maxn];
    char str[1000];
    while (scanf("%d", &n) == 1 && n) {
        for (int i = 0; i < n; i++) {
            scanf("%s", str);
            A[0] = 0;
            for (int j = 0; str[j] != '\0'; j++) A[i] ^= (1<<(str[j] - 'A'));
        }

        // 1. 粗暴一点, 有个2^n的枚举方案, 这个方案就不写了,采用一个更高效的方案
        // 2. 更优的方案: 把n个字符串拆分为n/2
        int n1 = n / 2, n2 = n - n1;
        tab.clear();
        for (int i = 0; i < (1<<n1); i++) {
            int x = 0;
            for (int j = 0; j < n1; j++) {
                if (i & (1<<j)) x ^= A[j];// 这里是一种方案
            }
            // 把这个方案加到tab里面去
            if(!tab.count(x) || bitcount(tab[x]) < bitcount(i)) tab[x] = i;
        }

        // 枚举后半部分
        int ans = 0;
        for (int i = 0; i < (1<<n2); i++) {
            int x = 0;
            for (int j = 0; j < n2; j++) {
                if (i & (1<<j)) x ^= A[j + n1];
            }
            // 一个新的方案 x is one choice.
			// if you want to make all to 0, the x must has been in tab.
			// the bitcount(tab[x]) + bitcount(i) > bitcount(ans), update ans
			if (tab.count(x) && (bitcount(tab[x]) + bitcount(i)) > bitcount(ans)) {
				ans = (i<<n1)^tab[x];
			}
        }
        
        printf("%d\n", bitcount(ans));
		for (int i = 0; i < n; i++) {
			if (ans & (1<<i)) printf("%d ", i + 1);
		}
		printf("\n");
    }
    return 0;
}
