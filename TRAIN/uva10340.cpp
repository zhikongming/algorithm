#include <cstdio>
using namespace std;

const int maxn = 10000;
char s[maxn], t[maxn];

int main() {
	int sn = -1, tn = -1;
	char c = getchar();
	while (c != '\n') {
		s[++sn] = c;
		c = getchar();
	}
	
	c = getchar();
	while (c != '\n') {
		t[++tn] = c;
		c = getchar();
	}

	bool ans = false;
	while (sn >= 0 && tn >= 0) {
		if (s[sn] == t[tn]) {
			sn--;
			tn--;
		} else {
			sn--;
		}
		if (tn < 0) {
			ans = true;
			break;
		}
	}
	printf("%s", ans ? "YES" : "NO");
	return 0;
} 
