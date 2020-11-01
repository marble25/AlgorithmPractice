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

int t;
int a, b;

pair<int, char> parent[10005];
queue<int> q;
int visited[10005];

void bfs(int x) {
    while(!q.empty()) {
        q.pop();
    }

    q.push(x);
    visited[x] = 1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        int d = (x * 2) % 10000;
        int s = (x - 1 + 10000) % 10000;

        int l = (x / 1000) + (x % 1000) * 10;
        int r = (x / 10) + (x % 10) * 1000;

        if(!visited[d]) {
            parent[d] = {x, 'D'};
            visited[d] = 1;
            q.push(d);
        }

        if(!visited[s]) {
            parent[s] = {x, 'S'};
            visited[s] = 1;
            q.push(s);
        }

        if(!visited[l]) {
            parent[l] = {x, 'L'};
            visited[l] = 1;
            q.push(l);
        }

        if(!visited[r]) {
            parent[r] = {x, 'R'};
            visited[r] = 1;
            q.push(r);
        }

        if(d == b || s == b || l == b || r == b) {
            return;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    while(t--) {
        cin >> a >> b;

        memset(visited, 0, sizeof(visited));

        bfs(a);

        stack<char> stk;
        while(b != a) {
            stk.push(parent[b].second);
            b = parent[b].first;
        }

        while(!stk.empty()) {
            cout << stk.top();
            stk.pop();
        }

        cout << "\n";
    }
    return 0;
}