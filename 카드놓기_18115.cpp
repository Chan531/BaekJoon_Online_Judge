#include <iostream>
#include <deque>
#define N 1000000

using namespace std;

int n, com[N], arr[N];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> com[i];
}

void solution()
{
	deque<int> dq;
	int num = n;

	for (int i = 0; i < n; i++)
		dq.push_back(i);

	for (int i = 0; i < n; i++)
	{
		if (com[i] == 1)
		{
			int idx = dq.front();
			dq.pop_front();
			arr[idx] = num--;
		}

		else if (com[i] == 2)
		{
			int temp = dq.front();
			dq.pop_front();

			int idx = dq.front();
			dq.pop_front();
			arr[idx] = num--;

			dq.push_front(temp);
		}

		else
		{
			int idx = dq.back();
			dq.pop_back();
			arr[idx] = num--;
		}
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
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