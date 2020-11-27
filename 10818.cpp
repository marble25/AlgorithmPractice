//
// Created by marble on 20. 11. 27..
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

int n;
int mx = -987654321;
int mn = 987654321;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        mx = max(x, mx);
        mn = min(x, mn);
    }

    cout << mn << " " << mx;
    return 0;
}