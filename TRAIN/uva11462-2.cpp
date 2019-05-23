#include <cstdio>
#include <cstring>
using namespace std;

int readint() {
	char c = getchar();
	while(!isdigit(c)) c = gerchar();
	int x = 0;
	while(isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}

int buf[10];
void writeint(int i) {
	int p = 0;
	if (i == 0) p++;
	else while (i) {
		buf[p++] = i % 10;
		i = p / 10;
	}
	for (int j = p - 1; j >= 0; j--) {
		putchar('0' + buf[j]);
	}
}

int main() {
	int n, c[101];
	while(n = readint()) {
		memset(c, 0, sizeof(c));
		for (int i = 0; i < n; i++) {
			c[readint()]++;
		}
		for (int i = 1; i <= 100; i++) {
			for (int j = 0; j < c[i]; j++) {
				writeint(i);
			}
		}
	}
	return 0;
} 
