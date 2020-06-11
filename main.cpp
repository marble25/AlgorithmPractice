

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

int n, a, b;
int pos[500005] = {0};
int temp[500005] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> a >> b;
    pos[a] = 1;
    pos[b] = 2;

    for(int i=1;;i++) {
        bool is_reachable = false;

        int diff = pow(2, i-1);

        for(int j=1;j<=n;j++) {
            if(pos[j] != 0) {
                is_reachable = true;

                int duck = pos[j];
                if(j-diff > 0) {
                    if(temp[j-diff] == 3-duck) {
                        cout << i;
                        return 0;
                    }
                    temp[j-diff] = duck;
                }

                if(j+diff <= n) {
                    if(temp[j+diff] == 3-duck) {
                        cout << i;
                        return 0;
                    }
                    temp[j+diff] = duck;
                }
            }
        }

        if(!is_reachable) {
            cout << -1;
            break;
        }

        memcpy(pos, temp, sizeof(pos));
        memset(temp, 0, sizeof(temp));
    }

    return 0;
}