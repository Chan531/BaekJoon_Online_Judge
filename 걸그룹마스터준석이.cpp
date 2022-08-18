#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m, k;
string name, mem, group[100];
unordered_map<string, int> girl;
vector<string> member[100];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> name >> k;

		group[i] = name;

		while (k--)
		{
			cin >> mem;
			member[i].push_back(mem);
			girl[mem] = i;
		}
	}
}

void solution()
{
	for (int i = 0; i < n; i++)
		sort(member[i].begin(), member[i].end());

	while (m--)
	{
		cin >> name >> k;

		int idx;

		if (k)
		{	
			idx = girl[name];
			cout << group[idx] << '\n';
			continue;
		}
	
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (group[i] == name)
				{
					idx = i;
					break;
				}
			}
					
			for (int i = 0; i < member[idx].size(); i++)
				cout << member[idx][i] << '\n';
		}
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
	cout.tie(NULL);

	solve();
	return 0;
}