#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int n, x1, x2, y1, y2, m, cx, cy, r, point;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2 >> m;
		point = 0;
		for (int j = 0; j < m; j++)
		{
			cin >> cx >> cy >> r;
			int dis1 = pow(x1 - cx, 2) + pow(y1 - cy, 2);
			int dis2 = pow(x2 - cx, 2) + pow(y2 - cy, 2);
			int pr = pow(r, 2);
			if (dis1 < pr && dis2 > pr || dis1 > pr && dis2 < pr)
				point++;
		}
		cout << point << '\n';
	}
	return 0;
}