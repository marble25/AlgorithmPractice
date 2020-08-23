//
// Created by marble on 20. 8. 23..
//

// 까다로운 문제이다.
// nlogn까지는 어떻게 생각을 해 보겠는데 n 풀이는 쉽게 생각이 나지 않는다.

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
long long arr[100005];
long long sum[100005] = {0};
long long ans = 0;
stack<pair<long long, int>> stk;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        sum[i] = arr[i] + sum[i - 1]; // 부분합을 미리 구해놓는다
    }
    arr[n+1] = 0;

    for(int i=1;i<=n+1;i++) {
        while(!stk.empty() && stk.top().first > arr[i]) { // 이전 값이 현재 값보다 작으면
            int h = stk.top().first;
            stk.pop();
            int prv = stk.empty() ? 0 : stk.top().second; // 스택이 비어있으면 맨 앞, 아니면 이전 값의 인덱스
            ans = max(ans, (sum[i-1] - sum[prv]) * h); // 해당 값으로 만들 수 있는 최대의 크기와 ans를 비교
        }
        stk.push({arr[i], i});
    }
    cout << ans;

    return 0;
}