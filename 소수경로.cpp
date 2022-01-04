#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> primenum(10000), visited(10000);
queue<pair<int, int>> changepw;

void makeprimenum()
{
	primenum[1] = 1;
	for (int i = 2; i < 10000; i++)
	{
		if (!primenum[i])
		{
			for (int j = i * 2; j < 10000; j += i)
				primenum[j] = 1;
		}
	}
}

int solve(int a, int b)
{
	changepw.push({ a,0 });
	visited[a] = 1;

	while (!changepw.empty())
	{
		int num = changepw.front().first;
		int cnt = changepw.front().second;
		changepw.pop();

		if (num == b)
			return cnt;

		for (int i = 1000; i <= 9000; i += 1000)
		{
			int nextnum = i + num % 1000;
			if (!primenum[nextnum] && !visited[nextnum])
			{
				visited[nextnum] = 1;
				changepw.push({ nextnum,cnt + 1 });
			}
		}

		for (int i = 0; i <= 900; i += 100)
		{
			int nextnum = num / 1000 * 1000 + i + num % 100;
			if (!primenum[nextnum] && !visited[nextnum])
			{
				visited[nextnum] = 1;
				changepw.push({ nextnum,cnt + 1 });
			}
		}

		for (int i = 0; i <= 90; i += 10)
		{
			int nextnum = num / 100 * 100 + i + num % 10;
			if (!primenum[nextnum] && !visited[nextnum])
			{
				visited[nextnum] = 1;
				changepw.push({ nextnum,cnt + 1 });
			}
		}

		for (int i = 0; i <= 9; i++)
		{
			int nextnum = num / 10 * 10 + i;
			if (!primenum[nextnum] && !visited[nextnum])
			{
				visited[nextnum] = 1;
				changepw.push({ nextnum,cnt + 1 });
			}
		}
	}

	return -1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase, a, b, result;
	makeprimenum();
	cin >> testcase;
	while (testcase--)
	{
		cin >> a >> b;
		result = solve(a, b);
		result >= 0 ? cout << result << '\n' : cout << "Impossible\n";
		fill(visited.begin(), visited.end(), 0);
		while (!changepw.empty())
			changepw.pop();
	}
	return 0;
}