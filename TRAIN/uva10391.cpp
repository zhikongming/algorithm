#include <iostream>
#include <map>
#include <string>
using namespace std;

const int maxn = 120000 + 5;
string s[maxn];
map<string, bool> mmap;

int main() {
	int i = 0;
	while (cin>>s[i]) {
		mmap[s[i]] = true;
		i++;
	}
	
	for (int k = 0; k < i; k++) {
		for (int l = 1; l < s[k].size(); l++) {
			string left = s[k].substr(0, l);
			string right = s[k].substr(l);
			if (mmap[left] && mmap[right]) {
				cout<<s[k]<<endl;
				break;
			}
		}
	}
	return 0;
}
