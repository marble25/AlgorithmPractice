//
// Created by marble on 20. 7. 17..
//

// 오랜만에 풀어서 그런지 감 잃은듯 하다.
// 알고리즘도 열심히 공부해야 하는데...

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

int n;
int t[10005] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int ans = 0;

    cin >> n;
    for(int i=1;i<=n;i++) {
        int l, n_job;
        cin >> l >> n_job;
        for(int j=0;j<n_job;j++) {
            int x;
            cin >> x;
            t[i] = max(t[i], t[x]);
        }
        t[i] += l;
        ans = max(t[i], ans);
    }
    cout << ans;
    return 0;
}