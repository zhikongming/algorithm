#include <iostream>

using namespace std;

const int maxn = 100 * 2 + 5;
const int M = 10001;
int T, x[maxn];

void solve

int main() {
    cin>>T;
    for (int i = 1; i <= 2*T-1; i += 2) {
        cin>>x[i];
    }
    solve();
    for (int i = 2; i <= 2 * T; i += 2) {
        cout<<x[i]<<endl;
    }
}
