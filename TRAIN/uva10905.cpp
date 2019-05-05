#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
const int maxn = 50 + 5;
string A[maxn];

bool cmp(string a, string b) {
    return a+b > b+a;
}

int main() {
    while (cin>>n && n) {
        for (int i = 0; i < n; i++) {
            cin>>A[i];
        }

        sort(A, A+n, cmp);
        for (int i = 0; i < n; i++) cout<<A[i];
        cout<<endl;
    }
    return 0;
}
