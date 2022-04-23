#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string line;

	while (getline(cin, line))
	{
		if (line == "#")
			break;

		int ans = 0;

		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] == ' ')
				continue;

			ans += (line[i] - '@') * (i + 1);
		}

		cout << ans << '\n';
	}
	return 0;
}