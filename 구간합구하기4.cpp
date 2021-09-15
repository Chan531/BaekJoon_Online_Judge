#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, num, num1, sum = 0;
	cin >> n >> m;
	vector<int> v, w(1);
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		sum += num;
		v.push_back(num);
		w.push_back(sum);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> num >> num1;
		cout << w[num1] - w[num - 1] << '\n';
	}
	return 0;
}