#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	string name, teamname, ans;
	int n, per, maxper = 0, lcnt = 0, ocnt = 0, vcnt = 0, ecnt = 0;
	cin >> name >> n;
	lcnt += count(name.begin(), name.end(), 'L');
	ocnt += count(name.begin(), name.end(), 'O');
	vcnt += count(name.begin(), name.end(), 'V');
	ecnt += count(name.begin(), name.end(), 'E');
	while (n--)
	{
		cin >> teamname;

		if (ans == "")
			ans = teamname;

		lcnt += count(teamname.begin(), teamname.end(), 'L');
		ocnt += count(teamname.begin(), teamname.end(), 'O');
		vcnt += count(teamname.begin(), teamname.end(), 'V');
		ecnt += count(teamname.begin(), teamname.end(), 'E');

		per = ((lcnt + ocnt) * (lcnt + vcnt) * (lcnt + ecnt) * (ocnt + vcnt) * (ocnt + ecnt) * (vcnt + ecnt)) % 100;

		if (maxper < per)
		{
			maxper = per;
			ans = teamname;
		}

		else if (maxper == per && ans > teamname)
			ans = teamname;

		lcnt -= count(teamname.begin(), teamname.end(), 'L');
		ocnt -= count(teamname.begin(), teamname.end(), 'O');
		vcnt -= count(teamname.begin(), teamname.end(), 'V');
		ecnt -= count(teamname.begin(), teamname.end(), 'E');
	}
	cout << ans;
}