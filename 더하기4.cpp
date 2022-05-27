#include <iostream>
#include <string>
#include <numeric>

using namespace std;

int idx, arr[100];
string line;

void input()
{
	getline(cin, line);

	idx = 0;
	string num = "";
	for (int i = 0; i < line.length(); i++)
	{
		if (isdigit(line[i]))
			num += line[i];

		if (isspace(line[i]) || i == line.length() - 1)
		{
			arr[idx++] = stoi(num);
			num = "";
			continue;
		}
	}
}

void solution()
{
	cout << accumulate(arr, arr + idx, 0) << '\n';
}

void solve()
{
	int testcase;
	cin >> testcase;
	cin.ignore();

	while (testcase--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}