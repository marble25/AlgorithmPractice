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

int n, w;
double m;

int mp[1000][1000] = {0};
vector<pair<int, int>> place;
vector<pair<int, int>> linked;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> w;
    cin >> m;
    for(int i=0;i<n;i++) {
        int x, y;
        cin >> x >> y;
        mp[x][y] = 1;
        place.push_back({x, y});
    }

    for(int i=0;i<w;i++) {
        int x, y;
        cin >> x >> y;
        linked.push_back({x, y});
    }

    return 0;
}