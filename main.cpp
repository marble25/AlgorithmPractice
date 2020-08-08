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
int t[505] = {0};
vector<int> linked[505];
int order[505] = {0};
int visited[505] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> t[i];
        while(true) {
            int x;
            cin >> x;
            if(x == -1) break;
            linked[x].push_back(i);
            order[i]++;
        }
    }

    queue<int> q;

    for(int i=1;i<=n;i++) {
        if(order[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(int i=0;i<linked[x].size();i++) {
            int it=linked[x][i];
            order[it]--;
            visited[it] = max(visited[it], visited[x] + t[x]);
            if(order[it] == 0) {
                q.push(it);

            }
        }
    }

    for(int i=1;i<=n;i++) {
        cout << visited[i] + t[i] << '\n';
    }

    return 0;
}