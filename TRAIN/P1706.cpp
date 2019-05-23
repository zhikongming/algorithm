#include <cstdio>
#include <cstring>
using namespace std;

int n;
int temp[10];
int used[10];

void f(int i) {
	if (i == n) {
		for (int j = 0; j < n; j++) {
			printf("%5d", temp[j]);
		}
		printf("\n");
	} else {
		for (int j = 1; j <= n; j++) {
			if (!used[j]) {
				temp[i] = j;
				used[j] = 1;
				f(i+1);
				used[j] = 0;// 下一次选的是j+1了 
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	memset(used, 0, sizeof(used));
	f(0);
	return 0;
}
