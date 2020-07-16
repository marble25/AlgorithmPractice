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

int n;
int t[10005] = {0};
int start[10005] = {0};
int prior[10005] = {0};
vector<int> linked[10005];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> t[i];

        int n_job;
        cin >> n_job;

        prior[i] = n_job;
        for(int j=0;j<n_job;j++) {
            int x;
            cin >> x;
            linked[x].push_back(i);
        }
    }

    queue<int> q;

    for(int i=1;i<=n;i++) {
        if(prior[i] == 0) {
            q.push(i);
        }
    }

    int ans = 0;
    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(auto &it:linked[x]) {
            prior[it]--;
            start[it] = max(start[it], start[x] + t[x]);
            if(prior[it] == 0) {
                q.push(it);
            }
        }
    }

    for(int i=1;i<=n;i++) {
        ans = max(ans, start[i] + t[i]);
    }

    return 0;
}