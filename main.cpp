// 단순 정렬하는 문제였다.
// 어려운 문제도 꾸준히 풀어야 겠다.

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
vector<int> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int ans = 0;

    cin >> n;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end(), greater<>()); // 가장 오래 걸리는 것을 먼저 심음
    for(int i=0;i<n;i++) {
        ans = max(ans, v[i]+i+1); // 심은 날짜를 고려했을 때 가장 늦게 끝나는 것 고르기
    }

    cout << ans + 1;

    return 0;
}