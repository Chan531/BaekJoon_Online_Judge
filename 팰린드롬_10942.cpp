#include <iostream>
#include <vector>

using namespace std;
vector<int> arr;
vector<vector<int>> palindrome(2000, vector<int>(2000));

int pd(int a, int b)
{
	if (a == b)
		return 1;
	if (arr[a] == arr[b])
	{
		if (a == b - 1)
			return 1;
		else
			return palindrome[a + 1][b - 1];
	}
	return 0;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	int n, num, m, a, b, idx;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
	cin >> m;
	for (int i = n; i > 0; i--)
	{
		idx = n - i;
		for (int j = 0; j < i; j++)
		{
			palindrome[j][idx] = pd(j, idx);
			idx++;
		}
	}
	while (m--)
	{
		cin >> a >> b;
		cout << palindrome[a - 1][b - 1] << '\n';
	}
	return 0;
}