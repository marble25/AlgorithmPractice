//
// Created by marble on 20. 5. 25..
//

// 2차원 배열 정렬이 이상하게 안되어서 안하고 했더니 틀린 문제
// priority queue를 사용해서, greedy하게, 최대 연료만 먹어가면서 풀 수 있는 문제
// 귀찮아도 꼼꼼하게...

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
pair<int, int> info[10005];
int l, p;
int ans = 0;
priority_queue<int> pq;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> info[i].first >> info[i].second;
    }

    cin >> l >> p;

    sort(info, info+n);

    for(int i=0;i<n;i++) {
        if(p < info[i].first) { // 연료보다 거리를 많이 왔다면(그 전에 채웠어여 한다)
            while(!pq.empty()) {
                p += pq.top(); // 최대 연료 가져와서 주입
                pq.pop();
                ans++;

                if(p >= info[i].first) break;
            }

            if(p < info[i].first) { // 이제까지 나온 모든 주유소를 다 들려도 안된다면 -1 출력
                cout << -1;
                return 0;
            }

        }
        pq.push(info[i].second); // pq에 새 값 넣기
    }

    if(p < l) { // 끝까지 도달하지 못한다면
        while(!pq.empty()) {
            p += pq.top(); // 최대 연료 가져와서 주입
            pq.pop();
            ans++;

            if(p >= l) break;
        }

        if(p < l) { // 이제까지 나온 모든 주유소를 다 들려도 안된다면 -1 출력
            cout << -1;
            return 0;
        }
    }

    cout << ans;

    return 0;
}