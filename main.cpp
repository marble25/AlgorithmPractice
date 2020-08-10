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

int n, s;
int arr[100005];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> s;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    int st = 0, en = -1;
    int sum = 0;
    int ans = 9999999;
    while(en < n) {
        if(sum < s) {
            en++;
            if(en == n) break;
            sum += arr[en];
        } else {
            ans = min(ans, en-st+1);
            sum -= arr[st++];
        }
    }
    if(ans == 9999999) cout << 0;
    else cout << ans;
    return 0;
}