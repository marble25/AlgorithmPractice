//
// Created by marble on 20. 12. 16..
//

// 구현 문제이면서 생각을 하게 만드는 문제
// 각 지점에서 채워질 물의 양은 왼쪽에서의 최대와 오른쪽에서의 최대 중 작은 값을 높이로 갖는다.

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

int h, w;
int arr[505];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> h >> w;
    for(int i=0;i<w;i++) {
        cin >> arr[i];
    }

    int ans = 0;
    for(int i=1;i<w-1;i++) {
        int l_max = arr[i], r_max = arr[i];
        for(int j=i-1;j>=0;j--) { // 왼쪽으로 가면서 가장 높은 지점을 가져옴
            l_max = max(l_max, arr[j]);
        }

        for(int j=i+1;j<w;j++) { // 오른쪽으로 가면서 가장 높은 지점을 가져옴
            r_max = max(r_max, arr[j]);
        }

        ans += min(l_max, r_max) - arr[i]; // 오른쪽과 왼쪽 중 낮은 곳을 높이로 가지므로, 물의 양은 현재 높이에서 빼주면 된다.
    }
    cout << ans;

    return 0;
}