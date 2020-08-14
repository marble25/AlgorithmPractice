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

long long n, m;
long long mn = 100000005, mx = -1;
vector<pair<long long, long long>> people;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        long long x, y;
        cin >> x >> y;
        if(x > y) {
            people.push_back({x, y});
        }
    }
    if(people.empty()) {
        cout << m;
        return 0;
    }

    sort(people.begin(), people.end(), greater<>());

    long long total = 0;
    long long len = people[0].second - people[0].first;
    long long start = people[0].first;

    int sz = people.size();
    for(int i=1;i<sz;i++) {
        if(people[i].first < start - len) {
            total += len;
            start = people[i].first;
        }
        if(people[i].second < start - len) {
            len = start - people[i].second;
        }
    }

    return 0;
}