//
// Created by marble on 20. 9. 4..
//

// 처음에는 당황했지만 이내 쉽게 풀 수 있었던 문제
// 잘 생각하니 길이 보였다

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

int m, n;
int arr[705][705] = {0};
int seed[1505] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;
    for(int i=0;i<n;i++) {
        int x, y, z;
        cin >> x >> y >> z;
        y += x;
        seed[x]++; // 1 자람이 시작되는 지점
        seed[y]++; // 2 자람이 시작되는 지점
    }

    int cnt = 0, pos = 0;
    for(int i=m-1;i>=0;i--) {
        cnt += seed[pos++]; // 자람의 수가 바뀔 때 cnt에 더해줌
        arr[i][0] = cnt;
    }

    for(int j=1;j<m;j++) {
        cnt += seed[pos++]; // 자림이 수가 바뀔 때마다 cnt에 더해줌
        arr[0][j] = cnt;
    }

    for(int i=1;i<m;i++) {
        for(int j=1;j<m;j++) {
            arr[i][j] = arr[0][j]; // 왼쪽, 왼쪽 위, 위 중 가장 큰 값은 무조건 위쪽
        }
    }

    for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
            if(j == m-1) cout << arr[i][j]+1 << "\n";
            else cout << arr[i][j]+1 << " ";

        }
    }

    return 0;
}