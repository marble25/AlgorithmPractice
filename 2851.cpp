//
// Created by marble on 20. 3. 22..
//

#include <iostream>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, i;
    int result = 0;
    for(i=0;i<10;i++) {
        cin >> a;
        if(abs(100-result) < abs(100-(result+a))) {
            break;
        } else if(abs(100-result) == abs(100-(result+a))) {
            cout << result + a << endl;
            return 0;
        }
        result += a;
    }
    cout << result;
    return 0;
}