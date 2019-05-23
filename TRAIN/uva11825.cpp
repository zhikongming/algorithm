#include <cstdio>
using namespace std;

const int maxn = 16 + 5;
int P[maxn], cover[maxn*maxn];
int n;

int main() {
	while(scanf("%d", &n) == 1 && n) {
		for (int i = 0; i < n; i++) {
			int m;
			scanf("%d", &m);
			P[i] = (1<<i);
			for (int j = 0; j < m; j++) {
				int x;
				scanf("%d", &x);
				P[i] = P[i] | (1<<x);
			}
		}
		// 检查所有的可能性
		for (int s = 0; s < (1<<n); s++) {
			cover[s] = 0;
			for (int i = 0; i < n; i++) {
				if (s & (1<<i)) cover[s] |= P[i];
			}
		} 
		
		// f(s) = max(f(s-s0) | s0是s的子集， 并且cover[s0]等于全集)
	    f[0] = 0;
		int all = (1<<n) - 1;
		for (int s = 1; s < (1<<n); s++) {
			f[s] = 0;
			for (s0 = s; s0; s0 = (s0-1) & s) {
				if (cover[s0] == all) f[s] = max(f[s], f[s0^s]+1);
			} 
		} 
		printf("%d\n", f[all]);
	}
	return 0;
}  
