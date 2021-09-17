#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, a, b;
	vector<int> v = { 0,1,0,0 };
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (v[a])
		{
			v[a]--;
			v[b]++;
		}
		else if (v[b])
		{
			v[b]--;
			v[a]++;
		}
	}
	for (int i = 1; i <= 3; i++)
	{
		if (v[i])
			cout << i;
	}
	return 0;
}