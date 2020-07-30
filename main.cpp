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

int n;
vector<int> linked[55];
int parent[55] = {0};
int child[55] = {0};
int visited[55] = {0};

void call() {
    queue<int> q;

    q.push(0);
    visited[0] = 1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        int current;
        int mx = -1;
        for(auto &it:linked[x]) {
            if(visited[it] == 0 && mx < child[it]) {
                mx = linked[it].size();
                current = it;
            }
        }

        if(mx != -1) {
            visited[current] = visited[x] + 1;
            child[x]--;
            q.push(x);
            q.push(current);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> parent[i];
        if(parent[i] != -1) {
            child[parent[i]]++;
            linked[parent[i]].push_back(i);
        }
    }

    call();

    int ans = 0;
    for(int i=0;i<n;i++) {
        ans = max(ans, visited[i]);
    }

    cout << ans;

    return 0;
}