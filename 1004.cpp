//
// Created by marble on 20. 4. 16..
//

#include <iostream>

using namespace std;

int T;
long long x1, y1, x2, y2;
int n;
long long cx, cy, r;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;
    while(T--) {
        int cnt = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;
        for(int i=0;i<n;i++) {
            cin >> cx >> cy >> r;
            if((x1-cx) * (x1-cx) + (y1-cy) * (y1-cy) <= r*r) {
                if((x2-cx) * (x2-cx) + (y2-cy) * (y2-cy) <= r*r) {
                    continue;
                }
                cnt++;
            } else if((x2-cx) * (x2-cx) + (y2-cy) * (y2-cy) <= r*r) {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}