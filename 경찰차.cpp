#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

struct point {
	int y, x;
};

// dp -> 경찰차 1이 마지막으로 해결한 사건(a), 경찰차 2가 마지막으로 해결한 사건(b)
// dp의 값 -> 경찰차 1이 마지막으로 해결한 사건이 a이고 2가 b라고 했을 때 나머지 모든 사건을 해결하기 위해 경찰차가 이동해야하는 최소 거리
int n, w, dp[1001][1001];
point p1[1001], p2[1001];

void input()
{
	cin >> n >> w;

	for (int i = 1; i <= w; i++)
	{
		int y, x;
		cin >> p1[i].y >> p1[i].x;

		p2[i].y = p1[i].y;
		p2[i].x = p1[i].x;
	}
}

// 거리 반환
int dis(point o, point t)
{
	return abs(o.y - t.y) + abs(o.x - t.x);
}

// 최소 거리 반환
int min_dis(int o, int t)
{
	// 모든 사건 탐색
	if (o == w || t == w)
		return 0;

	// 중복 방지
	if (dp[o][t] != -1)
		return dp[o][t];

	// 다음으로 해결할 사건
	int next = max(o, t) + 1;

	// 경찰차 1이 사건을 맡을 때 이동해야 하는 거리
	int odis = dis(p1[o], p1[next]) + min_dis(next, t);

	// 경찰차 2가 사건을 맡을 때 이동해야 하는 거리
	int tdis = dis(p2[t], p2[next]) + min_dis(o, next);

	return dp[o][t] = min(odis, tdis);
}

// 루트 출력
void routereview(int o, int t)
{
	if (o == w || t == w)
		return;

	// 다음으로 해결할 사건
	int next = max(o, t) + 1;

	// 경찰차 1이 다음 사건을 맡을 때(dis) 모든 사건을 해결하기 위해 앞으로 이동해야 하는 거리(dp)
	int odis = dp[next][t] + dis(p1[o], p1[next]);

	// 경찰차 2가 다음 사건을 맡을 때(dis) 모든 사건을 해결하기 위해 앞으로 이동해야 하는 거리(dp)
	int tdis = dp[o][next] + dis(p2[t], p2[next]);

	if (odis < tdis)
	{
		cout << 1 << '\n';
		routereview(next, t);
	}

	else
	{
		cout << 2 << '\n';
		routereview(o, next);
	}
}

void solution()
{
	p1[0].y = 1;
	p1[0].x = 1;
	p2[0].y = n;
	p2[0].x = n;

	// 초기값 설정
	memset(dp, -1, sizeof(dp));

	cout << min_dis(0, 0) << '\n';
	routereview(0, 0);
}

void solve()
{
	input();
	solution();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}