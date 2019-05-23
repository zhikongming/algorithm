#include <cstdio>
#include <map>
using namespace std;

int n;
map<pair<int, int>, int> data;

int main() {
	while (scanf("%d", &n) == 1 && n) {
		int a, b;
		data.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a, &b);
			pair<int, int> from, to;
			from = make_pair(a, b);
			to = make_pair(b, a);
			if (data.count(to) && data[to] > 0) {
				data[to]--;
			} else {
				if (!data.count(from)) data[from] = 0;
				data[from]++;
			}
		}
		
		bool match = true;
		for (map<pair<int, int>, int>::iterator it = data.begin(); it != data.end(); it++) {
			if (it->second != 0) {
				match = false;
				break;
			}
		}
		
		printf("%s\n", match ? "YES" : "NO");
	}
	return 0;
}
