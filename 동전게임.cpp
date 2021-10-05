#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n, ttt, tth, tht, thh, htt, hth, hht, hhh;
	string s, t;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ttt = 0, tth = 0, tht = 0, thh = 0, htt = 0, hth = 0, hht = 0, hhh = 0;
		cin >> s;
		for (int j = 0; j < 38; j++)
		{
			t = s.substr(j, 3);
			if (t == "TTT")
				ttt++;
			else if (t == "TTH")
				tth++;
			else if (t == "THT")
				tht++;
			else if (t == "THH")
				thh++;
			else if (t == "HTT")
				htt++;
			else if (t == "HTH")
				hth++;
			else if (t == "HHT")
				hht++;
			else
				hhh++;
		}
		cout << ttt << ' ' << tth << ' ' << tht << ' ' << thh << ' ' << htt << ' ' << hth << ' ' << hht << ' ' << hhh << '\n';
	}
	return 0;
}