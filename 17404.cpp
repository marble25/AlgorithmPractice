//
// Created by marble on 20. 8. 6..
//

// 첫 번째 줄을 고정시키고 하는 방법으로 풀었다.
// 처리 하나를 안해줘서 한번 틀리고 말앗다.

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

int n;
int arr[1005][3] = {0};

int cache[1005][3] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<3;j++) {
            cin >> arr[i][j];
        }
    }
    for(int j=0;j<3;j++) { // default 값을 설정
        cache[1][j] = arr[1][j];
    }

    int ans = 999999999;

    for(int k=0;k<3;k++) { // 첫 번째 줄에서 k를 선택했다고 가정
        for(int j=0;j<3;j++) {
            if(j == k) {
                cache[2][j] = 999999999; // 첫 줄과 두번째 줄이 같으면 안되므로 매우 큰 값으로 설정
            } else {
                cache[2][j] = arr[2][j] + cache[1][k]; // 두 번째 줄은 첫 번째에서 선택한 값 + 두 번째 줄의 값
            }
        }
        for(int i=3;i<=n;i++) { // 세 번째 줄부터
            cache[i][0] = arr[i][0] + min(cache[i-1][1], cache[i-1][2]); // 위와 다른 색 중에서 최소를 선택
            cache[i][1] = arr[i][1] + min(cache[i-1][0], cache[i-1][2]);
            cache[i][2] = arr[i][2] + min(cache[i-1][1], cache[i-1][0]);
        }

        if(k == 0) { // 첫 줄과 마지막 줄의 색이 달라야 하기 때문에 if로 체크
            ans = min(ans, min(cache[n][1], cache[n][2]));
        } else if(k == 1) {
            ans = min(ans, min(cache[n][0], cache[n][2]));
        } else if(k == 2) {
            ans = min(ans, min(cache[n][0], cache[n][1]));
        }

    }

    cout << ans;

    return 0;
}