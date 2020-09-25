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
int arr[10][10] = {0};
int ans = 987654321;

vector<int> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0;i<n;i++) {
        v.push_back(i);
    }

    do {
        int cost = arr[v[n-1]][v[0]];
        if(cost == 0) continue;

        bool flag = false;
        for(int i=0;i<n-1;i++) {
            int current_cost = arr[v[i]][v[i+1]];
            if(current_cost == 0) {
                flag = true;
                break;
            }

            cost += current_cost;
        }

        if(flag) continue;
        ans = min(ans, cost);
    } while (next_permutation(v.begin(), v.end()));

    cout << ans;

    return 0;
}