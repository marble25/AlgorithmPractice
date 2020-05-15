//
// Created by marble on 20. 5. 16..
//

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
        int linked = 1;
        while(j < n-1) {
            if(mp[i][j] == mp[i][j+1]) { // 뒷값과 같다면
                linked++;
            } else if(mp[i][j] == mp[i][j+1] + 1) { // 현재 값이 뒷값 + 1이라면
                if(j+l >= n) break; // 범위를 넘어가면 break

                bool flag = false;
                for(int k=2;k<=l;k++) {
                    if(mp[i][j+1] != mp[i][j+k]) { // 같지 않으면
                        flag = true;
                        break;
                    }
                }

                if(flag) break;

                j += l; // l칸 뒤로 넘어감
                linked = 0; // 연결된 개수를 0으로 하고 이번 칸을 다시 확인
                continue;
            } else if(mp[i][j] == mp[i][j+1] - 1) { // 현재 값이 뒷값 - 1이라면
                if(linked < l) { // 연결된 동일 값이 l개보다 작을 때
                    break;
                }
                linked = 1; // 연결된 갯수를 1로 함
            } else { // 1보다 큰 높이 차이라면 break
                break;
            }

            j++;
        }

        if(j >= n-1) { // 끝까지 도착했다면 정답으로 인정
            ans++;
        }
    }

    for(int j=0;j<n;j++) {
        int i=0;
        int linked = 1;
        while(i < n-1) {
            if(mp[i][j] == mp[i+1][j]) { // 뒷값과 같다면
                linked++;
            } else if(mp[i][j] == mp[i+1][j] + 1) { // 현재 값이 뒷값 + 1이라면
                if(i+l >= n) break; // 범위를 넘어가면 break

                bool flag = false;
                for(int k=2;k<=l;k++) {
                    if(mp[i+1][j] != mp[i+k][j]) { // 같지 않으면
                        flag = true;
                        break;
                    }
                }

                if(flag) break;

                i += l; // l칸 뒤로 넘어감
                linked = 0; // 연결된 개수를 0으로 하고 이번 칸을 다시 확인
                continue;
            } else if(mp[i][j] == mp[i+1][j] - 1) { // 현재 값이 뒷값 - 1이라면
                if(linked < l) { // 연결된 동일 값이 l개보다 작을 때
                    break;
                }
                linked = 1; // 연결된 갯수를 1로 함
            } else { // 1보다 큰 높이 차이라면 break
                break;
            }

            i++;
        }

        if(i >= n-1) { // 끝까지 도착했다면 정답으로 인정
            ans++;
        }
    }

    cout << ans;

    return 0;
}