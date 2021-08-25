#include <iostream>
#include <string>

using namespace std;

void outtime(int n)
{
	if (n == 0)
		cout << "00";
	else if (n < 10)
		cout << '0' << n;
	else
		cout << n;
	return;
}

void checktime(int bh, int bm, int bs, int sh, int sm, int ss)
{
	if (bs < ss)
	{
		bm--;
		bs += 60;
	}
	if (bm < sm)
	{
		bh--;
		bm += 60;
	}
	int ah = bh - sh;
	int am = bm - sm;
	int as = bs - ss;

	outtime(ah);
	cout << ':';
	outtime(am);
	cout << ':';
	outtime(as);
	return;
}

int main(void)
{
	string str1, str2;
	int h1, m1, s1, h2, m2, s2, t1, t2;
	cin >> str1 >> str2;
	h1 = stoi(str1.substr(0, 2));
	m1 = stoi(str1.substr(3, 2));
	s1 = stoi(str1.substr(6, 2));
	h2 = stoi(str2.substr(0, 2));
	m2 = stoi(str2.substr(3, 2));
	s2 = stoi(str2.substr(6, 2));
	t1 = 3600 * h1 + 60 * m1 + s1;
	t2 = 3600 * h2 + 60 * m2 + s2;

	if (t1 > t2)
		h2 += 24;

	checktime(h2, m2, s2, h1, m1, s1);

	return 0;
}