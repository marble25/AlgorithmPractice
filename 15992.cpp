//
// Created by marble on 20. 6. 24..
//

// DP로 간단하게 풀 수 있었던 문제

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

int T;
int n, m;

long long cache[1005][1005] = {0}; // n을 m개의 수로 표현할 수 있는 가지수

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;

    // 기저값을 설정
    cache[1][1] = 1;
    cache[2][1] = 1;
    cache[2][2] = 1;
    cache[3][1] = 1;
    cache[3][2] = 2;
    cache[3][3] = 1;

    for(int i=4;i<=1000;i++) {
        for(int j=2;j<=1000;j++) {
            cache[i][j] = cache[i-1][j-1] + cache[i-2][j-1] + cache[i-3][j-1]; // i-1에 1 더하기, i-2에 2 더하기, i-3에 3 더하기 경우를 모두 더함
            cache[i][j] %= 1000000009;
        }
    }
    while(T--) {
        cin >> n >> m;
        cout << cache[n][m] << "\n";
    }

    return 0;
}