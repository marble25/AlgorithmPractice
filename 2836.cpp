//
// Created by marble on 20. 8. 15..
//

// 쉽게 보고 얕보다가 생각보다 안풀린 문제
// Line Sweeping의 개념을 다시 다잡았다
// 정방향으로 가는 사람은 고려하지 않고 역방향만 라인 스위핑을 이용해서 합해준다

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

long long n, m;
vector<pair<long long, long long>> people;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        long long x, y;
        cin >> x >> y;
        if(x > y) {
            people.push_back({y, x});
        }
    }
    if(people.empty()) {
        cout << m;
        return 0;
    }

    sort(people.begin(), people.end());

    long long total = 0;
    long long start = people[0].first;
    long long end = people[0].second;

    int sz = people.size();
    for(int i=1;i<sz;i++) {
        if(people[i].first > end) { // 겹치는 부분이 없는 경우
            total += (end - start); // total에 더해줌
            start = people[i].first; // 새로 시작
            end = people[i].second;
        } else if(people[i].second > end) { // 겹치면서 구간이 더 길어지는 경우(end가 범위 바깥)
            end = people[i].second;
        }
    }

    total += (end - start); // 더해주지 않은 마지막 값을 더해줌

    cout << m + 2 * total; // 역방향 구간만큼 왔다 갔다 한 것을 m에다 더해줌

    return 0;
}