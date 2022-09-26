#include <iostream>
#include <stack>

using namespace std;

int idx = 1;
string line;

void input()
{
	cin >> line;
}

void solution()
{
	if (line == "0")
		exit(0);

	// 양 끝이 1과 2이어야 함
	if ((line[0] != '1') || line[line.length() - 1] != '2')
	{
		cout << idx++ << ". NOT\n";
		return;
	}

	stack<char> st;
	st.push(line[0]);

	for (int i = 1; i < line.length(); i++)
	{
		// 1번이 두 번 등장하면 x
		if (line[i] == '1') 
		{
			cout << idx++ << ". NOT\n";
			return;
		}

		// 2번이 끝쪽에 말고 등장하면 x
		else if (line[i] == '2' && i != line.length() - 1)
		{
			cout << idx++ << ". NOT\n";
			return;
		}

		// 2번, 3번 앞에는 4번, 6번이 와야함
		else if (line[i] == '2' || line[i] == '3')
		{
			if (st.top() != '4' && st.top() != '6')
			{
				cout << idx++ << ". NOT\n";
				return;
			}
		}

		// 4번, 5번 앞에는 1번, 3번이 와야함
		else if (line[i] == '4' || line[i] == '5')
		{
			if (st.top() != '1' && st.top() != '3')
			{
				cout << idx++ << ". NOT\n";
				return;
			}
		}

		// 6번, 7번 앞에는 8번이 와야함
		else if (line[i] == '6' || line[i] == '7')
		{
			if (st.top() != '8')
			{
				cout << idx++ << ". NOT\n";
				return;
			}
		}

		// 8번 앞에는 5번, 7번이 와야함
		else if (line[i] == '8')
		{
			if (st.top() != '5' && st.top() != '7')
			{
				cout << idx++ << ". NOT\n";
				return;
			}
		}

		st.push(line[i]);
	}

	cout << idx++ << ". VALID\n";
}

void solve()
{
	while (1)
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