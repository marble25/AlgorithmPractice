//
// Created by marble on 20. 6. 12..
//

// bfs로 풀다가 틀려서 다른 방법을 시도해본 문제
// 다른 사람은 dfs로 풀었다는 것이 충격이다.

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

int n, a, b;
int pos[500005] = {0}; // 이전 stage에서 오리들이 갈 수 있는 위치들
int temp[500005] = {0}; // 현재 stage에서 오리들이 갈 수 있는 위치들

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> a >> b;
    pos[a] = 1; // a에는 1번 오리
    pos[b] = 2; // b에는 2번 오리

    for(int i=1;;i++) {
        bool is_reachable = false;

        int diff = pow(2, i-1);

        for(int j=1;j<=n;j++) {
            if(pos[j] != 0) { // 오리가 해당 위치에 존재하면
                is_reachable = true; // 오리가 만날 수 있음

                int duck = pos[j];
                if(j-diff > 0) { // 왼쪽으로 가도 맵 안에 있다면
                    if(temp[j-diff] == 3-duck) { // 현재 위치에서 다른 오리도 그 위치로 갈 수 있다면 답 출력 후 끝
                        cout << i;
                        return 0;
                    }
                    temp[j-diff] = duck; // 현재 stage에서 갈 수 있는 위치
                }

                if(j+diff <= n) { // 오른쪽으로 가도 맵 안에 있다면
                    if(temp[j+diff] == 3-duck) { // 현재 위치에서 다른 오리도 그 위치로 갈 수 있다면 답 출력 후 끝
                        cout << i;
                        return 0;
                    }
                    temp[j+diff] = duck; // 현재 stage에서 갈 수 있는 위치
                }
            }
        }

        if(!is_reachable) { // 맵 안에 오리가 없다면
            cout << -1;
            break;
        }

        memcpy(pos, temp, sizeof(pos)); // pos에 temp 복사
        memset(temp, 0, sizeof(temp)); // temp 초기화
    }

    return 0;
}