#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num, cnt = 0;
	vector<int> v(1000001);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v[num]++;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (v[num])
			v[num]--;
		else
			cnt++;
	}
	cout << cnt;
	return 0;
}