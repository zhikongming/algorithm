#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int g;
    int p;
    Item(int g = 0, int p = 0): g(g), p(p) {}
};

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n, ans = 0;
    cin>>n;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin>>A[i];
    }
    vector<Item> items;
    for (int j = 0; j < n; j++) {
        items.push_back(Item(0, j));
        cout<<"j = "<<j<<endl;
        for (int i = 0; i < items.size(); i++) {
            // cal i ~ j gcd
            items[i].g = gcd(items[i].g, A[j]);
        }

        vector<Item> newItems;
        for (int i = 0; i < items.size(); i++) {
            if (i == 0 || items[i].g != items[i - 1].g) {
                newItems.push_back(items[i]);
                ans = max(ans, items[i].g * (j - items[i].p + 1));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
