#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n, m, num, cnt = 0;
vector<int> ans;
map<int, int> arr;
map<int, int>::iterator it;

void input()
{
	cin >> n >> m;

	while (n--)
	{
		cin >> num;
		arr[num] = 1;
	}

	while (m--)
	{
		cin >> num;

		if (arr[num])
			arr[num] = 0;
	}
}

void solution()
{
	for (it = arr.begin(); it != arr.end(); it++)
	{
		if (it->second)
		{
			cnt++;
			ans.push_back(it->first);
		}
	}

	cout << cnt << '\n';

	if (cnt)
		for (auto i : ans)
			cout << i << ' ';
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