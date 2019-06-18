#include <cstdio>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    // p = a * x, q = b * x, p*q = x * y => a*b = y/x 并且 a, b 互为质数
    int s = y / x, count = 0;
    if (s * x == y) {
        int mid = (int)sqrt(s);
        int a = 1;
        while (a <= mid) {
            int b = s / a;
            if (a * b == s && gcd(a, b) == 1) count++;
            a++;
        }
    }
    printf("%d\n", count * 2);
    return 0;
}
