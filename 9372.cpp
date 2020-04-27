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

        int ans = n-1;

        cout << ans << '\n';
    }

    return 0;
}