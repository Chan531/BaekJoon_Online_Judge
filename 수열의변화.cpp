#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, k;
string str;
queue<int> q;

void input()
{
	cin >> n >> k >> str;
}

void solution()
{
	int idx = 0;
	string s = "";
	bool plus = 1;

	while (idx != str.length())
	{
		if (str[idx] == ',')
		{
			q.push(stoi(s));

			s = "";
			idx++;
			continue;
		}

		s += str[idx];
		idx++;
	}

	q.push(stoi(s));
	idx = 0;

	while (k--)
	{
		int size = q.size() - 1;

		while (size--)
		{
			int a = q.front();
			q.pop();

			int b = q.front();

			q.push(b - a);
		}

		q.pop();
	}

	int size = q.size();

	for (int i = 0; i < size; i++)
	{
		if (i == 0)
			cout << q.front();

		else
			cout << ',' << q.front();

		q.pop();
	}
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