//
// Created by marble on 20. 10. 12..
//

// 뭔가 풀고나도 찝찝한 문제

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

int r=3, c=3;
int tar_r, tar_c, k;

int arr[305][305] = {0};
int check[105] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> tar_r >> tar_c >> k;
    for(int i=1;i<=3;i++) {
        for(int j=1;j<=3;j++) {
            cin >> arr[i][j];
        }
    }

    if(arr[tar_r][tar_c] == k) { // 한번도 안움직여도 되면 0 출력
        cout << 0;
        return 0;
    }

    for(int time=1;time<=100;time++) {
        if(r >= c) { // row가 column보다 클 때
            int temp_c = 0;
            for(int i=1;i<=r;i++) {
                memset(check, 0, sizeof(check));
                vector<pair<int, int>> v;
                for(int j=1;j<=c;j++) {
                    check[arr[i][j]]++; // 개수를 파악
                }

                for(int j=1;j<=100;j++) {
                    if(check[j] == 0) continue; // 개수가 0이면 넘어감
                    v.push_back({check[j], j}); // 개수, 숫자 순으로 넣어줌(정렬을 위해)
                }

                sort(v.begin(), v.end());
                for(int j=1;j<=v.size();j++) { // 벡터값을 순서대로 넣어줌
                    arr[i][j*2-1] = v[j-1].second;
                    arr[i][j*2] = v[j-1].first;
                }

                for(int j=v.size()*2+1;j<=300;j++) { // 나머지는 0으로 채움
                    arr[i][j] = 0;
                }
                temp_c = max(temp_c, (int)v.size() * 2); // column값 업데이트
            }

            c = temp_c;
        } else {
            int temp_r = 0;
            for(int j=1;j<=c;j++) {
                memset(check, 0, sizeof(check));
                vector<pair<int, int>> v;
                for(int i=1;i<=r;i++) {
                    check[arr[i][j]]++; // 개수를 파악
                }

                for(int i=1;i<=100;i++) {
                    if(check[i] == 0) continue; // 개수가 0이면 넘어감
                    v.push_back({check[i], i}); // 개수, 숫자 순으로 넣어줌(정렬을 위해)
                }

                sort(v.begin(), v.end());
                for(int i=1;i<=v.size();i++) { // 벡터 값을 순서대로 넣어줌
                    arr[i*2-1][j] = v[i-1].second;
                    arr[i*2][j] = v[i-1].first;
                }

                for(int i=v.size()*2+1;i<=300;i++) { // 나머지는 0으로 채움
                    arr[i][j] = 0;
                }
                temp_r = max(temp_r, (int)v.size() * 2); // row값 업데이트
            }

            r = temp_r;
        }

        if(arr[tar_r][tar_c] == k) { // 목표했던 값이 오면 출력하고 종료
            cout << time;
            return 0;
        }
    }

    cout << -1;

    return 0;
}