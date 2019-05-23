#include <cstdio>
#include <set>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

// stringstream 很慢， string也很慢 
int next(int n, int x) {
	stringstream ss;
	long long k = (long long)x * x;
	ss<<k;
	string s = ss.str();
	if (s.length() > n) s = s.substr(0, n);
	int ans;
	stringstream ss2(s);
	ss2>>ans;
	return ans;
}

int buf[100];
int next2(int n, int x) {
	if (!k) return 0;
	long long k = (long long)x * x;
	int l = 0;
	while (k > 0) {
		buf[l++] = k % 10;
		k = k / 10;
	}
	if (n > l) n = l;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = ans * 10 + buf[--l];
	}
	return ans;
} 

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, k;
		scanf("%d %d", &n, &k);
		int ans = k;
//		set<int> s;
//		while (!s.count(k)) {
//			s.insert(k);
//			if (k > ans) ans = k;
//			k = next(n, k);
//		}

		// floyd 判圈算法
		int k1 = k, k2 = k
		do {
			k1 = next(n, k1);
			k2 = next(n, k2); if (k2 > ans) ans = k2;
			k2 = next(n, k2); if (k2 > ans) ans = k2;
		} while(k1 != k2)
		printf("%d\n", ans);
	}
	return 0;
}
