#include <iostream>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	for (int j = 0; j < t; j++)
	{
		int hp = 0, mp = 0, str = 0, def = 0, n;
		for (int i = 0; i < 8; i++)
		{
			if (i % 4 == 0)
			{
				cin >> n;
				hp += n;
			}
			else if (i % 4 == 1)
			{
				cin >> n;
				mp += n;
			}
			else if (i % 4 == 2)
			{
				cin >> n;
				str += n;
			}
			else
			{
				cin >> n;
				def += n;
			}
		}
		if (str < 0)
			str = 0;
		if (hp < 1)
			hp = 1;
		if (mp < 1)
			mp = 1;
		cout << hp + 5 * mp + 2 * (str + def) << '\n';
	}
	return 0;
}