//
// Created by marble on 20. 3. 22..
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
vector<pair<int, int>> v;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(y, x));
    }
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++) {
        cout << v[i].second << " " << v[i].first << '\n';
    }
    return 0;
}