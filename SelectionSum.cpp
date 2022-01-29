#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num, m, a, b;
	vector<int> arr(100001);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		arr[i] = num + arr[i - 1];
	}
	cin >> m;
	while (m--)
	{
		cin >> a >> b;
		cout << arr[b + 1] - arr[a] << '\n';
	}
	return 0;
}