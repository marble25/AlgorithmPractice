//
// Created by marble on 20. 3. 22..
//

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr1[10], arr2[10];
    for(int i=0;i<10;i++) {
        cin >> arr1[i];
    }
    for(int i=0;i<10;i++) {
        cin >> arr2[i];
    }
    sort(arr1, arr1+10);
    sort(arr2, arr2+10);

    int score1 = arr1[9] + arr1[8] + arr1[7];
    int score2 = arr2[9] + arr2[8] + arr2[7];

    cout << score1 << " " << score2 << endl;
    return 0;
}