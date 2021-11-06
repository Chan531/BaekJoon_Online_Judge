#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int num, a = 0, b = 0;
	vector<int> v;
	for (int i = 1; i <= 2; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> num;
			v.push_back(num);
			if (i > 1)
			{
				if (v[j] > v[j + 10])
					a++;
				else if (v[j] < v[j + 10])
					b++;
			}
		}
	}
	if (a > b)
		cout << 'A';
	else if (a < b)
		cout << 'B';
	else
		cout << 'D';
	return 0;
}