//
// Created by marble on 20. 5. 26..
//

// 라인 스위핑이라는 신기한 알고리즘이라고 한다.
// 정렬 후 큰 값으로 바꿔주는 알고리즘이다.

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
vector<pair<long long, long long>> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    long long s, e;
    for(int i=0;i<n;i++) {

        cin >> s >> e;
        v.push_back({s, e});
    }

    sort(v.begin(), v.end());

    long long ans = 0;
    s = v[0].first, e = v[0].second;
    for(int i=1;i<n;i++) {
        if(e < v[i].first) { // 이을 수 없을 때 새로운 선으로 옮겨감
            ans += e-s;
            s = v[i].first;
            e = v[i].second;
        } else { // 이을 수 있으면 새로 들어온 값과 기존 값 중 max로 옮겨감
            e = max(v[i].second, e);
        }
    }

    cout << ans + (e - s); // 마지막 값까지 더해서 출력

    return 0;
}