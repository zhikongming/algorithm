#include <cstdio>
using namespace std;

int main() {
    int m;
    scanf("%d", &m);
    int mid = (1 + m) >> 1;
    int start = 0, end = 1;
    int sum = start + end;
    while (start < end && end <= mid) {
        if (sum == m) {
            printf("%d %d\n", start, end);
            sum -= start;
            start++;
        } else if (sum < m) {
            end++;
            sum += end;
        } else {
            sum -= start;
            start++;
        }
    }
    return 0;
}
