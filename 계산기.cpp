#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	int n, num, st = 0, count = -1;                       // -1���� �������༭ +�� �ϳ� �� ���Ǿ ���� ���ǰԲ� ��
	vector<int> v;
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		cin >> num;
		v.push_back(num);
		if (num != 0)
			count++;
	}
	int i = 0;
	while (i != v.size())
	{
		if (i == v.size() - 1)
		{
			string s = to_string(v[i]);
			count += s.length() + 1;
			if (v[i] == 0)
				count--;
			if (st != 0)
				count += 2 * st;
			break;
		}
		if (v[i] > 1)
		{
			count++;
			string s = to_string(v[i]);
			count += s.length() + 1;                     // ���ڶ� �� �ڿ� �ٴ� ���ϱ���� ��� 
			if (st != 0)
			{
				count += st;                          // ���ϱ� �� ���
				count += st;                          // x�� �� ���
			}
			st = 0;
		}
		else if (v[i] == 1)
		{
			count++;
			if (st != 0)
			{
				count += st + 1;                     // ���ϱ� �� ���
				count += st + 1;                     // x�� �� ���
			}
			st = 0;
		}
		else if (i == v.size() - 1 && st != 0)
		{
			count += 2 * st;
		}
		else                                             // 0�� ��
			st++;
		i++;
	}
	cout << count;
	return 0;
}