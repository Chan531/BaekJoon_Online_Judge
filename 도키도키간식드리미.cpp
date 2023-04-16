#include <iostream>
#include <stack>
#define N 1000

using namespace std;

int n, arr[N];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	stack<int> st;
	int tar = 1;

	for (int i = 0; i < n; i++)
	{
		while (!st.empty() && st.top() == tar)
		{
			st.pop();
			tar++;
		}

		if (!st.empty() && st.top() < arr[i])
		{
			cout << "Sad";
			return;
		}

		if (arr[i] == tar)
		{
			tar++;
			continue;
		}

		st.push(arr[i]);
	}
	
	while (!st.empty() && st.top() == tar)
	{
		st.pop();
		tar++;
	}

	tar == n + 1 ? cout << "Nice" : cout << "Sad";
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