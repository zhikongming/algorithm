#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

struct Point {
    int x, y, z, p, n1, n2;
};

struct Edge {
	Point from, to;
	double dis;
	bool operator < (const Edge& a) const {
		return dis < a.dis;
	}
}; 

const int maxn = 1000 + 5;
int n, en = 0;
double mindis;
Point A[maxn];
Edge E[maxn];

int main() {
    while (scanf("%d", &n) == 1) {
        int x, y, z, p;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d%d", &x, &y, &z, &p);
            A[i] = (Point){x, y, z, p, 1, 0};
            for (int j = 0; j < i; j++) {
                double dis = sqrt((A[i].x - A[j].x)*(A[i].x - A[j].x) + (A[i].y - A[j].y)*(A[i].y - A[j].y) + (A[i].z - A[j].z)*(A[i].z - A[j].z));
            	E[en++] = (Edge){A[j], A[i], dis};
			}
        }
        
        // 本题目有个特点， 边肯定为答案 
        sort(E, E+en);
        int count = 0, maxcount = 0;
        double ans = 0;
        for (int i = 0; i < en; i++) {
        	Edge e = E[i];
        	if (e.from.p == e.to.p) {
        		e.from.n1++;
        		// 新变成了稳定的点 
        		if (e.from.n1 == e.from.n2) count--; 
        		e.to.n1++;
        		if (e.to.n2 == e.to.n2) count--;
			} else {
				e.from.n2++;
				// 新变成的不稳定的点 
				if (e.from.n2 - e.from.n1 == 1) count++;
				e.to.n2++;
				if (e.to.n2 - e.to.n1 == 1) count++;
			}
			if ((i == en || E[i+1].dis != e.dis) && count > maxcount) {
				maxcount = count;
				ans = e.dis;
			}
		}
		printf("%d\n%f\n", maxcount, ans);
    }
    return 0;
}
