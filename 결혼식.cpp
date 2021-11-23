#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> classmate(501);
vector<int> check(501), mate(501);
int cnt = 0;

void inviteclassmate(int num)
{
	for (int j = 0; j < classmate[num].size(); j++)
	{
		if (!mate[classmate[num][j]] && !check[classmate[num][j]])
		{
			check[classmate[num][j]] = 1;
			cnt++;
		}
	}
}

int main(void)
{
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		classmate[a].push_back(b);
		classmate[b].push_back(a);
		if (a == 1)
			mate[b]++;
	}
	check[1] = 1;
	for (int i = 0; i < classmate[1].size(); i++)
	{
		if (!check[classmate[1][i]])
		{
			check[classmate[1][i]] = 1;
			inviteclassmate(classmate[1][i]);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}