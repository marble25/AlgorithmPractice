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

int n, l;
int mp[105][105];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> l;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> mp[i][j];
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++) {
        int j=0;
        int linked = 0;
        while(j < n-1) {
            if(mp[i][j] != mp[i][j+1]) {
                if(mp[i][j] == mp[i][j+1] + 1) {
                    linked = 1;

                    int cnt = 0;
                    for(int k=1;k<=l;k++) {
                        if(j+k < n && mp[i][j+1] == mp[i][j+k]) {
                            cnt++;
                        } else {
                            break;
                        }
                    }

                    if(cnt == l) {
                        j += l;
                        continue;
                    } else {
                        break;
                    }
                } else if(mp[i][j] == mp[i][j+1] - 1) {
                    if(linked < l) {
                        break;
                    }
                    linked = 1;
                } else {
                    break;
                }



            } else {
                linked++;
            }
            j++;
        }

        if(j >= n-1) {
            ans++;
        }
    }


    for(int j=0;j<n;j++) {
        int i=0;
        int linked = 0;
        while(i < n-1) {
            if(mp[i][j] != mp[i+1][j]) {
                if(mp[i][j] == mp[i+1][j] + 1) {
                    linked = 1;

                    int cnt = 0;
                    for(int k=1;k<=l;k++) {
                        if(i+k < n && mp[i+1][j] == mp[i+k][j]) {
                            cnt++;
                        } else {
                            break;
                        }
                    }

                    if(cnt == l) {
                        i += l;
                        continue;
                    } else {
                        break;
                    }
                } else if(mp[i][j] == mp[i+1][j] - 1) {
                    if(linked < l) {
                        break;
                    }
                    linked = 1;
                } else {
                    break;
                }

            } else {
                linked++;
            }
            i++;
        }

        if(i >= n-1) {
            ans++;
        }
    }


    cout << ans;

    return 0;
}