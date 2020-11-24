//
// Created by marble on 20. 11. 24..
//

// 간단한 그리디 문제

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <string.h>
using namespace std;

int l, p, v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=1;;i++) {
        cin >> l >> p >> v;
        if(l == 0 && p == 0 && v == 0) {
            break;
        }

        int ans = (v/p)*l + min(v%p, l); // p일 중 l일 쓰고 p-l일 안쓰고를 반복하여 (v/p)*l일 쓰고, 나머지를 최대 l일 쓸 수 있다.
        cout << "Case " << i << ": " << ans << "\n";
    }

    return 0;
}