#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	int n, num, st = 0, count = -1;                       // -1으로 설정해줘서 +가 하나 더 계산되어도 정상 계산되게끔 함
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
			count += s.length() + 1;                     // 숫자랑 그 뒤에 붙는 곱하기까지 계산 
			if (st != 0)
			{
				count += st;                          // 곱하기 수 계산
				count += st;                          // x의 수 계산
			}
			st = 0;
		}
		else if (v[i] == 1)
		{
			count++;
			if (st != 0)
			{
				count += st + 1;                     // 곱하기 수 계산
				count += st + 1;                     // x의 수 계산
			}
			st = 0;
		}
		else if (i == v.size() - 1 && st != 0)
		{
			count += 2 * st;
		}
		else                                             // 0일 때
			st++;
		i++;
	}
	cout << count;
	return 0;
}