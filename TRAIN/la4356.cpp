#include <cstdio>
#include <cmath>
#include <algorithm> 
using namespace std;

struct Point {
	int x, y;
	double dis;
	bool operator < (const Point& p) const {
		return dis < p.dis;
	}
};

const int maxn = 5000 + 5;
Point A[maxn];
int n, k;

/*
* 思路: 1.找找距离来， 至少K个， 类似于一个滑动窗口 
        2.按照角度做一个排序 
*/
int main() {
	while (scanf("%d%d", &n, &k) == 2 && n) {
		int x, y;
		double dis;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);
			dis = sqrt(x*x, y*y);
			A[i] = (Point){x, y, dis};
		}
		sort(A, A+n);
	}
	return 0;
}
