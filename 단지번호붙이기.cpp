#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<char>> map;
vector<int> apart;
int label = 1;

void investigate(int x, int y, int label)
{
	if (x < 0 || y < 0 || x >= map[0].size() || y >= map.size())
		return;

	if (map[x][y] == 48 || map[x][y] == '.') return;

	else
	{
		map[x][y] = '.';
		apart[label - 1]++;
		investigate(x - 1, y, label);
		investigate(x, y - 1, label);
		investigate(x + 1, y, label);
		investigate(x, y + 1, label);
	}
}

void search(int x, int y)
{
	for (int a = 0; a < y; a++)
	{
		for (int b = 0; b < x; b++)
		{
			if (map[a][b] == 49)
			{
				apart.push_back(0);
				investigate(a, b, label++);
			}
		}
	}
}

int main(void)
{
	int n = 0;
	cin >> n;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		vector<char> num;
		string s = "";
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			num.push_back(s[j]);
		}
		map.push_back(num);
	}
	search(n, n);
	sort(apart.begin(), apart.end());
	cout << label - 1 << '\n';
	for (auto i : apart)
	{
		cout << i << '\n';
	}
}