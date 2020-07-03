//
// Created by marble on 20. 7. 4..
//

// 방법을 생각하기 꽤 까다로웠다.
// 간단하지만, 어려운 문제였다.

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

int d, n;
int m[300005] = {0};
int p[300005] = {0};


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> d >> n;
    m[0] = 1000000001;
    for(int i=1;i<=d;i++) {
        int x;
        cin >> x;
        m[i] = min(x, m[i-1]);
    }

    for(int i=1;i<=n;i++) {
        cin >> p[i];
    }

    int idx = 1;
    for(int i=d;i>0;i--) { // i : 체크하는 오븐의 depth
        if(p[idx] > m[i]) continue; // 오븐의 지름보다 피자의 지름이 더 크면 위칸으로 올라감
        idx += 1; // 다음 피자를 체크(인덱스 증가)
        if(idx > n) { // 피자를 다 넣었으면 종료
            cout << i << "\n";
            return 0;
        }
    }

    cout << 0;

    return 0;
}