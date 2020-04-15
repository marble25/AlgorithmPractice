//
// Created by marble on 20. 4. 15..
//

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

int c;
int n, m;
int visit_cnt = 1;
vector<int> v;
char arr[85][85];
int number[85][85] = {0};
int dx[] = {-1, 0, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 1, 1, 1};
vector<vector<int>> adj; // 한 쪽이라도 컨닝 가능한 간선을 나타냄
vector<int> visit;
vector<int> match;

int dfs(int a) {
    if(visit[a] == visit_cnt) return 0; // 이미 방문했다면 리턴
    visit[a] = visit_cnt;

    for(int i=0;i<adj[a].size();i++) {
        int b = adj[a][i];

        if(match[b] == -1 || dfs(match[b])) { // 한 번도 방문하지 않았거나 방문했더라도 다른 방법이 존재하면
            match[b] = a; // b에서 a로 감(reverse)
            return 1;
        }
    }

    return 0;
}

int bipartite_match() {
    int size = 0;
    visit = vector<int>(n*m+1);
    match = vector<int>(n*m+1, -1);

    for(auto &it:v) {
        visit_cnt++;
        size += dfs(it);
    }
    return size;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> c;
    while(c--) {
        cin >> n >> m;

        adj = vector<vector<int>>(n*m+1);
        v.clear();

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin >> arr[i][j];
            }
        }

        int crash = 0;
        int cnt = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(arr[i][j] == 'x')
                    crash++;

                if(j%2 == 0)
                    v.push_back(cnt);

                number[i][j] = cnt++;
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(arr[i][j] == 'x')
                    continue;

                for(int k=0;k<6;k++) {
                    int x = i+dx[k];
                    int y = j+dy[k];

                    if(x < 0 || y < 0 || x >= n || y >= m || arr[x][y] == 'x')
                        continue;

                    adj[number[i][j]].push_back(number[x][y]); // a에서 b를 컨닝할 수 있거나 b에서 a를 컨닝할 수 있다면 a와 b 모두 추가
                }
            }
        }

        int ans = bipartite_match();
        cout << n*m - ans - crash << '\n'; // 매칭된 갯수와 x 갯수 뺀 것을 출력
    }
    return 0;
}