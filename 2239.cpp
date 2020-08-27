//
// Created by marble on 20. 8. 27..
//

// 백트래킹으로 맞추기는 했으나 시간이 생각보다 많이 나온다.
// 더 짧은 시간으로 풀어봐야겠다.

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

char s[10][10];

int row_checked[9][9] = {0};
int col_checked[9][9] = {0};
int box_checked[9][9] = {0};

bool find_answer(int x, int y) {
    if(x == 8 && y == 9) { // 끝까지 왔다면 출력
        for(int i=0;i<9;i++) {
            cout << s[i] << '\n';
        }
        exit(0);
    } else if(y == 9) { // y열의 끝까지 간다면 다음 줄로 감
        return find_answer(x+1, 0);
    }

    if(s[x][y] != '0') { // 이미 답이 들어가 있다면 다음으로 넘어감
        return find_answer(x, y+1);
    }

    int box_idx = (x / 3) * 3 + y / 3;

    for(int i=1;i<=9;i++) {
        int num = i;

        if(row_checked[x][num] == 1 ||
           col_checked[y][num] == 1 ||
           box_checked[box_idx][num] == 1) { // 이미 사용된 번호는 넘어감
            continue;
        }

        // 새로 받은 번호를 세팅해봄
        row_checked[x][num] = 1;
        col_checked[y][num] = 1;
        box_checked[box_idx][num] = 1;
        s[x][y] = num + '0';

        bool ret = find_answer(x, y+1);

        if(!ret) { // 정답이 아니면 다시 초기화
            row_checked[x][num] = 0;
            col_checked[y][num] = 0;
            box_checked[box_idx][num] = 0;
            s[x][y] = '0';
        }
    }

    return false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=0;i<9;i++) {
        cin >> s[i];
    }

    // 기존 값을 미리 세팅
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            int num = s[i][j] - '0';
            int box_idx = (i / 3) * 3 + j / 3;

            if(num != 0) {
                row_checked[i][num] = 1;
                col_checked[j][num] = 1;
                box_checked[box_idx][num] = 1;
            }
        }
    }

    find_answer(0, 0);

    return 0;
}