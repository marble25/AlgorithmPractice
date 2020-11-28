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

int n;
vector<pair<int, int>> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(v[0].second);

    for(int i=1;i<n;i++) {
        if(pq.top() <= v[i].first) {
            pq.pop();
        }
        pq.push(v[i].second);
    }

    cout << pq.size();

    return 0;
}