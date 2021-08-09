#include <iostream>
#include <vector>

using namespace std;

int check[1001];
vector<int> v[1001];
int c = 0;

void dfs(int n)
{
	if (check[n] == 1)
		return;
	else
		check[n] = 1;
	for (int k = 0; k < v[n].size(); k++)
	{
		dfs(v[n][k]);
	}
	return;
}

int main(void)
{
	int n, m, num1, num2;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> num1 >> num2;
		v[num1].push_back(num2);
		v[num2].push_back(num1);
	}
	for (int i = 1; i <= n; i++)
	{
		if (check[i] != 1)
		{
			dfs(i);
			c++;
		}
	}
	cout << c;
	return 0;
}