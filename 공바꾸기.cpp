#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	int n, m, a, b;
	map<int, int> ball;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		ball[i] = i;
	while (m--)
	{
		cin >> a >> b;
		swap(ball[a], ball[b]);
	}
	for (int i = 1; i <= n; i++)
		cout << ball[i] << ' ';
	return 0;
}