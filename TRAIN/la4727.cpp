#include <cstdio>
#include <list>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        // 约瑟夫环的数学解法, 时间复杂度为 O(n)
        int last = 0;
        for (int i = 2; i <= n; i++) {
            last = (last + k) % i;
        }
        printf("%d\n", last + 1);
        // last + 1 为最后一个留下的数字, 那么

        // 模拟约瑟夫环的解法, 时间复杂度为O(n * k)
        /*
        list<int> data;
        for (int i = 1; i <= n; i++) data.push_back(i);
        list<int>::iterator ite = data.begin();
        while (data.size() > 0) {
            for (int i = 1; i < k; i++) {
                ite++;
                if (ite == data.end()) ite = data.begin();
            }
            list<int>::iterator next = ite;
            next++;
            if (next == data.end()) next = data.begin();
            if (data.size() <= 3) printf("%d ", *ite);
            data.erase(ite);
            ite = next;
        }
        printf("\n");
        */
    }
    return 0;
}
