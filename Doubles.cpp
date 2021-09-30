#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num, count;
	while (1)
	{
		vector<int> v;
		count = 0;
		while (1)
		{
			cin >> num;
			if (num == 0 || num == -1)
				break;
			v.push_back(num);
		}
		if (num == -1)
			break;
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < v.size(); j++)
			{
				if (v[i] == v[j] * 2)
					count++;
			}
		}
		cout << count << '\n';
	}
	return 0;
}