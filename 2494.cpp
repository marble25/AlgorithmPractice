//
// Created by marble on 20. 3. 27..
//

// 수정하다 보니 맞은 문제
// 정확히 어떤 부분을 수정해서 맞았는지 모르겠다..

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int MAX = 10000;
const int BIG_NUM = 987654321;

int n;
char arr[MAX+5];
char goal[MAX+5];
int dp[MAX+1][10]; // dp[i][j] : i번째칸을 돌릴 때 현재 나사가 왼쪽으로 j만큼 돌아가 있다면 나오는 최소 횟수
int parent[MAX+1][10]; // dp[i][j]의 parent 저장
int rot[MAX+1][10]; // 양수면 왼쪽, 음수면 오른쪽으로 돌아간 정도를 저장
vector<int> v;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    cin >> arr;
    cin >> goal;

    for(int i=0;i<n;i++) {
        for(int j=0;j<10;j++) {
            dp[i][j] = BIG_NUM;
        }
    }

    int diff = (goal[0] - arr[0]+10) % 10;
    dp[0][diff] = diff; // 왼쪽
    dp[0][0] = (arr[0]-goal[0]+10) % 10; // 오른쪽
    rot[0][diff] = dp[0][diff];
    rot[0][0] = -dp[0][0];

    for(int i=1;i<n;i++) {
        for(int j=0;j<10;j++) {
            int left_diff = (goal[i]-(arr[i]+j)+20)%10; // 현재 상태는 arr[i]+j이므로 goal에서 빼준 만큼이 왼쪽으로 돌렸을 때 돌리는 횟수이다. 양수로 만들기 위해 20을 더해줌
            int right_diff = ((arr[i]+j)-goal[i]+20)%10; // 오른쪽으로 돌려야 하는 횟수. 양수로 만들기 위해 20 더해줌

            if(dp[i][(j+left_diff)%10] > dp[i-1][j] + left_diff) { // 더 작은값이 들어오면
                dp[i][(j+left_diff)%10] = dp[i-1][j] + left_diff; // 업데이트
                parent[i][(j+left_diff)%10] = j; // 부모 설정
                rot[i][(j+left_diff)%10] = left_diff; // 돌아간 정도 설정
            }

            if(dp[i][j] > dp[i-1][j] + right_diff) { // 더 작은 값이 들어오면
                dp[i][j] = dp[i-1][j] + right_diff; // 업데이트
                parent[i][j] = j; // 부모 설정
                rot[i][j] = -right_diff; // 돌아간 정도 설정
            }

        }
    }

    int min_val = BIG_NUM;
    int min_index = 0;
    for(int i=0;i<10;i++) {
        if(min_val > dp[n-1][i]) { // 가장 작은 값 찾기
            min_index = i;
            min_val = dp[n-1][i];
        }
    }

    if(min_val == BIG_NUM) {
        cout << 0 << '\n';
        return 0;
    }

    cout << min_val << '\n';

    for(int i=n-1;i>0;i--) { // 가장 작은 값에서 시작해서 부모로 타고 올라가면서 경로를 v에 저장
        v.push_back(rot[i][min_index]);
        min_index = parent[i][min_index];
    }
    v.push_back(rot[0][min_index]);

    reverse(v.begin(), v.end());
    for(int i=0;i<n;i++) {
        if(v[i] == 0) continue;
        cout << i+1 << ' ' << v[i] << '\n';
    }

    return 0;
}