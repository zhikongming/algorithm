#include <iostream>

using namespace std;

void gcd(int a, int b, int& x, int& y, int &d) {
    if (!b) {
        d = a;
        x = 1;
        y = 0;
    } else {
        gcd(b, a%b, y, x, d);
        y -= x * (a / b);
    }
}

int main() {
    int a = 6, b = 15, x, y, d;
    gcd(a, b, x, y, d);
    cout<<"x = "<<x<<", y = "<<y<<", d ="<<d<<endl;
}
