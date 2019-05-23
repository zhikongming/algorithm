#include <cstdio>
using namespace std;

const int maxn = 100000 + 5;
int A[maxn], n, S;

//O(n^3)
int solve() {
	int ans = n + 1;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			for (int k = i; k <= j; k++) sum += A[k];
		}
		if (sum > S) ans = min(ans, j - i + 1);
	}
	return ans;
}

int solve2() {
	int ans = n + 1;
	int B[n];
	for (int i = 0; i < n; i++) {
		B[i] = A[i];
		if (i > 0) B[i] += B[i - 1];
	}
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			if (i == 0) sum = B[j];
			else sum = B[j] - B[i-1];
		}
		if (sum > S) ans = min(ans, j - i + 1);
	}
	return ans;
}

int solve3() {
	int ans = n + 1;
	int B[n];
	for (int i = 0; i < n; i++) {
		B[i] = A[i];
		if (i > 0) B[i] += B[i - 1];
	}
	for (int j = 0; j < n; j++) {
		int i = lower_bound(B, B + j, B[j]-S) - B;// 这里是个二分 
		if (i >= 0) ans = min(ans, j - i + 1);
	}
	return ans;
}

int solve4() {
	int ans = n + 1;
	int B[n];
	for (int i = 0; i < n; i++) {
		B[i] = A[i];
		if (i > 0) B[i] += B[i - 1];
	}
	int i = 0;
	for (int j = 0; j < n; j++) {
		if (B[i-1] > B[j] - S) continue;
		while(B[i-1] <= B[j] - S) i++;
		ans = min(ans, j-i+1);
	} 
	return ans;
} 

int main() {
	while(scanf("%d%d", &n, &S) == 2) {
		for (int i = 0; i < n; i++) scanf("%d", &n);
		int ans;
		ans = solve();
		ans == n + 1 ? 0 : ans;
	}
	return 0;
}
