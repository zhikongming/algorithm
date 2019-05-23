#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 5;
int n, dep = 0, temp[maxn], top = 0;

// ��ʾ������dep�£� ��ǰ���cur��������������㷨
// x��ʾ��ǰ����ֵ 

bool checkin(int k) {
	for (int i = 0; i <= top; i++) {
		if (temp[i] == k) return true;
	}
	return false;
}

bool dfs(int cur, int x) {
	//printf("try: cur = %d, x = %d, dep = %d, n = %d\n", cur, x, dep, n);
	if (cur > dep) return false;
	if (x == n) return true;
	int maxp = 0;
	for (int i = 0; i <= top; i++) {
		maxp = max(maxp, temp[i]);
	}
	if (x + maxp<<(dep - cur) < n) return false;
	// x��i֮��Ĳ���Ϊ+ ���� - 
	for (int i = 0; i <= top; i++) {
		// ���뱣֤x�Ƚϴ�����ü��� 
		if (x > temp[i] && !checkin(x - temp[i])) {
			temp[++top] = x - temp[i];
			if (dfs(cur + 1, x - temp[i])) return true;
			top--;
		} 
		// ����һ�¼ӷ�
		if (!checkin(x + temp[i])) {
			temp[++top] = x + temp[i];
			if (dfs(cur + 1, x + temp[i])) return true;
			top--;
		}
	}
	return false;
}

int main() {
	// ���غ�xûʲô��ϵ�� ֻ��Ҫָ���ļӼ�����
	// ���彫���õ��������������㷨�����м��� 
	scanf("%d", &n);
	if (n != 1) {
		while (true) {
			memset(temp, 0, sizeof(temp));
			temp[0] = 1;
			top = 0;
			dep++;
			bool res = dfs(0, 1);
			if (res) {
				break;
			}
		}
	}
	printf("%d\n", dep);
	return 0;
} 
