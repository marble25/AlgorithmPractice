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

int l, p, v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=1;;i++) {
        cin >> l >> p >> v;
        if(l == 0 && p == 0 && v == 0) {
            break;
        }

        int ans = (v/p)*l + min(v%p, l);
        cout << "Case " << i << ": " << ans << "\n";
    }

    return 0;
}