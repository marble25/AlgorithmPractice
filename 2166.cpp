//
// Created by marble on 20. 8. 22..
//

// 간단한 문제였는데 이렇게 long long으로 고생하는 문제는 싫다..
// 처음부터 자료형 자체를 long long으로 받을걸..

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
pair<long long, long long> v[10005];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> v[i].first >> v[i].second;
    }
    v[n].first = v[0].first;
    v[n].second = v[0].second;

    long long a=0, b=0;
    for(int i=0;i<n;i++) { // https://mathworld.wolfram.com/PolygonArea.html . 다른 말로는 사선 공식이라고 한다.
        a += v[i].first * v[i+1].second;
        b += v[i].second * v[i+1].first;
    }
    long long ans = std::abs(a-b);
    if(ans % 2 == 0) cout << ans / 2 << ".0"; // 소숫점 정확도 때문에 짝수이면 0 붙여주기, 홀수이면 .5 붙여주기
    else cout << ans / 2 << ".5";

    return 0;
}