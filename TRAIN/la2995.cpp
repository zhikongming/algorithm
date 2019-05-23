#include <iostream>
using namespace std;

const int maxn = 10;
const int viewNum = 6;
char view[maxn][maxn][maxn];
char pos[maxn][maxn][maxn];
int n; 

char read_char() {
	char ch;
	while (true) {
		ch = getchar();
		if ((ch >= 'A' && ch <= 'Z') || ch == '.') {
			return ch;
		}
	}
}

// 坐标系和题解保持一样， 方便check 
void get(int k, int i, int j, int len, int& x, int& y, int& z) {
	switch(k) {
		case 0:
			x = len;y = j;z = i;
			break;
		case 1:
			x = n-j-1;y = len;z = i;
			break;
		case 2:
			x = n-len-1;y = n-j-1;z = i;
			break;
		case 3:
			x = j; y = n-len-1; z = i;
			break;
		case 4:
			x = n-1-i; y = j; z = len;
			break;
		case 5:
			x = i; y = j; z = n-len-1;
			break;
	}
}

int main() {
	while (scanf("%d", &n) == 1 && n) {
		for (int a = 0; a < n; a++) {
		 	for (int b = 0; b < 6; b++) {
		 		for (int c = 0; c < n; c++) {
		 			view[b][a][c] = read_char();
				}
			}
		}

		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
			 	for (int c = 0; c < n; c++) {
			 		pos[a][b][c] = '#';
				}
			}
		}
		// delete the invalid place
		for (int a = 0; a < 6; a++) {
			for (int b = 0; b < n; b++) {
				for (int c = 0; c < n; c++) {
					// check '.', it means no place
					if (view[a][b][c] == '.') {
						for (int d = 0; d < n; d++) {
							// get the invalid point.
							int x, y, z;
							get(a, b, c, d, x, y, z);
							pos[x][y][z] = '.';
						}
					}
				}
			}
		}
		
		// check the color 
		while (true) {
			bool done = true;
			for (int a = 0; a < 6; a++) {
				for (int b = 0; b < n; b++) {
					for (int c = 0; c < n; c++) {
						if (view[a][b][c] != '.') {
							for (int d = 0; d < n; d++) {
								int x, y, z;
								get(a, b, c, d, x, y, z);
								if (pos[x][y][z] == '.') continue;
								if (pos[x][y][z] == '#') {
									pos[x][y][z] = view[a][b][c];
									break;
								}
								if (pos[x][y][z] == view[a][b][c]) break;
								pos[x][y][z] = '.';
								done = false;
							}
						}
					}
				}
			}
			if (done) break;
		}
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				for (int c = 0; c < n; c++) {
					printf("(%d,%d,%d) = %c\n", a, b, c, pos[a][b][c]);
				}
			}
		}
		// print the place
		int ans = 0;
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				for (int c = 0; c < n; c++) {
					if (pos[a][b][c] != '.') ans++;
				}
			}
		}
		printf("Maximum weight: %d gram(s)\n", ans);
	}
	return 0;
}
