#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define N 55

using namespace std;

struct node {
	int a, b, c;
};

int n, cnt, p[N];
vector<int> con[N];
node arr[N];
bool check[N];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].a >> arr[i].b >> arr[i].c;
}

void init()
{
	for (int i = 0; i < n; i++)
	{
		p[i] = i;

		// 서로 잡아먹는 것을 방지하기 위해 (j = 0부터 시작하면 서로 잡아먹음)
		// 한 쪽만 가리킬 수 있도록 처리
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i].a >= arr[j].a && arr[i].b >= arr[j].b && arr[i].c >= arr[j].c)
				con[i].push_back(j);

			else if (arr[i].a <= arr[j].a && arr[i].b <= arr[j].b && arr[i].c <= arr[j].c)
				con[j].push_back(i);
		}
	}
}

bool dfs(int node)
{
	for (auto i : con[node])
	{
		if (check[i])
			continue;

		check[i] = 1;

		if (p[i] == i || dfs(p[i]))
		{
			p[i] = node;
			return 1;
		}
	}

	return 0;
}

void solution()
{
	init();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (dfs(i))
				cnt++;

			memset(check, 0, sizeof(check));
		}
	}
	
	cout << n - cnt;
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

	solve();
	return 0;
}