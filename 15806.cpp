//
// Created by marble on 20. 4. 23..
//

// 이렇게 간단한 문제를 왜 이렇게 많이 틀렸을까...
// BFS를 체크해주면서 하면 간단한 문제였는데..

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

int n, m, k, t;
int map[305][305][2] = {0}; // 짝수 번째와 홀수 번째의 곰팡이를 나누어 준다.(짝수 번째면 모든 짝수번째마다 곰팡이가 피게 되므로 중복 체크할 필요 없다.)
queue<pair<int, int>> q;
vector<pair<int, int>> check;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k >> t;
    for(int i=0;i<m;i++) {
        int x, y;
        cin >> x >> y;
        q.push({x, y});
        map[x][y][0] = 1;
    }

    for(int i=0;i<k;i++) {
        int x, y;
        cin >> x >> y;
        check.push_back({x, y});
    }

    for(int i=1;i<=t;i++) {
        int q_size = q.size();
        while(q_size--) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int j=0;j<8;j++) {
                int m_x = x + dx[j];
                int m_y = y + dy[j];
                if(m_x < 0 || m_y < 0 || m_x >= n || m_y >= n) continue;
                if(map[m_x][m_y][i%2] == 0) { // 방문 안했으면 방문
                    q.push({m_x, m_y});
                    map[m_x][m_y][i%2] = 1;
                }

            }
        }
    }

    for(int i=0;i<k;i++) {
        int x = check[i].first, y = check[i].second;
        if(map[x][y][t%2] == 1) { // 검사일에 곰팡이가 피어있으면 YES 출력
            cout << "YES" << "\n";
            return 0;
        }
    }
    cout << "NO" << "\n";
    return 0;
}