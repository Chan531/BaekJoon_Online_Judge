#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int k, n, arr[50];
string num[50];

void input()
{
	cin >> k >> n;
	for (int i = 0; i < k; i++)
		cin >> arr[i];
}

bool cmp(string a, string b)
{
	return a + b > b + a;
}

void solution()
{
	sort(arr, arr + k);

	while (k != n)
	{
		arr[k] = arr[k - 1];
		k++;
	}

	for (int i = 0; i < k; i++)
		num[i] = to_string(arr[i]);

	sort(num, num + n, cmp);

	for (int i = 0; i < n; i++)
		cout << num[i];
}

void solve()
{
	input();
	solution();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}