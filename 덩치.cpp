#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, x, y;
	vector<int> w, h;
	string s = "";
	cin >> n;
	vector<vector<int>> table;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		w.push_back(x);
		h.push_back(y);
	}
	for (int i = 0; i < n; i++)
	{
		vector<int> line;                        // 0 -> 자기자신, 1 -> 우열 가릴 수 x, 2 -> 얘는 확실히 이김, -1 -> 완패
		for (int j = 0; j < n; j++)
		{
			if (i == 0 && j == 0)
				line.push_back(0);
			else if (w[i] > w[j] && h[i] > h[j])
				line.push_back(2);
			else if (w[i] < w[j] && h[i] < h[j])
				line.push_back(-1);
			else
				line.push_back(1);
		}
		table.push_back(line);
	}
	for (int i = 0; i < n; i++)
	{
		s += to_string(count(table[i].begin(), table[i].end(), -1) + 1);
		s += ' ';
	}
	cout << s;
	return 0;
}