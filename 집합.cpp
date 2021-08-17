#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	vector<int> col(21);
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;

		if (s == "add")
		{
			cin >> num;
			col[num] = 1;
		}

		else if (s == "remove")
		{
			cin >> num;
			col[num] = 0;
		}

		else if (s == "check")
		{
			cin >> num;
			cout << col[num] << '\n';
		}

		else if (s == "toggle")
		{
			cin >> num;
			if (col[num] == 0)
				col[num] = 1;
			else
				col[num] = 0;
		}

		else if (s == "all")
			replace(col.begin(), col.end(), 0, 1);

		else
			replace(col.begin(), col.end(), 1, 0);
	}
	return 0;
}