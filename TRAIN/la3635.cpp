#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 5;
const double PI = acos(-1.0);

int n, f;
double area[maxn];

bool ok(double ar) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += floor(area[i] / ar);
	}
	return sum >= (f + 1);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int ri;
		scanf("%d%d", &n, &f);
		double maxa = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", ri);
			area[i] = PI * ri * ri;
			maxa = max(maxa, area[i]);
		}
		double l = 0, r = maxa;
		while (r-l > 1e-5) {
			double m = (l+r)/2;
			if (ok(m)) {
				l = m;
			} else {
				r = m;
			}
		}
		printf("%.5lf\n", l);
	}
	return 0;
}
