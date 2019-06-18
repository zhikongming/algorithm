#include <iostream>
#include <stack>

using namespace std;

/*
 * @string a
 * @string b, get the max string.
 * @return, return the max string.
 */
string getCommonString(string a, string b) {
    string returnStr = "";
    for (int i = 0; i < a.length(); i++) {
        if (a.length() - i > b.length()) {
            continue;
        }
        if (a.substr(i, a.length()) == b.substr(0, a.length() - i) && i != 0 && (a.length() - i) != b.length()) {
            returnStr = a.substr(i, a.length());
        }
    }
    return returnStr;
}

int main() {
    // init source data
    int n;
    cin>>n;
    string arr[n];
    int num[n];
    string root;
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
        num[i] = 2;
    }
    cin>>root;

    // calculate the data
    int maxLength = 0;
    int tmpLength = 0;
    stack<int> strStack;
    for (int i = 0; i < n; i++) {
        if (root[0] == arr[i][0]) {
            strStack.push(i);
            num[i]--;
            tmpLength += arr[i].length();
            int lastIndex = -1;
            while (!strStack.empty()) {
                // check whether another word match.
                bool getMatchItem = false;
                int startIndex = 0;
                if (lastIndex != -1) {
                    startIndex = lastIndex + 1;
                }
                for (int i = startIndex; i < n; i++) {
                    if (num[i] > 0) {
                        string commonStr = getCommonString(arr[strStack.top()], arr[i]);
                        if (commonStr.length() > 0) {
                            strStack.push(i);
                            // cout<<"push "<<arr[i]<<endl;
                            num[i]--;
                            tmpLength += arr[i].length() - commonStr.length();
                            getMatchItem = true;
                            break;
                        }
                    }
                }
                if (maxLength <= tmpLength) {
                    maxLength = tmpLength;
                }

                if (!getMatchItem) {
                    lastIndex = strStack.top();
                    strStack.pop();
                    //cout<<"pop "<<arr[lastIndex]<<endl;
                    num[lastIndex]++;
                    if (strStack.empty()) {
                        tmpLength = 0;
                    } else {
                        string lastCommonString = getCommonString(arr[strStack.top()], arr[lastIndex]);
                        tmpLength -= arr[lastIndex].length() - lastCommonString.length();
                    }
                } else {
                    lastIndex = -1;
                }
            }
        }
    }
    cout<<maxLength<<endl;
}
