#include <cstdio>
using namespace std;

const int maxn = 60 + 5;
int n, start[maxn], finish[maxn];

// ��P�У� ǰk��Ų��finalȥ 
long long f(int* P, int k, int final) {
	if (k == 0) return 0;
	if (P[k] == final) return f(P, k - 1, final);
	return f(P, k - 1, 6 - P[k] - final) + (1LL << (k - 1)) - 1 + 1; // �������ǣ� ����ĺ�ŵ����k-1��Ų��һ����ȥ�� 2^n - 1, �������һ��move�Ĳ����� 
} 

int main() {
	int kase = 0;
	while (scanf("%d", &n) == 1 && n) {
		for (int i = 0; i < n; i++) scanf("%d", &start[i]);
		for (int i = 0; i < n; i++) scanf("%d", &finish[i]);
		int k = n;
		while (k >= 0 && start[k] == finish[k]) k--;

		long long ans = 0;
		if (k >= 0) {
			int other = 6 - start[k] - finish[k];// ������other�������
			ans +=  f(start, k - 1, other) + 1 + f(finish, k - 1, other);// finish �����ʵ�Ƿ������ģ� ��ʵ�ǲο�״̬���Ŀ��״̬ 
		}
		printf("Case %d: %lld\n", ++kase, ans);
	}
}
