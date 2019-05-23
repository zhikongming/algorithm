#include <cstdio>
using namespace std;

const int maxn = 100000 + 5;
char str[maxn];
int A[maxn], sum[maxn], k[maxn];

double getAve(int i, int j) {
	double res = double(sum[j] - sum[i-1]) / (j - i + 1);
	return res;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, l;
        scanf("%d%d%s", &n, &l, str);
        sum[0] = 0;
        for (int i = 1; i <= n; i++) {
            char ch = str[i-1];
            if (ch == '0') A[i] = 0;
            else A[i] = 1;
            sum[i] = sum[i-1] + A[i];
        }
        // å…¶å®æ‰¾çš„å°±æ˜¯ (sum[j] - sum[i-1]) / (j - i + 1) çš„æ–œç‡
        // æ•°å½¢ç»“åˆ, éœ€è¦ç§»é™¤å‡¸ç‚¹
        int ansl = 1, ansr = l; // ½á¹ûµÄ×óÓÒ¶Ëµã 
		int i = 0, j = 0; // µ¥µ÷¶ÓÁĞµÄ×óÓÒ 
        for (int m = l; m <= n; m++) {
            // mÎªĞÂÒıÈëµÄµã£¬ ÅĞ¶ÏÒ»ÏÂk[j-2], k[j-1], m-lÕâÈı¸öµãµÄĞ±ÂÊ£¬¿´¿´ÓĞÃ»ÓĞ³öÏÖÍ¹µã
			while (i < j - 1 && getAve(k[j-2], k[j-1]) > getAve(k[j-1], m-l)) j--;// ³öÏÖÁËÍ¹µã 
			k[j] = m - l + 1;
			j++; 
			
			// ²éÕÒÒÔ t ½áÎ²µÄµã£¬ ×öÒ»¸öÇĞÏßÇóµÃµÄ×î´óĞ±ÂÊ
			while (i < j - 1 && getAve(k[i+1], m) > getAve(k[i], m)) i++;
			
			double tk = getAve(k[i], m);
			double ori = getAve(ansl, ansr);
			if (ori < tk || (tk == ori && m - k[i] < ansr - ansl)) { // ori < tk, m - k[i] < ansr - ansl ±íÊ¾¸ü¶Ì 
				ansl = k[i];
				ansr = m; 
			}
        }
        
        printf("%d %d\n", ansl, ansr);
    }
    return 0;
}
