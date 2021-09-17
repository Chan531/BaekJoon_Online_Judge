#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, m, num;
	vector<vector<int>> v, w;
	for (int k = 0; k < 2; k++)
	{
		cin >> n >> m;
		if (k)
		{
			for (int i = 0; i < n; i++)
			{
				vector<int> line;
				for (int j = 0; j < m; j++)
				{
					cin >> num;
					line.push_back(num);
				}
				v.push_back(line);
			}
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				vector<int> line;
				for (int j = 0; j < m; j++)
				{
					cin >> num;
					line.push_back(num);
				}
				w.push_back(line);
			}
		}
	}
	vector<vector<int>> x(w.size(), vector<int>(m));
	for (int i = 0; i < m; i++)
	{
		for (int k = 0; k < w.size(); k++)
		{
			num = 0;
			for (int j = 0; j < n; j++)
				num += w[k][j] * v[j][i];
			x[k][i] = num;
		}
	}
	for (int i = 0; i < w.size(); i++)
	{
		for (int j = 0; j < m; j++)
			cout << x[i][j]<< ' ';
		cout << '\n';
	}
	return 0;
}