#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 500000 + 5;
int A[maxn];
int n;

bool cmp(int a, int b) {
    return abs(a) < abs(b);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    sort(A, A+n, cmp);
    int ans = 0, last = 0, cur;
    for (int i = 0; i < n; i++) {
        if (A[i] > 0) cur = 1;
        else cur = 0;
        if (i != 0) {
            if (cur^last) {
                ans++;
                last = cur;
            }
        } else {
            ans++;
            last = cur;
        }
    }

    printf("%d\n", ans);
    return 0;
}
