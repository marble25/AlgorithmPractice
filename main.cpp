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
int arr[2005];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int cnt = 0;
    for(int i=0;i<n;i++) {
        int st=0, en=n-1;
        while(st < en) {
            if(arr[st] + arr[en] < arr[i]) {
                st++;
            } else if(arr[st] + arr[en] > arr[i]) {
                en--;
            } else {
                if(st != i && en != i) {
                    cnt++;
                    break;
                }

                if(en == i) {
                    en--;
                } else if(st == i) {
                    st++;
                }
            }
        }
    }
    cout << cnt;

    return 0;
}