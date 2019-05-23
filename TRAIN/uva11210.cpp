#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 34;
int n;
char* majiang[maxn] = {
	"1T","2T","3T","4T","5T","6T","7T","8T","9T",
	"1S","2S","3S","4S","5S","6S","7S","8S","9S",
	"1W","2W","3W","4W","5W","6W","7W","8W","9W",
	"DONG","NAN","XI","BEI","ZHONG","FA","BAI" 
};
int c[34];

int convert(char* s) {
	for (int i = 0; i < maxn; i++) {
		if (strcmp(majiang[i], s) == 0) {
			return i;
		}
	}
	return -1;
}

bool search(int times) {// times Ϊ���ٵĴ����� ÿ�μ��������Ӷ��� ˳�ӻ��������� 12/3=4�� �ܹ�ֻ�ܼ����Ĵ�
	for (int i = 0; i < 34; i++) {
		if (c[i] >= 3) {
			if (times == 3) return true;
			c[i] -= 3;
			if (search(times+1)) return true;
			c[i] += 3;
		}
	}
	// ���������߹��ˣ� �����ֻ��˳����, ���ҵ�ǰ�Ӷ���С�� 3*9 - 3 = 24 
	for (int i = 0; i <= 24; i++) {
		if (i % 9 <= 6 && c[i] >= 1 && c[i+1] >= 1 && c[i+2] >= 1) {// T S W ���棬 ֻ��ǰ�߸��ſ��Գ�˳�ӵ�ͷ�� 
			if (times == 3) return true;
			c[i]--;c[i+1]--;c[i+2]--;
			if (search(times+1)) return true;
			c[i]++;c[i+1]++;c[i+2]++;
		} 
	} 
	return false;
}

bool check() {
	for (int i = 0; i < 34; i++) {
		if (c[i] >= 2) {//��һ���Ƶ��ɽ��� 
			c[i] -= 2;
			bool flag = search(0);
			if (flag) {
				return true;
			}
			c[i] += 2;// �ָ����� 
		}
	}
	return false;
}

int main() {
	int kase = 0, i, j;
	int mj[14];
	char s[100];
	bool flag = false;// whether win.
	while (scanf("%s", &s) == 1) {
		if (s[0] == '0') break;
		printf("\nCase %d:", ++kase);
		mj[0] = convert(s);
		for (i = 1; i < 13; i++) {
			scanf("%s", &s);
			mj[i] = convert(s);
		}
		
		for (int i = 0; i < 34; i++) {
			memset(c, 0, sizeof(c));
			for (int j = 0; j < 13; j++) {
				c[mj[j]]++;
			}
			// ����һ�������ƣ� �ж��ǲ��Ǻ��� 
			if (c[i] == 4) continue;
			c[i]++;
			if (check()) {
				flag = true;
				printf("%s ", majiang[i]);
			}
			c[i]--; 
		}
		if (!flag) {
			printf("Not Ready!");
		}
	}
	return 0;
}
