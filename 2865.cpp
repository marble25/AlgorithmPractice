//
// Created by marble on 20. 6. 30..
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <string.h>
using namespace std;

int n, m, k;
vector<pair<float, int>> v;
int check[105] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int x;
            float y;
            cin >> x >> y;
            v.push_back({y, x});
        }
    }
    sort(v.begin(), v.end(), greater<>());

    float sum = 0;
    for(auto &it:v) {
        if(k == 0) break;
        if(check[it.second] == 0) { // 이미 뽑은 아이가 아니면 뽑기
            k--;
            check[it.second] = 1;
            sum += it.first;
        }
    }

    cout << fixed;
    cout.precision(1);
    cout << sum;
    return 0;
}