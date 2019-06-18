#include <cstdio>
using namespace std;

void zhuan(int n, int r) {
    if (n == 0) return;
    int yu = n % r;
    int s = n / r;
    if (yu < 0) {
        yu -= r;
        s++;
    }

    char printc;
    if (yu >= 10) printc = 'A' + yu - 10;
    else printc = '0' + yu;

    zhuan(s, r);
    printf("%c", printc);
}

int main() {
    int n, r, absr;
    scanf("%d%d", &n, &r);
    printf("%d=", n);
    zhuan(n, r);
    printf("(base%d)", r);
    return 0;
}
