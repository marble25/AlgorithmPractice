//
// Created by marble on 20. 6. 17..
//

// 간단하게 피보나치 수열을 구해서 규칙만 찾아주면 되는 문제
// 기저 사례들에 대한 예외 처리가 필요

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
long long fib[85] = {0};
long long ans = 0;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    fib[1] = 1;
    fib[2] = 1;
    for(int i=3;i<=n;i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    if(n == 1) ans = 4;
    else if(n == 2) ans = 6;
    else ans = (fib[n] + fib[n-1]) * 2 + (fib[n-1] + fib[n-2]) * 2;

    cout << ans;

    return 0;
}