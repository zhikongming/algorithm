#include <cstdio>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;
bool flag = false;
struct choice {
	vector<int> ans;
	set<int> next;
};

int main() {
    while (scanf("%d%d", &m, &n) == 2 && m) {
        // f1: loop all the num and check
        // f2: the first num will affect the next num
        flag = false;
        queue<choice> Q;
        // choose the first num
        for (int i = 0; i < n; i++) {
        	choice ch;
        	ch.ans.push_back(i);
        	for (int j = 2; j <= m; j++) {
        		int num = (i * j % n);
        		ch.next.insert(num);
			}
			Q.push(ch);
		}
		
		// loop the next number
		while (!Q.empty()) {
			choice ch = Q.front();
			Q.pop();
			if (ch.ans.size() == m) {
				set<int> ans;
				for (vector<int>::iterator it = ch.ans.begin(); it != ch.ans.end(); it++) {
					ans.insert(*it);
				}
				if (ans.size() == ch.next.size()) {
					reverse(ch.ans.begin(), ch.ans.end());
					for (vector<int>::iterator it = ch.ans.begin(); it != ch.ans.end(); it++) {
						printf("%d ", *it);
					}
					printf("\n");
					flag = true;
					break;
				}
			} else {
				for (int i = 0; i < n; i++) {
					choice p = ch;
					if (ch.ans.size() == m - 1 && (i == 0 || i * m > n)) continue;
					// i will be the next number, but first check the adding.
					for (int j = 2; j <= m; j++) {
						int adding = 0;
						for (vector<int>::iterator it = p.ans.begin(); it != p.ans.end(); it++) {
							adding = (*it * j + adding) / n;
						}
						p.next.insert((i * j + adding) % n);
					}
					if (p.next.size() <= m) {
						p.ans.push_back(i);
						Q.push(p);
					}
				}
			}
		}
		if (!flag) printf("Not found.");
    }
    return 0;
}
