#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		cin >> m;
		arr.insert(arr.begin() + m, i);
	}

	while (!arr.empty())
	{
		cout << arr.back() << ' ';
		arr.pop_back();
	}
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