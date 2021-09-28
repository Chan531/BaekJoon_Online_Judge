#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, num, count = 0;
	cin >> n >> m;
	vector<int> v, w(m + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = v[i]; j <= m; j += v[i])
		{
			if (!w[j])
			{
				w[j] = 1;
				count++;
			}
		}
	}
	cout << count;
	return 0;
}