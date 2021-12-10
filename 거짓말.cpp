#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> party(51, 1), check(51);
vector<vector<int>> member(51), participation(51);

int main(void)
{
	int n, m, k, num, partynum, partymem, ans = 0;
	queue<int> checkliar;
	cin >> n >> m >> k;
	while (k--)
	{
		cin >> num;
		checkliar.push(num);
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> k;
		party[i] = 1;
		while (k--)
		{
			cin >> num;
			member[i].push_back(num);
			participation[num].push_back(i);
		}
	}
	while (!checkliar.empty())
	{
		num = checkliar.front();
		checkliar.pop();

		check[num] = 1;

		for (int i = 0; i < participation[num].size(); i++)
		{
			partynum = participation[num][i];
			party[partynum] = 0;
			for (int j = 0; j < member[partynum].size(); j++)
			{
				if (!check[member[partynum][j]])
				{
					partymem = member[partynum][j];
					checkliar.push(partymem);
				}
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		if (party[i])
			ans++;
	}
	cout << ans;
	return 0;
}