//
// Created by marble on 20. 12. 17..
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

int x, y;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> x >> y;
    int ans = 0;

    if(y > 0) {
        if(x > 0) ans = 1;
        else ans = 2;
    } else {
        if(x > 0) ans = 4;
        else ans = 3;
    }

    cout << ans;
    return 0;
}