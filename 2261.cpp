#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>

#define inf 100000000

using namespace std;

typedef pair<int, int> pii;

map<pii, int> mp;

double getDist(pii a, pii b)
{
	int x = a.first - b.first;
	int y = a.second - b.second;

	return (double)(x*x + y*y);
}

int main()
{
	int n;
	scanf("%d", &n);

	vector<pii> vc;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);

		vc.push_back({ x,y });
	}

	// x에 대해 정렬
	sort(vc.begin(), vc.end());

	// 처음 두 값 map에 추가(y, x 순서)
	mp[{vc[0].second, vc[0].first}] = 1;
	mp[{vc[1].second, vc[1].first}] = 1;

	// 최솟값 초기화
	double ans = getDist(vc[0], vc[1]);

	int last = 0;

	for (int i = 2; i < n; i++)
	{
		// while문은 최솟값보다 x간의 거리가 더 큰 것을 제거하는 과정
		// x간의 거리가 최솟값 보다 더 크면 y값을 비교할 필요가 없다.
		while (last < i)
		{
			// i > last
			int dx = vc[i].first - vc[last].first;

			// 최솟값이 더 크거나 같으면 break;(검사여지 없음)
			if (dx * dx <= ans)
				break;

			// 최솟값 보다 더 큰 last에 해당하는 mp값 제거
			mp.erase({ vc[last].second, vc[last].first });
			last++;
		}

		// ans의 실제 거리
		int limit = sqrt(ans);

		// y좌표를 봤을 때 현재 알고있는 최솟값 기준으로 답일 수 있는 영역 설정
		auto lo = mp.lower_bound({ vc[i].second - limit, -inf });
		auto up = mp.upper_bound({ vc[i].second + limit,  inf });

		// 그 영역 내에서 최솟값
		for (auto it = lo; it != up; it++)
			ans = min(ans, getDist({ it->first.second, it->first.first }, vc[i]));

		// map에 추가
		mp[{vc[i].second, vc[i].first}] = 1;
	}

	printf("%d", (int)ans);
	return 0;
}
