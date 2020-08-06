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
int arr[1005][3] = {0};

int cache[1005][3] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<3;j++) {
            cin >> arr[i][j];
        }
    }
    for(int j=0;j<3;j++) {
        cache[1][j] = arr[1][j];
    }

    int ans = 999999999;

    for(int k=0;k<3;k++) {
        for(int j=0;j<3;j++) {
            if(j == k) {
                cache[2][j] = 999999999;
            } else {
                cache[2][j] = arr[2][j] + cache[1][k];
            }
        }
        for(int i=3;i<=n;i++) {
            cache[i][0] = arr[i][0] + min(cache[i-1][1], cache[i-1][2]);
            cache[i][1] = arr[i][1] + min(cache[i-1][0], cache[i-1][2]);
            cache[i][2] = arr[i][2] + min(cache[i-1][1], cache[i-1][0]);
        }

        if(k == 0) {
            ans = min(ans, min(cache[n][1], cache[n][2]));
        } else if(k == 1) {
            ans = min(ans, min(cache[n][0], cache[n][2]));
        } else if(k == 2) {
            ans = min(ans, min(cache[n][0], cache[n][1]));
        }

    }

    cout << ans;

    return 0;
}