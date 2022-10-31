#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans;
string com[100000];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> com[i];

}

void solution()
{
	int idx = 0;
	string cur;
	vector<string> name;

	while (idx++ < n)
	{
		while (idx < n && com[idx] != "ENTER")
		{
			name.push_back(com[idx++]);
		}

		sort(name.begin(), name.end());

		for (int i = 0; i < name.size(); i++)
		{
			if (i == 0 || cur != name[i])
			{
				cur = name[i];
				ans++;
			}
		}

		name.clear();
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