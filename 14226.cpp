//
// Created by marble on 20. 4. 7..
//

// 예전에 풀었던 문제와 비슷한 것 같은데, 그때는 많이 틀렸지만 지금은 한번에 맞춰서 기분이 좋다.

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

int s;
int visited[1005][1005] = {0}; // visited[num][buff] : 이모티콘 갯수가 num이고, buff에 담긴 갯수가 buff일때 최소 횟수
queue<pair<int, int>> q;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> s;
    visited[1][0] = 1;
    q.push(make_pair(1, 0));
    while(!q.empty()) {
        int num = q.front().first, buff = q.front().second;
        q.pop();

        if(num == s) { // 처음에는 queue가 비어있을 때까지 계속 돌렸는데, num이 s인 경우만 하더라도 최솟값이 나온다는 것을 깨닫고 이렇게 중간 break 조건을 넣어줌
            cout << visited[num][buff] - 1;
            return 0;
        }

        if(num-1 > 0 && visited[num-1][buff] == 0) { // 하나 빼는 경우
            q.push(make_pair(num-1, buff));
            visited[num-1][buff] = visited[num][buff] + 1;
        }

        if(num+buff <= s && visited[num+buff][buff] == 0) { // buff만큼 더해주는 경우
            q.push(make_pair(num+buff, buff));
            visited[num+buff][buff] = visited[num][buff] + 1;
        }

        if(num != buff && visited[num][num] == 0) { // buff에 현재 있는 것을 넣어주는 경우
            q.push(make_pair(num, num));
            visited[num][num] = visited[num][buff] + 1;
        }
    }

    return 0;
}