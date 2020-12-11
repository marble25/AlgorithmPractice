//
// Created by marble on 20. 12. 11..
//

// DP로 여러 가지 경우를 모두 고려해야 하는 문제
// 다시 풀어봐도 여전히 어렵다.

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

int T;
int n, w;

int arr[10005][2];
int a[10005], b[10005], c[10005];

// a는 0행과 1행 모두 i-1까지 채워져 있는 가지수
// b는 0행이 i-1까지, 1행은 i까지 채워져 있는 가지수
// c는 0행이 i까지, 1행은 i-1까지 채워져 있는 가지수

void solve(int idx) {
    for(int i=idx;i<n;i++) {
        a[i+1] = min(b[i]+1, c[i]+1);
        if(arr[i][0] + arr[i][1] <= w) {
            a[i+1] = min(a[i+1], a[i] + 1);
        }
        if (i > 0 && arr[i-1][0] + arr[i][0] <= w && arr[i-1][1] + arr[i][1] <= w)
            a[i+1] = min(a[i+1], a[i-1] + 2);
        if (i < n-1) {
            b[i+1] = a[i+1] + 1;
            if (arr[i][0] + arr[i+1][0] <= w)
                b[i+1] = min(b[i+1], c[i] + 1);
            c[i+1] = a[i+1] + 1;
            if (arr[i][1] + arr[i+1][1] <= w)
                c[i+1] = min(c[i+1], b[i] + 1);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;

    while(T--) {
        cin >> n >> w;

        for(int i=0;i<n;i++) {
            cin >> arr[i][0];
        }

        for(int i=0;i<n;i++) {
            cin >> arr[i][1];
        }

        // 0행과 1행의 시작점이 끝점과 모두 연결되지 않은 경우

        a[0] = 0;
        b[0] = c[0] = 1;
        solve(0);
        int res = a[n];

        // 0행의 시작점이 끝점과 연결되고, 1행은 아닌 경우

        if(n >= 2 && arr[0][0] + arr[n-1][0] <= w) {
            a[1] = 1;
            b[1] = 2;
            c[1] = arr[0][1] + arr[1][1] <= w ? 1 : 2;
            solve(1);
            res = min(res, c[n-1] +1);
        }

        // 1행의 시작점이 끝점과 연결되고, 0행은 아닌 경우

        if(n >= 2 && arr[0][1] + arr[n-1][1] <= w) {
            a[1] = 1;
            b[1] = arr[0][0] + arr[1][0] <= w ? 1 : 2;
            c[1] = 2;
            solve(1);
            res = min(res, b[n-1] + 1);
        }

        // 0행과 1행의 시작점이 모두 끝점과 연결된 경우

        if(n >= 2 && arr[0][0] + arr[n-1][0] <= w && arr[0][1] + arr[n-1][1] <= w) {
            a[1] = 0;
            b[1] = c[1] = 1;
            solve(1);
            res = min(res, a[n-1] + 2);
        }

        cout << res << "\n";
    }



    return 0;
}