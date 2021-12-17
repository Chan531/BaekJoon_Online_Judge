#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> check(51);
vector<vector<int>> mate(51, vector<int>(51));
int n, ans, rans = 0;

int checkmate(int st, int m)
{
	int cnt = 1;
	for (int k = 1; k <= n; k++)
	{
		if (!check[k] && mate[m][k])
		{
			if (!mate[st][k])
			{
				check[k] = 1;
				cnt++;
			}
		}
	}
	return cnt;
}

int main(void)
{
	string yn;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> yn;
		for (int j = 1; j <= n; j++)
		{
			if (yn[j - 1] == 'Y')
				mate[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		check[i] = 1;
		ans = 0;
		for (int j = 1; j <= n; j++)
		{
			if (mate[i][j] && !check[j])
			{
				check[j] = 1;
				ans += checkmate(i, j);
			}
		}
		rans = max(ans, rans);
		fill(check.begin(), check.end(), 0);
	}
	cout << rans;
	return 0;
}