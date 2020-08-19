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

int n, s, d;
vector<int> linked[100005];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> s >> d;
    for(int i=0;i<n;i++) {
        int x, y;
        cin >> x >> y;
        linked[x].push_back(y);
        linked[y].push_back(x);
    }



    return 0;
}