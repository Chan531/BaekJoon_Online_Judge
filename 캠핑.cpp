#include <iostream>

using namespace std;

int main(void)
{
	int l, p, v, answer;
	for (int i = 1; ; i++)
	{
		answer = 0;
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0)
			break;
		answer += v / p * l;
		if (v % p > l)
			answer += l;
		else
			answer += v % p;
		cout << "Case " << i << ": " << answer<< '\n';
	}
	return 0;
}