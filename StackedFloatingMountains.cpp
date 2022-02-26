#include <iostream>
#include <vector>

using namespace std;

int n, m, num;
vector<int> arr;

void input()
{
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
}

bool solution()
{
	for (int i = 2; i < m; i++)
	{
		if (arr[i] != arr[i - 1] + arr[i - 2])
			return false;
	}
	return true;
}

void solve()
{
	cin >> n;
	while (n--)
	{
		input();
		solution() ? cout << "YES\n" : cout << "NO\n";
		arr.clear();
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