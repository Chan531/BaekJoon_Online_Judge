#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, num, stu, sex;
	vector<int> v;
	v.push_back(-1);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	cin >> stu;
	for (int i = 0; i < stu; i++)
	{
		cin >> sex >> num;
		if (sex == 1)
		{
			for (int j = num; j <= n; j += num)
				v[j] ^= 1 << 0;
		}
		else
		{
			v[num] ^= 1 << 0;
			int left = num - 1;
			int right = num + 1;
			while (left != 0 && right != n + 1 && v[left] == v[right])
			{
				v[left] ^= 1 << 0;
				v[right] ^= 1 << 0;
				left--;
				right++;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << v[i] << ' ';
		if (i % 20 == 0)
			cout << '\n';
	}
	return 0;
}