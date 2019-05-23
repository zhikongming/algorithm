#include <cstdio>
#include <iostream>
#include <string> 
#include <algorithm>
using namespace std;

/*
* ˼·�� sum[i] ��ʾǰi���У� ��ͬ��λ�õĸ����� ����Ҫ�ҵ�i < j, ���� sum[j]-sum[i] / j-i <= p/100
*        �Ƶ�һ�£� ��sum[j]*100 - p*j <= sum[i]*100-p*i, �����ݼ����� 
*        �������LIS���⣿ 
*/
const int maxn = 150000 + 5;
string A, B;
int k[maxn]; 

bool cmp(int i, int j) {
	return k[i] > k[j];
}

int main() {
	int n, p;
	while (scanf("%d%d", &n, &p) == 2 && n) {
		cin>>A;
		cin>>B;
		int sum = 0, tmp[maxn];
		for (int i = 0; i < n; i++) {
			if (A[i] != B[i]) sum++;
			k[i] = sum * 100 - p * i;
			tmp[i] = i;
		} 
		
		sort(tmp, tmp+n, cmp);
		
		int m = tmp[0], ans = 0;
		for (int i = 1; i < n; i++) {
			if (tmp[i] >= m && tmp[i] - m > ans) {
				ans = tmp[i] - m;// ����Ϊʲô����  tmp[i] - m + 1 �أ� ��Ϊsum��ԭ�� sum[i]���ų��˵�i�����˵ģ� ��i+1��ʼ������ 
			}
			m = min(m, tmp[i]);
		}
		if (ans == 0) {
			printf("No sulution.\n");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
} 
