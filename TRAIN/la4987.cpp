#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 4000 + 5;
int a[maxn], b[maxn], d[maxn][maxn];
int n, m;

int dp(int peoplePos, int shelterPos) {
    printf("peoplePos = %d, shelterPos = %d\n", peoplePos, shelterPos);
    if (d[peoplePos][shelterPos]) return d[peoplePos][shelterPos];
    if (peoplePos == 0 || shelterPos == 0) return 0;
    // 保证每个避难所都有人在
    if (peoplePos == shelterPos) {
        d[peoplePos][shelterPos] =  dp(peoplePos-1, shelterPos-1) + abs(a[peoplePos-1] - b[shelterPos-1]);
    } else {
        if (shelterPos == 1) {
            d[peoplePos][shelterPos] = dp(peoplePos-1, shelterPos) + abs(a[peoplePos-1] - b[shelterPos-1]);
        } else {
            d[peoplePos][shelterPos] = min(dp(peoplePos-1, shelterPos-1), dp(peoplePos-1, shelterPos)) + abs(a[peoplePos-1] - b[shelterPos-1]);
        }
    }
    return d[peoplePos][shelterPos];
}

int main() {
    memset(d, 0, sizeof(d));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    sort(a, a+n);
    sort(b, b+m);
    dp(n, m);
    printf("%d\n", d[n][m]);
    return 0;
}
