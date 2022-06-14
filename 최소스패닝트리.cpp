#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	int s, e, dis;
	// 시작점, 끝점, 가중치
};

bool cmp(node a, node b)
{
	return a.dis < b.dis;
}

int v, e, root[10001], cnt[10001], ans;
// 정점, 간선, 부모 노드, 그래프에 속한 노드의 개수
node path[100000];

void input()
{
	cin >> v >> e;

	for (int i = 0; i < e; i++)
		cin >> path[i].s >> path[i].e >> path[i].dis;
}

int find(int n)
{
	if (root[n] == n)
		return n;

	return root[n] = find(root[n]);
}

void solution()
{
	sort(path, path + e, cmp);

	for (int i = 1; i <= v; i++)         // union_find를 위한 초기화
	{
		root[i] = i;
		cnt[i] = 1;
	}

	for (int i = 0; i < e; i++)
	{
		if (cnt[1] == v)                // 모든 정점이 연결됐다면 탈출
			break;

		int sroot = find(path[i].s);    // 시작점의 부모노드
		int eroot = find(path[i].e);    // 끝점의 부모노드

		if (sroot == eroot)             // 이미 같은 그래프에 속해있다면 연결할 필요 x
			continue;

		ans += path[i].dis;

		// 더 작은 정점을 부모노드로 설정 후 노드 개수 더해줌
		if (sroot < eroot)
		{
			root[eroot] = sroot;
			cnt[sroot] += cnt[eroot];
		}

		else
		{
			root[sroot] = eroot;
			cnt[eroot] += cnt[sroot];
		}
	}

	cout << ans;
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