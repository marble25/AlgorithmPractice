//
// Created by marble on 20. 3. 28..
//

// 초기에 제출한 방법을 바꿔서 재제출해서 시간을 크게 감소한 문제
// 초기 : 현재 i, j에서 point를 써서 갈 수 있는 모든 스탯을 queue에 넣고 탐색
// 개선 : 현재 i, j에서 point를 써서 갈 수 있는 퀘스트(이미 달성한 퀘스트 제외)에 해당하는 스탯을 queue에 넣음

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int arr[105][3];
int dp[1005][1005] = {0};
int visited[1005][1005] = {0};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=0;i<n;i++) {
        for(int j=0;j<3;j++) {
            cin >> arr[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push(make_pair(1, 1)); // 시작 능력치(1, 1) 집어넣음

    int max_val = INT16_MIN;

    while(!q.empty()) {
        pair<int, int> p = q.front(); // p는 캐릭터의 능력치
        q.pop();

        int point = 2; // 초기 능력치
        for(int i=0;i<n;i++) {
            if(arr[i][0] <= p.first || arr[i][1] <= p.second) { // 퀘스트의 능력치보다 캐릭터의 능력치가 같거나 높을 때 퀘스트 클리어 가능
                dp[p.first][p.second] ++; // 클리어 가능한 퀘스트 갯수 + 1
                point += arr[i][2]; // 달성할 수 있는 모든 퀘스트의 능력치 합을 더해줌
            }
        }
        max_val = max(max_val, dp[p.first][p.second]);
        point -= (p.first + p.second); // 퀘스트로 얻은 포인트에서 현재 능력치를 빼면 남은 포인트가 생김

        for(int i=0;i<n;i++) {
            if(arr[i][0] > p.first && point >= arr[i][0]-p.first && visited[arr[i][0]][p.second] == 0) { // 다음 퀘스트가 현재 스탯보다 높고 현재 포인트로 갈 수 있으며 한번도 안가봤다면
                visited[arr[i][0]][p.second] = 1;
                q.push(make_pair(arr[i][0], p.second));
            }

            if(arr[i][1] > p.second && point >= arr[i][1] - p.second  && visited[p.first][arr[i][1]] == 0) { // 다음 퀘스트가 현재 스탯보다 높고 현재 포인트로 갈 수 있으며 한번도 안가봤다면
                visited[p.first][arr[i][1]] = 1;
                q.push(make_pair(p.first, arr[i][1]));
            }
        }
    }

    cout << max_val << '\n';

    return 0;
}