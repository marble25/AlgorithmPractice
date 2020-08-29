//
// Created by marble on 20. 8. 29..
//

// 시간이 너무 많이 걸리게 풀어버린 문제...
// 간단할 줄 알았는데 테스트 데이터가 상당히 큰 모양이다.

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

int T;
int n;
int arr[100005] = {0};

int team;
int visited[100005] = {0};

int dfs(int x) {
    int next = arr[x];
    if(visited[next] == 0) { // 방문 안했으면 방문
        visited[next] = visited[x];
        int ret = dfs(next);
        if(ret == next) { // 다음 노드가 cycle의 시작이라면 앞으로는 -1만 리턴
            return -1;
        } else if(ret == -1) { // cycle이 아니면 visited를 -1로 설정해서 팀이 안이뤄짐을 알림
            visited[next] = -1;
            return ret;
        } else { // cycle이면 cycle의 시작 노드를 계속 리턴
            return ret;
        }
    } else if(visited[next] == team) { // 방문을 했고, cycle이면 cycle의 시작 노드를 리턴
        return next;
    } else { // 방문을 했지만 cycle이 아니거나 예전에 체크를 했다면
        return -1;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;
    while(T--) {
        cin >> n;
        for(int i=1;i<=n;i++) {
            cin >> arr[i];
            visited[i] = 0;
        }

        for(int i=1;i<=n;i++) {
            if(visited[i] == 0) {
                team = i;
                visited[i] = i;
                int ret = dfs(i);
                if(ret == -1) { // 시작점이 cycle이 아니면 visited를 초기화
                    visited[i] = -1;
                }
            }
        }

        int cnt = 0;
        for(int i=1;i<=n;i++) { // 그룹이 안이뤄진 것만 체크
            if(visited[i] == 0 || visited[i] == -1) cnt++;
        }

        cout << cnt << "\n";
    }

    return 0;
}