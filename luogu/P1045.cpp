#include <iostream>
#include <math.h>

using namespace std;

const int MAX = 500;

int main() {

    int p;
    cin>>p;
    int bits = 0;
    int lastNums[500] = {0};

    //cal bits
    bits = floor(p * log10(2)) + 1;
    cout<<bits<<endl;

    // 效率有点低, 尝试一下快速幂
    /*for (int i = 0; i < p; i++) {
        if (i == 0) {
            lastNums[MAX - 1] = 2;
        } else {
            bool addOne = false;
            for (int j = MAX - 1; j >= 0; j--) {
                int x = lastNums[j] * 2;
                if (addOne) x++;
                if (x >= 10) {
                    addOne = true;
                } else {
                    addOne = false;
                }
                lastNums[j] = x % 10;
            }
        }
    }*/

    // 快速幂计算2^p


    // subtract one
    bool suntractOne = false;
    for (int j = MAX - 1; j >= 0; j--) {
        int x = lastNums[j];
        if (j == MAX - 1) {
            x--;
        }
        if (suntractOne) {
            x--;
        }
        if (x < 0) {
            x += 10;
            lastNums[j] = x;
            suntractOne = true;
        } else {
            lastNums[j] = x;
            break;
        }
    }

    for (int i = 0; i < MAX; i++) {
        cout<<lastNums[i];
        if ((i + 1) % 50 == 0 && i != 0) {
            cout<<endl;
        }
    }
    /*for (int i = 0; i < MAX; i++) {
        if (lastNums[i] != 0) {
            cout<<lastNums[i];
            break;
        }
    }
    cout<<endl;*/

    return 0;
}
