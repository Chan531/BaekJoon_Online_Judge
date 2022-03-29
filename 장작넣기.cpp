#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

struct node {
	string route;
	int pos;
};

int n, w, t, k, ans = 0;
int fire[6], testfire[6], decrease[6];
vector<string> testcase;        // 경로의 경우의 수 보관

void input()
{
	cin >> n >> w >> t >> k;
	for (int i = 0; i < n; i++)
		cin >> fire[i];
}

void search()
{
	queue<node> q;
	q.push({ "", w });

	while (!q.empty())
	{
		string route = q.front().route;
		int pos = q.front().pos;
		q.pop();

		if (route.length() == t - 1)
		{
			testcase.push_back(route);
			continue;
		}
		
		if (pos == 0)              // 현재 위치가 가장 왼쪽이라면
		{
			q.push({ route + '2', pos });       // 이동x
			q.push({ route + '3',pos + 1 });    // 오른쪽으로 이동
		}

		else if (pos == n - 1)     // 현재 위치가 가장 오른쪽이라면
		{
			q.push({ route + '1', pos - 1 });   // 왼쪽으로 이동
			q.push({ route + '2', pos });       // 이동x
		}

		else
		{
			q.push({ route + '1', pos - 1 });   // 왼쪽으로 이동
			q.push({ route + '2', pos });       // 이동x
			q.push({ route + '3',pos + 1 });    // 오른쪽으로 이동
		}
	}
}

void decreasefire(int pos)          // 장작을 넣은 곳 빼고 화력을 감소시킴
{
	memset(decrease, 0, n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		if (i == pos)
			continue;

		decrease[i] -= 3;

		if (i == 0 && testfire[i + 1] > 0)
			decrease[i]++;

		else if (i == n - 1 && testfire[i - 1] > 0)
			decrease[i]++;

		else if (i > 0 && i < n - 1)
		{
			if (testfire[i - 1] > 0)
				decrease[i]++;

			if (testfire[i + 1] > 0)
				decrease[i]++;
		}
	}

	for (int i = 0; i < n; i++)
		testfire[i] += decrease[i];
}

bool checkfire()
{
	int cnt = n;
	for (int i = 0; i < n; i++)
	{
		if (testfire[i] <= 0)
			cnt--;
	}
	
	if (cnt < k)
		return false;

	return true;
}

void solution()
{
	search();
	for (int i = 0; i < testcase.size(); i++)
	{
		string route = testcase[i];
		copy(fire, fire + n, testfire);
		decreasefire(-1);
		int pos = w;

		for (int j = 0; j < route.length(); j++)
		{
			if (route[j] == '1')
				pos--;
			else if (route[j] == '3')
				pos++;

			decreasefire(pos);
		}

		if (checkfire())
			ans++;
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