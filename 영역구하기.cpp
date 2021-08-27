#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ar;
vector<int> area;
vector<vector<int>> visited(101, vector<int> (101));

void rerec(vector<vector<int>> &v, int x1, int y1, int x2, int y2)
{
	for (int j = y1; j < y2; j++)
		for (int k = x1; k < x2; k++)
			v[j][k] = 1;                                    // ���簢���� ������ 1�� ����
	return;
}

void searcharea(vector<vector<int>> &v, int x, int y)
{
	if (x < 0 || x >= v[0].size() || y < 0 || y >= v.size() || v[y][x] == 1 || visited[y][x] == 1)               // ������ ������� �ٷ� return
		return;

	visited[y][x] = 1;
	ar++;

	searcharea(v, x, y - 1);
	searcharea(v, x + 1, y);
	searcharea(v, x, y + 1);
	searcharea(v, x - 1, y);
}

int main(void)
{
	int m, n, k, x1, x2, y1, y2;
	cin >> m >> n >> k;
	vector<vector<int>> v(m, vector<int>(n));               // ������ ���̰� m, ������ ���̰� n�� 0���� �ʱ�ȭ�� 2���� ���� ����
	for (int i = 0; i < k; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		rerec(v, x1, y1, x2, y2);
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ar = 0;
			searcharea(v, j, i);
			if (ar != 0)
				area.push_back(ar);
		}
	}
		
	sort(area.begin(), area.end());
	cout << area.size() << '\n';
	for (auto i : area)
		cout << i << ' ';
	return 0;
}