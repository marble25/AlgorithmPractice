//
// Created by marble on 20. 12. 19..
//

// long long으로 정답을 저장을 안했다.
// 변수 모두 한번씩 더 봐야겠다.

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
vector<long long> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        long long x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int cnt = 1;
    int cur = 1;
    long long ans = v[0]; // ans도 long long이어야 함

    for(int i=1;i<n;i++) {
        if(v[i] == v[i-1]) { // 이전 것과 같으면 갯수 증가
            cur++;
        } else { // 이전 것과 다르므로 현재 상태로 업데이트
            if(cnt < cur) { // max 갯수 업데이트
                cnt = cur;
                ans = v[i-1]; // ans 설정
            }
            cur = 1;
        }
    }

    if(cnt < cur) { // 맨 마지막 값이 업데이트 안되는 경우 고려
        cnt = cur;
        ans = v[n-1];
    }

    cout << ans;

    return 0;
}