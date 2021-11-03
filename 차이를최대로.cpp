#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num, ma = 0, ans;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	do
	{
		ans = 0;
		for (int i = 0; i < n - 1; i++)
			ans += abs(v[i] - v[i + 1]);
		if (ma < ans)
			ma = ans;
	} while (next_permutation(v.begin(), v.end()));
	cout << ma;
	return 0;
}