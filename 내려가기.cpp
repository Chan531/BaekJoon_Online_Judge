#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num1, num2, num3;
	cin >> n;
	vector<vector<pair<int, int>>> v(2, vector<pair<int, int>>(3));
	cin >> num1 >> num2 >> num3;
	v[0][0] = { num1, num1 };
	v[0][1] = { num2, num2 };
	v[0][2] = { num3, num3 };
	for (int i = 1; i < n; i++)
	{
		cin >> num1 >> num2 >> num3;
		v[i % 2][0] = { num1, num1 };
		v[i % 2][1] = { num2, num2 };
		v[i % 2][2] = { num3, num3 };

		v[i % 2][0].first += max(v[(i - 1) % 2][0].first, v[(i - 1) % 2][1].first);
		v[i % 2][0].second += min(v[(i - 1) % 2][0].second, v[(i - 1) % 2][1].second);

		v[i % 2][1].first += max({ v[(i - 1) % 2][0].first, v[(i - 1) % 2][1].first, v[(i - 1) % 2][2].first });
		v[i % 2][1].second += min({ v[(i - 1) % 2][0].second, v[(i - 1) % 2][1].second, v[(i - 1) % 2][2].second });

		v[i % 2][2].first += max(v[(i - 1) % 2][1].first, v[(i - 1) % 2][2].first);
		v[i % 2][2].second += min(v[(i - 1) % 2][1].second, v[(i - 1) % 2][2].second);
	}
	if (n % 2)
		cout << max({ v[0][0].first, v[0][1].first, v[0][2].first }) << ' ' << min({ v[0][0].second, v[0][1].second, v[0][2].second });
	else
		cout << max({ v[1][0].first, v[1][1].first, v[1][2].first }) << ' ' << min({ v[1][0].second, v[1][1].second, v[1][2].second });
	return 0;
}