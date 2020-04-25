//
// Created by marble on 20. 4. 25..
//

// 그래프를 정렬하는 위상정렬 문제를 풀어보았다.
// 기본 문제라서 어려울 것은 없었다.

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

int n, m;
vector<int> linked[100005];
vector<int> ans;
int visited[100005] = {0};
int linked_count[32005] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int x, y;
        cin >> x >> y;
        linked[x].push_back(y);
        linked_count[y] ++;
    }

    queue<int> q;

    for(int i=1;i<=n;i++) {
        if(linked_count[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int x = q.front();
        ans.push_back(x);
        q.pop();

        for(int i=0;i<linked[x].size();i++) {
            int next = linked[x][i];
            linked_count[next] --;
            if(linked_count[next] == 0) {
                q.push(next);
            }
        }
    }

    for(auto &it:ans) {
        cout << it << ' ';
    }

    return 0;
}