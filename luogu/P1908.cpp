#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct segTree {
    int left;
    int right;
    int data;
};

int n;
const int MAXN = 500000;
int data[MAXN];
int B[MAXN]; // 离散化之后的数据, 其实就是存储的第几大
int C[MAXN]; // 存储树状数组
int D[MAXN];
long long int countN = 0;
segTree tree[2 * MAXN + 2];

/*
 * loop the all data
 * O(n^2)
 */
void fun1() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (data[i] > data[j]) {
                countN++;
            }
        }
    }
}

/*
 * merge sort
 * O(nlgn)
 */
void mergeSort(int left, int right) {
    if (left >= right) {
        return ;
    }
    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    int i = left, j = mid + 1;
    int tmpArr[right - left + 1];
    int k = 0;
    while (i <= mid && j <= right) {
        if (data[i] <= data[j]) {
            tmpArr[k] = data[i];
            k++;
            i++;
        } else {
            tmpArr[k] = data[j];
            k++;
            j++;
            countN += (mid -i + 1);
        }
    }
    while (i <= mid) {
        tmpArr[k] = data[i];
        k++;
        i++;
    }
    while (j <= right) {
        tmpArr[k] = data[j];
        k++;
        j++;
    }
    for (int m = 0; m < right - left + 1; m++) {
        data[left + m] = tmpArr[m];
    }
}


/*
 * Binary indexed tree
 * 
 */

void binaryIndexedTree() {
    cout<<"yes";
}

int lowbit(int x) {
    return x & (-x);
}

void update(int x, int val) {
    for (; x <= n; x += lowbit(x)) {
        C[x] += val;
    }
}

int getsum(int x) {
    int sum = 0;
    cout<<"sum of "<<x;
    for (; x > 0; x -= lowbit(x)) {
        sum += C[x];
    }
    cout<<" is "<<sum<<endl;
    return sum;
}

void buildSegTree(int root, int left, int right) {
    tree[root].left = left;
    tree[root].right = right;
    tree[root].data = 0;
    cout<<root<<"("<<left<<","<<right<<")"<<endl;
    if (left == right) return;
    int mid = (left + right) / 2;
    buildSegTree(root * 2, left, mid);
    buildSegTree(root * 2 + 1, mid + 1, right);
}

int querySegTree(int root, int left, int right) {
    if (tree[root].left >= left && tree[root].right <= right) {
        return tree[root].data;
    }
    int mid = (tree[root].left + tree[root].right) / 2;
    int sum = 0;
    if (left <= mid) {
        sum += querySegTree(root * 2, left, right);
    }
    if (right > mid) {
        sum += querySegTree(root * 2 + 1, left, right);
    }
    return sum;
}

void printSeqTree(int root, int left, int right) {
    cout<<root<<"("<<left<<","<<right<<","<<tree[root].data<<")"<<endl;
    if (left == right) return;
    int mid = (left + right) / 2;
    printSeqTree(root * 2, left, mid);
    printSeqTree(root * 2 + 1, mid + 1, right);
}

void updateSegTree(int root, int index) {
    if (tree[root].left == tree[root].right) {
        tree[root].data++;
        return;
    }
    int mid = (tree[root].left + tree[root].right) / 2;
    if (index <= mid) updateSegTree(root * 2, index);
    else updateSegTree(root * 2 + 1, index);
    tree[root].data = tree[root * 2].data + tree[root * 2 + 1].data;
}

int main() {
    // 求解逆序对算法解析
    // init source data
    cin>>n;
    int tmp_data[n];
    for (int i = 0; i < n; i++) {
        cin>>data[i];
        tmp_data[i] = data[i];
        C[i] = 0;
    }
    // 对数据进行离散化
    sort(tmp_data, tmp_data + n);
    int nn = unique(tmp_data, tmp_data + n) - tmp_data;
    for (int i = 0; i < n; i++) {
        B[i] = lower_bound(tmp_data, tmp_data + nn, data[i]) - tmp_data;
        D[i] = B[i] + 1;// D 用于线段树
        B[i] = n - B[i];// B用于树状数组
        cout<<D[i]<<" ";
    }
    cout<<endl;

    // 构建树状数组
    /*
    for (int i = 0; i < n; i++) {
        update(B[i], 1);
        countN += getsum(B[i] - 1);
    }*/

    // 线段树解法
    buildSegTree(1, 1, n);
    for (int i = 0; i < n; i++) {
        cout<<"prepare to search "<<D[i]<<endl;
        countN += querySegTree(1, D[i] + 1, n);
        cout<<"countN = "<<countN<<endl;
        updateSegTree(1, D[i]);
        printSeqTree(1, 1, n);
        cout<<endl;
    }

    // cal the data
    //fun1();
    //mergeSort(0, n - 1);
    cout<<countN;
    return 0;
}
