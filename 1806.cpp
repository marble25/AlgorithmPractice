//
// Created by marble on 20. 8. 11..
//

// 투 포인터 이용해서 간단하게 풀어본 문제이다.

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

int n, s;
int arr[100005];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> s;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    int st = 0, en = -1; // 시작 포인터와 끝 포인터
    int sum = 0;
    int ans = 9999999;
    while(en < n) {
        if(sum < s) { // 현재 값이 s보다 작으면 뒷 숫자를 추가
            en++;
            if(en == n) break;
            sum += arr[en];
        } else { // 현재 값이 s보다 크면 앞 숫자를 뺌
            ans = min(ans, en-st+1);
            sum -= arr[st++];
        }
    }
    if(ans == 9999999) cout << 0;
    else cout << ans;
    return 0;
}