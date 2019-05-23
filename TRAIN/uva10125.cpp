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
	// 从后往前枚举， 如果找得到， d一定是最大的。 
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (i != j) {
				// 二分查找一下sum=A[i] - A[j]的
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
	* 1. 枚举法： 时间复杂度是O(n^3), 判断在不在set里面需要额外的lg(n)时间， 总体时间为O(n^3*lgn) 
	* 2. 中途相遇法：首先枚举a,b，把所有的a+b记录下来存放在一个有序数组里，然后枚举c,d，看看有多少种方法写成a+b的形式,
	*    这个就是中途相遇法的思想， 可以降低枚举的时间复杂度 
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
