//
// Created by marble on 21. 1. 1..
//

// 더 빨리 푸는 방법이 있는데 더 간단한 방법으로 풀었다.

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

int t;
int n, m;

int arr[1000005] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;

    arr[0] = 1;
    for(int i=1;i<=1000000;i++) { // 미리 메모이제이션
        int x = i;
        while(x > 0) {
            if(x % 10 == 0) arr[i]++;
            x /= 10;
        }

        arr[i] += arr[i-1];
    }

    for(int i=0;i<t;i++) {
        cin >> n >> m;

        int x = (n == 0 ? 0 : arr[n-1]);
        cout << arr[m] - x << "\n";
    }
    return 0;
}