//
// Created by marble on 20. 12. 18..
//

// 문제를 어렵게 생각하지 말고 쉽게 쉽게 생각하자

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

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    int cnt = 0;
    int cur = 1;
    while(n > 0) {
        if(n < cur) { // 날아갈 새들이 더 커지면 새들을 1로 초기화
            cur = 1;
        }

        n -= cur;
        cnt++;
        cur++;
    }

    cout << cnt;
    return 0;
}