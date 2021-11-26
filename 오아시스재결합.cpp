#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	int n, num, cnt;
	long long ans = 0;
	stack<pair<int, int>> st;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (st.empty())
		{
			st.push(make_pair(num, 1));
			continue;
		}
		if (st.top().first < num)
		{
			while (!st.empty() && st.top().first < num)
			{
				ans += st.top().second;
				st.pop();
			}
			if (!st.empty() && st.top().first == num)
			{
				cnt = st.top().second;
				ans += cnt;
				st.pop();
				if (!st.empty())
					ans++;
				st.push(make_pair(num, cnt + 1));
			}
			else if (!st.empty())
			{
				ans++;
				st.push(make_pair(num, 1));
			}
			else
			{
				st.push(make_pair(num, 1));
			}
		}
		else if (st.top().first > num)
		{
			st.push(make_pair(num, 1));
			ans++;
		}
		else
		{
			cnt = st.top().second;
			ans += cnt;
			st.pop();
			if (!st.empty())
				ans++;
			st.push(make_pair(num, cnt + 1));
		}
	}
	cout << ans;
	return 0;
}