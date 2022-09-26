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

	// �� ���� 1�� 2�̾�� ��
	if ((line[0] != '1') || line[line.length() - 1] != '2')
	{
		cout << idx++ << ". NOT\n";
		return;
	}

	stack<char> st;
	st.push(line[0]);

	for (int i = 1; i < line.length(); i++)
	{
		// 1���� �� �� �����ϸ� x
		if (line[i] == '1') 
		{
			cout << idx++ << ". NOT\n";
			return;
		}

		// 2���� ���ʿ� ���� �����ϸ� x
		else if (line[i] == '2' && i != line.length() - 1)
		{
			cout << idx++ << ". NOT\n";
			return;
		}

		// 2��, 3�� �տ��� 4��, 6���� �;���
		else if (line[i] == '2' || line[i] == '3')
		{
			if (st.top() != '4' && st.top() != '6')
			{
				cout << idx++ << ". NOT\n";
				return;
			}
		}

		// 4��, 5�� �տ��� 1��, 3���� �;���
		else if (line[i] == '4' || line[i] == '5')
		{
			if (st.top() != '1' && st.top() != '3')
			{
				cout << idx++ << ". NOT\n";
				return;
			}
		}

		// 6��, 7�� �տ��� 8���� �;���
		else if (line[i] == '6' || line[i] == '7')
		{
			if (st.top() != '8')
			{
				cout << idx++ << ". NOT\n";
				return;
			}
		}

		// 8�� �տ��� 5��, 7���� �;���
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