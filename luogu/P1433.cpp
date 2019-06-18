#include <iostream>
#include <math.h>
#include<iomanip>

using namespace std;

#define point pair<double, double>
const int MAX = 15;
point data[MAX];
int check[MAX];
point path[MAX];
int n;
double minLength = 0;
double dfslength = 0.0;

double getDistance(point a, point b) {
    double tmp = sqrt((b.first - a.first)*(b.first - a.first) + (b.second - a.second)*(b.second - a.second));
    return tmp;
}

double getPathLength(int k) {
    point source(0, 0);
    point previous, next;
    double length = 0.0;
    for (int i = 0; i < k; i++) {
        if (i == 0) {
            previous.first = source.first;
            previous.second = source.second;
        } else {
            previous.first = next.first;
            previous.second = next.second;
        }
        next.first = path[i].first;
        next.second = path[i].second;
        length += getDistance(previous, next);
    }
    return length;
}

bool checkPathLength(int k) {
    if (minLength != 0 && getPathLength(k + 1) > minLength) {
        return false;
    }
    return true;
}

void dfs(int i) {
    if (i == n) {
        double len = getPathLength(n);
        if (minLength == 0 || minLength > len) {
            minLength = len;
        }
    } else {
        for (int j = 0; j < n; j++) {
            if (check[j] == 0) {
                check[j] = 1;
                path[i] = data[j];
                // 优化一下, 如果当前选项已经出现比minLength更大的话, 没有必要继续走下去了啊.
                point previous, next;
                if (i == 0) {
                    previous.first = 0;
                    previous.second = 0;
                } else {
                    previous.first = path[i-1].first;
                    previous.second = path[i-1].second;
                }
                next.first = path[i].first;
                next.second = path[i].second;
                double tmp = getDistance(previous, next);
                if (minLength == 0 || dfslength + tmp < minLength) {
                    dfslength += tmp;
                    dfs(i+1);
                    dfslength -= tmp;
                }
                check[j] = 0;
            }
        }
    }
}

int main() {
    cin>>n;
    double row, col;
    for (int i = 0; i < n; i++) {
        cin>>row>>col;
        point tmp(row, col);
        data[i] = tmp;
    }

    dfs(0);
    cout<<fixed<<setprecision(2)<<minLength<<endl;

    return 0;
}
