#include <iostream>
#include <queue>

using namespace std;

string a, b;
int stroke[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };

void input()
{
	cin >> a >> b;
}

void solution()
{
	queue<int> q;
	int l = a.length();
	int cnt = 0;
	
	for (int i = 0; i < l; i++)
	{
		q.push(stroke[a[i] - 'A']);
		q.push(stroke[b[i] - 'A']);
	}

	l *= 2;

	while (l != 2)
	{
		int a = q.front();
		q.pop();
		int b = q.front();

		q.push((a + b) % 10);
		cnt++;

		if (cnt == l - 1)
		{
			q.pop();
			cnt = 0;
			l--;
		}
	}

	cout << q.front();
	q.pop();
	cout << q.front();
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