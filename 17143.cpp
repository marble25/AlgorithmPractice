//
// Created by marble on 20. 4. 8..
//

// 특별히 어려운 알고리즘은 없는데 주어진 조건이 너무 복잡했던 문제
// 그래도 한번에 맞추었다.

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

int r, c, m;
tuple<int, int, int, int, int, int> sharks[10005]; // 상어들이 들어있는 배열(tuple로 구현)
pair<int, int> map[105][105]; // 중복된 상어를 체크할 map

int catch_shark(int target_col) {
    int min_x = INT32_MAX;
    int min_idx = -1;
    for(int j=0;j<m;j++) {
        int row = get<1>(sharks[j]);
        int col = get<2>(sharks[j]);
        if(col == target_col) { // y값이 같을 때
            if(min_x > row) { // 가장 작은 row값으로 업데이트
                min_x = row;
                min_idx = j;
            }
        }
    }
    if(min_idx != -1) { // target_col에 하나라도 상어가 있다면
        int size = get<5>(sharks[min_idx]);
        sharks[min_idx] = tuple(-1, -1, -1, -1, -1, -1); // 땅과 가장 가까운 상어 삭제
        return size; // size 리턴
    }
    return 0;
}
void update_pos() {
    for(int j=0;j<m;j++) {
        int idx = get<0>(sharks[j]);
        int x = get<1>(sharks[j]);
        int y = get<2>(sharks[j]);
        int speed = get<3>(sharks[j]);
        int direction = get<4>(sharks[j]);
        int size = get<5>(sharks[j]);

        if(idx == -1) continue;

        switch(direction) {
            case 1: x -= speed; break;
            case 2: x += speed; break;
            case 3: y += speed; break;
            case 4: y -= speed; break;
        }

        if(x < 1 || x > r) { // x가 범위 밖으로 넘어갔을 때
            int ex = (x < 1 ? 1-x : x-r); // 넘어간 거리
            if(((ex-1) / (r-1)) % 2 == 0) { // 방향 반대로 바꿔줌
                direction = 3 - direction;
            }

            if(direction == 1) { // 가는 방향이 위면
                x = (ex % (r-1) == 0 ? 1 : r - (ex % (r-1))); // 끝까지 갔으면 1
            } else {
                x = (ex % (r-1) == 0 ? r : 1 + (ex % (r-1))); // 끝까지 갔으면 r
            }
        }
        if(y < 1 || y > c) { // y가 범위 밖으로 넘어갔을 때
            int ex = (y < 1 ? 1-y : y-c); // 넘어간 거리
            if(((ex-1) / (c-1)) % 2 == 0) { // 방향 반대로 바꿔줌
                direction = 7 - direction;
            }

            if(direction == 3) { // 가는 방향이 오른쪽이면
                y = (ex % (c-1) == 0 ? c : 1 + (ex % (c-1))); // 끝까지 갔으면 c
            } else {
                y = (ex % (c-1) == 0 ? 1 : c - (ex % (c-1))); // 끝까지 갔으면 1
            }
        }
        sharks[j] = tuple(idx, x, y, speed, direction, size); // 상어 값 업데이트
    }
}

// 맵 초기화
void clear_map() {
    for(int i=0;i<=r;i++) {
        for(int j=0;j<=c;j++) {
            map[i][j] = make_pair(-1, -1);
        }
    }
}

// 중복되는 상어 제거
void eat_sharks() {
    for(int i=0;i<m;i++) {
        int idx = get<0>(sharks[i]);
        int x = get<1>(sharks[i]);
        int y = get<2>(sharks[i]);
        int size = get<5>(sharks[i]);
        if(idx == -1) continue; // 상어가 이미 없으면 넘어감

        if(map[x][y].second != -1 && map[x][y].second < size) { // 기존에 있던 상어가 작으면 기존 상어 삭제하고 맵 덮어씌우기
            int deleted_idx = map[x][y].first;
            sharks[deleted_idx] = tuple(-1, -1, -1, -1, -1, -1);
            map[x][y] = make_pair(idx, size);
        } else if(map[x][y].second > size) { // 기존에 있던 상어가 더 크면 새로운 상어는 삭제
            sharks[i] = tuple(-1, -1, -1, -1, -1, -1);
        } else { // default로 상어를 맵에 추가
            map[x][y] = make_pair(idx, size);
        }

    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> r >> c >> m;

    for(int i=0;i<m;i++) {
        int x, y, s, d, z;
        cin >> x >> y;
        cin >> s >> d >> z;
        sharks[i] = tuple(i, x, y, s, d, z);
    }
    int ans = 0;
    for(int i=1;i<=c;i++) {
        ans += catch_shark(i);
        update_pos();
        clear_map();
        eat_sharks();
    }
    cout << ans;
    return 0;
}