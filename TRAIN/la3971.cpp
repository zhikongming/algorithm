#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <string>
using namespace std;

struct Component {
	int price;
	int quality;
	Component(int p, int q):price(p),quality(q){
	}
};

map<string, int> tid;
int tidc = 0;
const int maxn = 1000 + 5; 
int n, b;// ����ĸ�����Ԥ�� 
vector<Component> compon[maxn]; // ÿ�����͵ķ���һ��vector���� 

// ���е�quality��������ڵ���q 
bool ok(int q) {
	int sum = 0;
	int cheapest = b + 1;// �п������еĶ���q�� 
	for (int i = 0; i < tidc; i++) {
		for (int j = 0; j < compon[i].size(); j++) {
			if (compon[i][j].quality >= q) cheapest = min(cheapest, compon[i][j].price); 
		}
		if (cheapest == b + 1) return false;
		sum += cheapest;
		if (sum > b) return false;
	}
	return true;
} 

int getTid(string s) {
	if (!tid.count(s)) {
		tid[s] = tidc;
		tidc++;
	}
	return tid[s];
}

int main() {
	int T;
	scanf("%d", &T);
	for (int kase = 0; kase < T; kase++) {
		scanf("%d %d", &n, &b);
		for (int i = 0; i < n; i++) {
			compon[i].clear();
		}
		tid.clear(); 
		int maxq = 0;
		for (int i = 0; i < n; i++) {
			char type[25], name[25];
			int price, quality;
			scanf("%s%s%d%d", type, name, &price, &quality);
			int id = getTid(type);
			maxq = max(maxq, quality);
			compon[id].push_back((Component){price, quality});
		}
		
		int l = 0, r = maxq;
		while (l < r) {
			int m = (l + r + 1) / 2;
			if (ok(m)) {
				l = m;
			} else {
				r = m - 1;
			}
		}
		printf("%d\n", l);
	}
	return 0;
} 
