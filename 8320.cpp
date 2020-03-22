//
// Created by marble on 20. 3. 22..
//

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int dp[10001] = {0};
    int result = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=sqrt(i);j++) {
            if(i%j==0) {
                dp[i] ++;
            }
        }
        result += dp[i];
    }
    cout << result << endl;
    return 0;
}