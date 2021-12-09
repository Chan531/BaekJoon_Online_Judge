#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string sa, sb, fa, fb;
	int maxa, mina, maxb, minb;
	cin >> sa >> sb;
	fa = sa;
	fb = sb;
	for (int i = 0; i < sa.length(); i++)
	{
		if (sa[i] == '5')
			sa[i] = '6';
		if (fa[i] == '6')
			fa[i] = '5';
	}
	for (int i = 0; i < sb.length(); i++)
	{
		if (sb[i] == '5')
			sb[i] = '6';
		if (fb[i] == '6')
			fb[i] = '5';
	}
	cout << stoi(fa) + stoi(fb) << ' ' << stoi(sa) + stoi(sb);
	return 0;
}