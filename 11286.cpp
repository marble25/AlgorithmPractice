//
// Created by marble on 20. 3. 22..
//

//
// Created by marble on 20. 3. 22..
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    priority_queue<int, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        if(x == 0) {
            cout << (pq.empty()?0:pq.top().second) << '\n';
            if(!pq.empty()) pq.pop();
        } else {
            pq.push(make_pair(abs(x), x));
        }
    }
    return 0;
}