//
// Created by marble on 20. 4. 9..
//

// 시간 복잡도의 급격한 차이를 경험한 문제
// 느릴 것 같던 방법이 오히려 빠르네..

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

int n;
string s;
char s_mat[12][12] = {0};
int arr[12] = {0};
int sum[12] = {0};

void brute_force(int stage) {
    if(stage == n+1) {
        for(int i=1;i<=n;i++) {
            cout << arr[i] << ' ';
        }
        exit(0);
    }

    // 이전 값과 현재 값을 사용해서 미리 범위를 줄여놓음
    int start = 1;
    int end = 10;

    if(s_mat[stage][stage] == '0') { // 현재 수가 0이면
        start = 0;
        end = 0;
    } else if(s_mat[stage][stage] == '+') { // 현재 수가 양수이면
        if(arr[stage-1] < 0) { // 이전 수가 0보다 작은 경우
            if(s_mat[stage-1][stage] == '+') { // 이전 수와 현재 수 합이 양수라면
                start = abs(arr[stage-1]) + 1; // 이전수 절대값에 1 더한 값에서 시작
            } else if(s_mat[stage-1][stage] == '0') { // 이전 수와 현재 수 합이
                start = abs(arr[stage-1]); // 그 값만 돌림
                end = start;
            } else if(s_mat[stage-1][stage] == '-') { // 이전 수와 현재 수 합이 음수라면
                end = abs(arr[stage-1]) - 1; // 이전 수 절대값에 하나 뺀 값까지 for 돌림
            }
        }
    } else if(s_mat[stage][stage] == '-') { // 현재 수가 음수라면
        if(arr[stage-1] > 0) { // 이전 수가 0보다 큰 경우
            if(s_mat[stage-1][stage] == '-') { // 이전 수와 현재 수 합이 음수라면
                start = abs(arr[stage-1]) + 1; // 이전수 절대값에 1 더한 값에서 시작
            } else if(s_mat[stage-1][stage] == '0') { // 이전 수 + 현재 수가 0인 경우
                start = abs(arr[stage-1]); // 그 값만 돌림
                end = start;
            } else if(s_mat[stage-1][stage] == '+') { // 이전 수 + 현재 수가 양수라면
                end = abs(arr[stage-1]) - 1; // 이전 수 절대값에 하나 뺀 값까지 for 돌림
            }
        }
        // 음수 변환
        start = -start;
        end = -end;

        // 크기에 맞게 swap
        swap(start, end);
    }

    for(int i=start;i<=end;i++) {
        arr[stage] = i;
        sum[stage] = sum[stage-1] + i;

        bool flag = true;
        for(int j=1;j<stage-1;j++) {
            if(sum[stage] - sum[j-1] > 0 && s_mat[j][stage] == '+') continue; // j~stage값이 양수일 때 그게 맞는지 확인
            if(sum[stage] - sum[j-1] == 0 && s_mat[j][stage] == '0') continue; // j~stage값이 0일 때 그게 맞는지 확인
            if(sum[stage] - sum[j-1] < 0 && s_mat[j][stage] == '-') continue; // j~stage값이 음수일 때 그게 맞는지 확인

            flag = false;
            break;
        }

        if(!flag) continue; // 조건이 하나라도 틀리면 다른 값
        brute_force(stage+1);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    cin >> s;

    int k = 0;
    for(int i=1;i<=n;i++) { // s_mat[i][j] : i~j까지의 합 결과
        for(int j=i;j<=n;j++) {
            s_mat[i][j] = s[k++];
        }
    }
    brute_force(1);

    return 0;
}