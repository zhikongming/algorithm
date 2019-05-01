#include <cstdio>
using namespace std;

const int maxn = 10000;
int A[maxn], B[maxn];
int cmap[27];
int n;

void readstring(int* x) {
    int i = 0;
    char c = getchar();
    while (c >= 'A' && c <= 'Z' && c) {
        int v = c - 'A' + 1;
        x[i++] = v;
        c = getchar();
        n = i;
    }
}

int main() {
    readstring(A);
    readstring(B);
    int i = 0;
    bool ans = true;
    for (int i = 0; i < n; i++) {
        if (!cmap[A[i]]) cmap[A[i]] = B[i];
        else if (cmap[A[i]] != B[i]) ans = false;
    }
    printf("%s", ans ? "YES" : "NO");
    return 0;
}
