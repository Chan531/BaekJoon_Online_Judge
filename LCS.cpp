#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	string s, p;
	cin >> s >> p;
	int sl = s.length(), pl = p.length();
	vector<vector<int>> v(sl, vector<int>(pl));
	for (int i = 0; i < sl; i++)
	{
		if (!i)
		{
			if (s[i] == p[0])
				v[i][0] = 1;
			else
				v[i][0] = 0;
			for (int j = 1; j < pl; j++)
			{
				if (s[i] == p[j])
					v[i][j] = 1;
				else
					v[i][j] = v[i][j - 1];
			}
			continue;
		}
		for (int j = 0; j < pl; j++)
		{
			if (!j)
			{
				if (s[i] == p[j])
					v[i][j] = 1;
				else
					v[i][j] = v[i - 1][j];
				continue;
			}
			if (s[i] == p[j])                                  // 똑같은 글자가 s와 p에 추가 된 상태이므로 v[i - 1][j - 1] + 1
				v[i][j] = v[i - 1][j - 1] + 1;
			else
				v[i][j] = max(v[i][j - 1], v[i - 1][j]);       // 글자가 다르므로 새로운 글자가 추가된 문자열과 아닌 문자열을 서로 비교
		}
	}
	cout << v[sl - 1][pl - 1];
	return 0;
}