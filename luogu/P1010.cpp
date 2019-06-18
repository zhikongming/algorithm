#include <iostream>
#include <map>

using namespace std;

map<int, string> cacheMap;

string fillNumber(int n) {
    int m = n;
    //cout<<"fill number "<<n<<endl;
    if (cacheMap.find(n) != cacheMap.end()) {
        //cout<<"cacheMap["<<n<<"] = "<<cacheMap[n]<<endl;
        return cacheMap[n];
    } else {
        string tmp = "";
        int a, b = 1, c = 0;
        while (m >= 1) {
            a = m % 2;
            if (a == 1) {
                string t = "";
                if (c > 1) {
                    t = "2(" + fillNumber(c) + ")";
                } else {
                    t = fillNumber(c);
                }
                if (tmp != "") {
                    tmp = t + "+" + tmp;
                } else {
                    tmp = t;
                }
            }
            b = b * 2;
            c = c + 1;
            m = m / 2;
        }
        cacheMap[n] = tmp;
        //cout<<"cacheMap["<<n<<"] = "<<cacheMap[n]<<endl;
        return tmp;
    }
}

int main() {
    // 本题可以使用动态规划来解
    int n;
    cin>>n;
    cacheMap[0] = "2(0)";
    cacheMap[1] = "2";
    string s = fillNumber(n);
    cout<<s<<endl;
    return 0;
}
