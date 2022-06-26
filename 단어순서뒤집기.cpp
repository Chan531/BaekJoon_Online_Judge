#include <iostream>
#include <string>
#include <stack>

using namespace std;

string line;

void input()
{
	getline(cin, line);
}

void solution(int n)
{
	stack<string> st;
	string word = "";

	for (int i = 0; i < line.length(); i++)
	{
		if (isalpha(line[i]))
			word += line[i];

		if (line[i] == ' ' || i == line.length() - 1)
		{
			st.push(word);
			word = "";
		}
	}

	cout << "Case #" << n << ": ";

	while (!st.empty())
	{
		cout << st.top() << ' ';
		st.pop();
	}

	cout << '\n';
}

void solve()
{
	int testcase;
	cin >> testcase;
	cin.ignore();

	for (int i = 1; i <= testcase; i++)
	{
		input();
		solution(i);
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