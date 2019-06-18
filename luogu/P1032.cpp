#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int main() {
    // init source data
    string sourceStrA, sourceStrB;
    cin>>sourceStrA>>sourceStrB;
    int n = 6;
    string a[n], b[n];
    char name[256];
    int i = 0;
    cin.getline(name, 256);
    while(cin.getline(name, 256) && strlen(name) > 0) {
        int spaceIndex;
        for (int j = 0; j < strlen(name); j++) {
            if (name[j] == ' ') {
                spaceIndex = j;
                break;
            }
        }
        char ta[spaceIndex];
        for (int j = 0; j < spaceIndex; j++) {
            ta[j] = name[j];
        }
        a[i] = string(ta);
        char tb[strlen(name) - spaceIndex];
        for (int j = 0; j < strlen(name) - spaceIndex; j++) {
            tb[j] = name[spaceIndex + 1 + j];
        }
        b[i] = string(tb);
        i++;
    }
    n = i;

    // cal the data
    queue<string> que;
    int maxCount = 10;
    queue<string> queArr[maxCount + 1];
    que.push(sourceStrA);
    queArr[0] = que;

    bool found = false;
    for (int i = 0; i < maxCount + 1; i++) {
        que = queArr[i];
        queue<string> tmpQue;
        while (!que.empty()) {
            string tmpStr = que.front();
            que.pop();
            for (int j = 0; j < n; j++) {
                if (tmpStr.find(a[j]) != string::npos) {
                    string t = tmpStr;
                    t.replace(tmpStr.find(a[j]), a[j].length(), b[j]);
                    //cout<<tmpStr<<" to "<<t<<" by "<<a[j]<<","<<b[j]<<endl;
                    if (t == sourceStrB) {
                        found = true;
                        break;
                    }
                    tmpQue.push(t);
                }
            }
            if (found) {
                break;
            }
        }
        if (found) {
            cout<<i + 1;
            return 0;
        }
        if (i + 1 < maxCount) {
            queArr[i + 1] = tmpQue;
        }
        //cout<<"step "<<i<<endl;
    }

    cout<<"NO ANSWER!";
    return 0;
}
