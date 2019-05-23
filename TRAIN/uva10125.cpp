#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Choice {
	int a, b, sum;
	bool operator < (const Choice& ch) const {
		return sum < ch.sum;
	}
}; 

const int maxn = 1000 + 5;
int A[maxn], n, ans;
vector<Choice> data;

int mfind(int k) {
	int l = 0, r = data.size() - 1;
	int mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (k == data[mid].sum) {
			while(mid-1 >= 0 && data[mid-1].sum == k) mid--;
			return mid;
		} else if (data[mid].sum < k) l = mid + 1;
		else r = mid - 1;
	}
	return -1;
}

bool solve() {
	// �Ӻ���ǰö�٣� ����ҵõ��� dһ�������ġ� 
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (i != j) {
				// ���ֲ���һ��sum=A[i] - A[j]��
				int temp = A[i] - A[j];
				int index = mfind(temp);
				while (index != -1 && data[index].sum == temp) {
					if (A[i] != data[index].a && A[i] != data[index].a && A[j] != data[index].b && A[j] != data[index].b) {
						ans = A[i];
						return true;
					}
					index++;
				}
			}
		}
	}
	return false;
}

int main() {
	/*
	* 1. ö�ٷ��� ʱ�临�Ӷ���O(n^3), �ж��ڲ���set������Ҫ�����lg(n)ʱ�䣬 ����ʱ��ΪO(n^3*lgn) 
	* 2. ��;������������ö��a,b�������е�a+b��¼���������һ�����������Ȼ��ö��c,d�������ж����ַ���д��a+b����ʽ,
	*    ���������;��������˼�룬 ���Խ���ö�ٵ�ʱ�临�Ӷ� 
	*/ 
	while(scanf("%d", &n) == 1 && n) {
		int l = 0;
		for (int i = 0; i < n; i++) scanf("%d", &A[i]);
		sort(A, A + n);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				Choice ch = (Choice){A[i], A[j], A[i] + A[j]};
				data.push_back(ch);
			}
		}
		sort(data.begin(), data.end());
		if (solve()) printf("%d\n", ans);
		else printf("no solution\n");
	}
	return 0;
}
