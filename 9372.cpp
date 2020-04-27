//
// Created by marble on 20. 4. 27..
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

int T;
int n, m;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;
    while(T--) {
        cin >> n >> m;

        vector<int> linked[1005];
        queue<int> q;
        int visited[1005] = {0};

        for(int i=0;i<m;i++) {
            int x, y;
            cin >> x >> y;
            linked[x].push_back(y);
            linked[y].push_back(x);
        }

        int ans = 0;

        q.push(1);
        visited[1] = 1;
        while(!q.empty()) {
            int x = q.front();
            q.pop();

            for(int i=0;i<linked[x].size();i++) {
                int next = linked[x][i];
                if(visited[next] == 0) {
                    visited[next] = 1;
                    ans ++;
                    q.push(next);
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}