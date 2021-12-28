#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int x1, x2, y1, y2, ans = 0;
	vector<vector<int>> plane(101, vector<int>(101));
	for (int i = 0; i < 4; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = y1; j < y2; j++)
		{
			for (int k = x1; k < x2; k++)
			{
				if (!plane[j][k])
				{
					plane[j][k] = 1;
					ans++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}