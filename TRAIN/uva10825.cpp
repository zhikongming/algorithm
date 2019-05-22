#include <cstdio>
#include <set>
#include <queue>
#include <vector>
using namespace std;

int m, n;

int main() {
    while (scanf("%d%d") == 3 && m) {
        queue< vector<int> > Q;
        for (int i = 0; i < n; i++) {
            vector<int> s;
            s.push_back(i);
            Q.push(s);
        }

        while (!Q.empty()) {
            vector<int> s = Q.front();
            Q.pop();
            if (s.size() == m) {
                bool res = check(s);
                if (res) {
                    printf("yes");
                    break;
                }
            } else {
                for (int i = 0; i < n; i++) {
                    // 最大的数值, num * m > n 的话, 肯定不符合的, 都不用考虑了
                }
            }
        }
    }
    return 0;
}
