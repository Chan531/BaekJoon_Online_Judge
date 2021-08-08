#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> card;

int bs(int n, int left, int right)
{
	int mid = (left + right) / 2;
	if (card[mid] == n)
		return 1;
	if (left >= right)
		return 0;
	if (card[mid] > n)
		return bs(n, left, mid - 1);
	if (card[mid] < n)
		return bs(n, mid + 1, right);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		card.push_back(num);
	}
	sort(card.begin(), card.end());
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		cout << bs(num, 0, n) << ' ';
	}
	return 0;
}