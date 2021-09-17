#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num, cn, ci;
	stack<pair<int, int>> st;
	cin >> n;
	vector<int> v(n + 1), w(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		v[i] = num;
	}
	for (int i = n - 1; i > 0; i--)
	{
		cn = v[i + 1];
		ci = i + 1;
		if (v[i] > cn)
			w[ci] = i;
		else
			st.push(make_pair(cn, ci));

		if (!st.empty() && st.top().second != i + 1)
		{
			while (!st.empty() && v[i] > st.top().first)
			{
				w[st.top().second] = i;
				st.pop();
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << w[i] << ' ';
	return 0;
}