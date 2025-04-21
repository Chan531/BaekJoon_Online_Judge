#include <iostream>
#include <string>

using namespace std;

string a, b;
int h1, m1, s1, h2, m2, s2, h3, m3, s3;

void input()
{
	cin >> a >> b;
}

void solution()
{
	h1 = (a[0] - '0') * 10 + a[1] - '0';
	m1 = (a[3] - '0') * 10 + a[4] - '0';
	s1 = (a[6] - '0') * 10 + a[7] - '0';

	h2 = (b[0] - '0') * 10 + b[1] - '0';
	m2 = (b[3] - '0') * 10 + b[4] - '0';
	s2 = (b[6] - '0') * 10 + b[7] - '0';

	if (s1 > s2)
	{
		s3 = 60 - s1;
		s1 = 0;
		m1++;
	}

	s3 += s2 - s1;

	if (m1 > m2)
	{
		m3 = 60 - m1;
		m1 = 0;
		h1++;
	}

	m3 += m2 - m1;

	if (h1 > h2)
	{
		h3 = 24 - h1;
		h1 = 0;
	}

	h3 += h2 - h1;

	if (h3 == 0 && m3 == 0 && s3 == 0)
	{
		cout << "24:00:00";
		return;
	}

	if (h3 < 10) cout << 0;
	cout << h3;
	cout << ":";
	if (m3 < 10) cout << 0;
	cout << m3;
	cout << ":";
	if (s3 < 10) cout << 0;
	cout << s3;
}

void solve()
{
	input();
	solution();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}