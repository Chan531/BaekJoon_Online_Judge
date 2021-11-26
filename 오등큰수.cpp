#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
	int n, num;
	vector<int> ngf(1000001), arr(1000001), ans(1000001, -1);
	stack<pair<int, int>> st;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		ngf[num]++;
		arr[i] = num;
	}
	for (int i = n; i > 0; i--)
	{
		if (st.empty())
		{
			st.push({ arr[i], i });
			continue;
		}
		if (ngf[st.top().first] > ngf[arr[i]])
		{
			ans[i] = st.top().first;
			st.push({ arr[i],i });
		}
		else
		{
			while (!st.empty() && ngf[st.top().first] <= ngf[arr[i]])
				st.pop();
			if (!st.empty())
				ans[i] = st.top().first;
			st.push({ arr[i],i });
		}
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	return 0;
}