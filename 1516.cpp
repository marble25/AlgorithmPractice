//
// Created by marble on 20. 8. 8..
//

// 간단하게 위상 정렬을 이용해서 맞추었던 문제
// 처음에 하나의 조건을 안 넣어줘서 틀린게 아쉽다

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
int t[505] = {0};
vector<int> linked[505];
int order[505] = {0};
int visited[505] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> t[i];
        while(true) {
            int x;
            cin >> x;
            if(x == -1) break;
            linked[x].push_back(i);
            order[i]++;
        }
    }

    queue<int> q;

    for(int i=1;i<=n;i++) {
        if(order[i] == 0) q.push(i); // 선행되어야 하는 건물이 없는 경우 queue에 넣어줌
    }

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(int i=0;i<linked[x].size();i++) {
            int it=linked[x][i];
            order[it]--;
            visited[it] = max(visited[it], visited[x] + t[x]); // 선행 건물 중 가장 큰 시간을 가진 것을 넣어줌
            if(order[it] == 0) { // 선행 건물이 없으면 push
                q.push(it);
            }
        }
    }

    for(int i=1;i<=n;i++) { // 선행 시간과 건물 건설 시간을 더해서 출력
        cout << visited[i] + t[i] << '\n';
    }

    return 0;
}