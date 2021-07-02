#include <iostream>
#include <vector>

using namespace std;

int main()
{
	double n;
	cin >> n;
	vector<int> v;
	if (n == 1)
		cout << 1;
	else
	{
		v.push_back(1);
		int i = 1;
		while (1)
		{
			v.push_back(v[i - 1] + 6 * i);
			if (n > v[i - 1] && n <= v[i])
			{
				cout << i + 1;
				break;
			}
			i++;
		}
	}
}