#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	stack<pair<int, int>> s;
	cin >> n;
	vector<pair<int, int>> v;
	vector<int> w(n + 1, -1);
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		v.push_back(make_pair(num, i));
	}
	int i = 0;
	while (i != v.size())
	{
		if (s.empty() || s.top().first >= v[i].first)
			s.push(make_pair(v[i].first, v[i].second));
		else
		{
			w[s.top().second] = v[i].first;
			s.pop();
			i--;
		}
		i++;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << w[i] << ' ';
	}
	return 0;
}