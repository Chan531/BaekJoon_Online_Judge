#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int n, m, num1, num2;
	cin >> n >> m;
	vector<int> fline(n + 1), ans;
	vector<vector<int>> nline(n + 1);
	queue<int> q;
	while (m--)
	{
		cin >> num1 >> num2;
		fline[num2]++;
		nline[num1].push_back(num2);
	}
	for (int i = 1; i <= n; i++)
	{
		if (fline[i] == 0)
			q.push(i);
	}
	while (!q.empty())
	{
		int pos = q.front();
		q.pop();

		ans.push_back(pos);
		
		for (int i = 0; i < nline[pos].size(); i++)
		{
			int npos = nline[pos][i];
			fline[npos]--;

			if (fline[npos] == 0)
				q.push(npos);
		}
	}
	for (auto i : ans)
		cout << i << ' ';
	return 0;
}