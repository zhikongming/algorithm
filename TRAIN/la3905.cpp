#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 5;
struct Event {
	double x;
	int type;
	bool operator < (const Event& a) const {
		return x < a.x || (x == a.x && type > a.type);
	}
} events[maxn*2];

void update(int x, int a, int w, double& l, double& r) {
	if (a == 0) {
		if (x <= 0 || x >= w) r = l - 1;
	} else if (a > 0) {
		l = max(l, -(double)x/a);
		r = min(r, (double)(w-x)/a);
	} else {
		l = max(l, (double)(w-x)/a);
		r = min(r, -(double)x/a);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	int w, h, n;
	scanf("%d%d", &w, &h);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y, a, b;
		scanf("%d%d%d%d", &x, &y, &a, &b);
		double l = 0, r = 1e9;
		update(x, a, w, l, r);
		update(y, b, h, l, r);
		int e = 0;
		if (r > l) {
			events[e++] = (Event) {l, 0};
			events[e++] = (Event) {r, 1};
		}
		sort(events, events + e);
		int cnt = 0, ans = 0;
		for (int j = 0; j < e; j++) {
			if(events[j].type == 0) {
				cnt++;
				ans = max(ans, cnt);
			} else {
				cnt--;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
} 
