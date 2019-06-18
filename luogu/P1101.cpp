#include <iostream>

using namespace std;

void checkLeftToRight(int row, int column, string arr[], string tmp[], int length) {
    if (length - column >= 7) {
        char tmpChar[7];
        for (int i = 0; i < 7; i++) {
            tmpChar[i] = arr[row][column + i];
        }
        string tmpStr = string(tmpChar);
        string des = "yizhong";
        if (des == tmpStr) {
            for (int i = 0; i < 7; i++) {
                tmp[row][column + i] = des[i];
            }
        }
    }
    // cout<<"checkLeftToRight"<<endl;
}

void checkLeftToRightBottom(int row, int column, string arr[], string tmp[], int length) {
    if (length - row >= 7 && length - column >= 7) {
        char tmpChar[7];
        for (int i = 0; i < 7; i++) {
            tmpChar[i] = arr[row + i][column + i];
        }
        string tmpStr = string(tmpChar);
        string des = "yizhong";
        if (des == tmpStr) {
            for (int i = 0; i < 7; i++) {
                tmp[row + i][column + i] = des[i];
            }
        }
    }
    // cout<<"checkLeftToRightBottom"<<endl;
}


void checkTopToBottom(int row, int column, string arr[], string tmp[], int length) {
    if (length - row >= 7) {
        char tmpChar[7];
        for (int i = 0; i < 7; i++) {
            tmpChar[i] = arr[row + i][column];
        }
        string tmpStr = string(tmpChar);
        string des = "yizhong";
        if (des == tmpStr) {
            for (int i = 0; i < 7; i++) {
                tmp[row + i][column] = des[i];
            }
        }
    }
    // cout<<"checkTopToBottom"<<endl;
}

void checkRightToLeftBottom(int row, int column, string arr[], string tmp[], int length) {
    if (length - row >= 7 && column >= 6) {
        char tmpChar[7];
        for (int i = 0; i < 7; i++) {
            tmpChar[i] = arr[row + i][column - i];
        }
        string tmpStr = string(tmpChar);
        string des = "yizhong";
        if (des == tmpStr) {
            for (int i = 0; i < 7; i++) {
                tmp[row + i][column - i] = des[i];
            }
        }
    }
    // cout<<"checkRightToLeftBottom"<<endl;
}

void checkRightToLeft(int row, int column, string arr[], string tmp[], int length) {
    if (column >= 6) {
        char tmpChar[7];
        for (int i = 0; i < 7; i++) {
            tmpChar[i] = arr[row][column - i];
        }
        string tmpStr = string(tmpChar);
        string des = "yizhong";
        if (des == tmpStr) {
            for (int i = 0; i < 7; i++) {
                tmp[row][column - i] = des[i];
            }
        }
    }
    // cout<<"checkRightToLeft"<<endl;
}

void checkRightToLeftTop(int row, int column, string arr[], string tmp[], int length) {
    if (row >= 6 && column >= 6){
        char tmpChar[7];
        for (int i = 0; i < 7; i++) {
            tmpChar[i] = arr[row - i][column - i];
        }
        string tmpStr = string(tmpChar);
        string des = "yizhong";
        if (des == tmpStr) {
            for (int i = 0; i < 7; i++) {
                tmp[row - i][column - i] = des[i];
            }
        }
    }
    // cout<<"checkRightToLeftTop"<<endl;
}

void checkBottomTotop(int row, int column, string arr[], string tmp[], int length) {
    if (row >= 6){
        char tmpchar[7];
        for (int i = 0; i < 7; i++) {
            tmpchar[i] = arr[row - i][column];
        }
        string tmpstr = string(tmpchar);
        string des = "yizhong";
        if (des == tmpstr) {
            for (int i = 0; i < 7; i++) {
                tmp[row - i][column] = des[i];
            }
        }
    }
    // cout<<"checkBottomTotop"<<endl;
}

void checkLeftToRightTop(int row, int column, string arr[], string tmp[], int length) {
    if (row >= 6 && length - column >= 7){
        char tmpchar[7];
        for (int i = 0; i < 7; i++) {
            tmpchar[i] = arr[row - i][column + i];
        }
        string tmpstr = string(tmpchar);
        string des = "yizhong";
        if (des == tmpstr) {
            for (int i = 0; i < 7; i++) {
                tmp[row - i][column + i] = des[i];
            }
        }
    }
    // cout<<"checkLeftToRightTop"<<endl;
}

int main() {
    // init source data.
    int n;
    cin>>n;
    string arr[n];
    string tmp[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
        char tmpChar[n];
        for (int j = 0; j < n; j++) {
            tmpChar[j] = '*';
        }
        string tmpStr(tmpChar);
        tmp[i] = tmpStr;
    }

    // calculate the data
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            checkTopToBottom(i, j, arr, tmp, n);
            checkLeftToRight(i, j, arr, tmp, n);
            checkLeftToRightBottom(i, j, arr, tmp, n);
            checkRightToLeftBottom(i, j, arr, tmp, n);
            checkRightToLeft(i, j, arr, tmp, n);
            checkRightToLeftTop(i, j, arr, tmp, n);
            checkBottomTotop(i, j, arr, tmp, n);
            checkLeftToRightTop(i, j, arr, tmp, n);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<tmp[i][j];
        }
        cout<<endl;
    }
    return 0;
}
