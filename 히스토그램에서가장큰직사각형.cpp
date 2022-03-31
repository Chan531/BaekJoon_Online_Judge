#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

struct node {
	long long val;
	int idx;
};

int n;
long long arr[100000], rans[100000], lans[100000], ans[100000];

void input()
{
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void rsol()
{
	stack<node> s;

	for (int i = 0; i < n; i++)
	{
		while (!s.empty() && s.top().val > arr[i])
		{
			long long val = s.top().val;
			int idx = s.top().idx;

			rans[idx] = (i - idx) * val;
			s.pop();
			continue;
		}

		s.push({ arr[i], i });
	}

	int midx = s.top().idx + 1;

	while (!s.empty())
	{
		long long val = s.top().val;
		int idx = s.top().idx;

		rans[idx] = (midx - idx) * val;
		s.pop();
	}
}

void lsol()
{
	stack<node> s;

	for (int i = n - 1; i >= 0; i--)
	{
		while (!s.empty() && s.top().val > arr[i])
		{
			long long val = s.top().val;
			int idx = s.top().idx;

			lans[idx] = (idx - i) * val;
			s.pop();
			continue;
		}

		s.push({ arr[i], i });
	}

	int midx = s.top().idx - 1;

	while (!s.empty())
	{
		long long val = s.top().val;
		int idx = s.top().idx;

		lans[idx] = (idx - midx) * val;
		s.pop();
	}
}

void solution()
{
	rsol();       // 자기보다 큰 idx만 고려할 때
	lsol();       // 자기보다 작은 idx만 고려할 때
	
	for (int i = 0; i < n; i++)
		ans[i] = lans[i] + rans[i] - arr[i];

	cout << *max_element(ans, ans + n) << '\n';
}

void solve()
{
	while (1)
	{
		cin >> n;

		if (n == 0)
			break;

		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}