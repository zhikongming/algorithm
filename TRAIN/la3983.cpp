#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 5;
int n, c;
int dist_total[maxn], x[maxn], y[maxn], weight_total[maxn], dist_origin[maxn];
int q[maxn], d[maxn];

int f(int i) {
	return d[i] - dist_total[i+1] + dist_origin(i+1);
}

int main() {
	int T, w, front, end;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &c, &n);
		dist_total[0] = weight_total[0] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &x[i], &y[i], &w);
			dist_total[i] = dist_total[i-1] + abs(x[i]-x[i-1]) + abs[y[i]-y[i-1]];
			weight_total[i] = weight_total[i-1] + w;
			dist_origin[i] = abs(x[i]) + abs(y[i]);
		}
		
		// »¬¶¯´°¿Ú O(n)
		front = end = 1;
		for (int i = 1; i <= n; i++) {
			while (front <= end && weight_total[i] - weight_total[q[front]] > c) front++;
			d[i] = f(q[i]) + dist_total[i] + dist_origin(i);
			while (front <= end && f(i) > f(q[end])) end--;
			q[++end] = i;
		}
		
		print("%d\n", d[n]);
	}
	return 0;
} 
