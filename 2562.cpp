//
// Created by marble on 20. 10. 30..
//

// 복귀 기념으로 연습 문제 풀이

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

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a[10];
    for(int i=0;i<9;i++) {
        cin >> a[i];
    }

    int mx = a[0];
    int mi = 0;

    for(int i=1;i<9;i++) {
        if(mx < a[i]) {
            mx = a[i];
            mi = i;
        }
    }

    cout << mx << "\n";
    cout << mi+1;

    return 0;
}