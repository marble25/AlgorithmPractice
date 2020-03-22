//
// Created by marble on 20. 3. 22..
//

#include <iostream>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, w, h;
    cin >> n >> w >> h;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        if(x * x <= w * w + h * h) {
            cout << "DA" << endl;
        } else {
            cout << "NE" << endl;
        }
    }
    return 0;
}