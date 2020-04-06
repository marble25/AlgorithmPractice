//
// Created by marble on 20. 4. 6..
//

// BFS를 이용한 간단한 문제

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

int n;
int dis[205][205] = {0};
int input_arr[205][3];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<3;j++) {
            cin >> input_arr[i][j];
        }
    }

    // 거리를 저장해줌
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            dis[i][j] = (input_arr[i][0] - input_arr[j][0]) * (input_arr[i][0] - input_arr[j][0]) +
                        (input_arr[i][1] - input_arr[j][1]) * (input_arr[i][1] - input_arr[j][1]);
            dis[j][i] = dis[i][j];
        }
    }

    int max_cnt = 0;
    for(int i=0;i<n;i++) { // 모든 정점에서 BFS를 시작해봄
        int visited[205] = {0};
        queue<int> q;

        q.push(i);
        visited[i] = 1;
        int cnt = 1;
        while(!q.empty()) {
            int x = q.front();
            q.pop();

            for(int j=0;j<n;j++) {
                if(visited[j] == 1) continue; // 방문했으면 continue
                if(input_arr[x][2] * input_arr[x][2] < dis[x][j]) continue; // power보다 거리가 더 크면 continue

                q.push(j);
                visited[j] = 1;
                cnt++;
            }
        }
        max_cnt = max(cnt, max_cnt);
    }
    cout << max_cnt;
    return 0;
}