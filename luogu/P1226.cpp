#include <iostream>

using namespace std;

int b, p, k;
long int result;

int main() {
    cin>>b>>p>>k;
    long long int tmpsub = 1, tmpadd = b;
    int m, pbr = p;
    // (a * b) % k => a%k * b%k
    while (p >= 1) {
        m = p % 2;
        if (m == 1) {
            tmpsub = tmpsub * (tmpadd % k);
            tmpsub = tmpsub % k;
            //cout<<"tmpsub = "<<tmpsub<<endl;
        }
        tmpadd = tmpadd % k;
        tmpadd = tmpadd * tmpadd;
        p = p / 2;
        //cout<<"p = "<<p<<endl;
    }
    tmpsub = tmpsub % k;
    cout<<b<<"^"<<pbr<<" mod "<<k<<"="<<tmpsub<<endl;
    return 0;
}
