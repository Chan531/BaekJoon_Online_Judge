#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, x, y, axis = 0;
	vector<int> q(5);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		if (x == 0 || y == 0)
			axis++;
		else if (x > 0 && y > 0)
			q[1]++;
		else if (x < 0 && y > 0)
			q[2]++;
		else if (x < 0 && y < 0)
			q[3]++;
		else
			q[4]++;
	}
	for (int i = 1; i <= 4; i++)
	{
		cout << 'Q' << i << ": " << q[i] << '\n';
	}
	cout << "AXIS: " << axis;
	return 0;
}