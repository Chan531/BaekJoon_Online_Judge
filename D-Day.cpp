#include <iostream>
#include <vector>

using namespace std;

bool leap(int n)
{
	if (n % 4 == 0)
	{
		if (n % 400 == 0)
			return 1;
		else if (n % 100 == 0)
			return 0;
		else
			return 1;
	}
		return 0;
}

int main(void)
{
	vector<int> day = {0, 31, 28, 31,30,31,30,31,31,30,31,30,31 };
	vector<int> info;
	int y, m, d = 0;
	for (int i = 0; i < 2; i++)
	{
		cin >> y >> m >> d;
		info.push_back(y);
		info.push_back(m);
		info.push_back(d);
	}
	int dday = 0;
	
	if (info[3] - info[0] == 1000)
	{
		if (info[4] == info[1] && info[5] >= info[2])
		{
			cout << "gg";
			return 0;
		} 
		else if (info[4] > info[1])
		{
			cout << "gg";
			return 0;
		}
	}

	if (info[3] - info[0] > 1000)
	{
		cout << "gg";
		return 0;
	}

	if (info[0] == info[3])
	{
		if (info[1] != info[4])
		{
			for (int i = info[1] + 1; i < info[4]; i++)
			{
				if (!leap(info[0]))
					dday += day[i];
				else
				{
					if (i == 2)
						dday += 29;
					else
						dday += day[i];
				}
			}
			if (!leap(info[0]))
				dday += (day[info[1]] - info[2]);
			else
			{
				if (info[1] == 2)
					dday += (29 - info[2]);
				else
					dday += (day[info[1]] - info[2]);
			}
			dday += info[5];
		}
		else
			dday += info[5] - info[2];
		cout << "D-" << dday;
		return 0;
	}

	for (int i = info[0] + 1; i < info[3]; i++)
		leap(i) ? dday += 366 : dday += 365;

	for (int i = info[1] + 1; i <= 12; i++)
	{
		if (!leap(info[0]))
			dday += day[i];
		else
		{
			if (i == 2)
				dday += 29;
			else
				dday += day[i];
		}
	}

	for (int i = 1; i < info[4]; i++)
	{
		if (!leap(info[3]))
			dday += day[i];
		else
		{
			if (i == 2)
				dday += 29;
			else
				dday += day[i];
		}
	}

	if (!leap(info[0]))
		dday += (day[info[1]] - info[2]);

	else
	{
		if (info[1] == 2)
			dday += (29 - info[2]);
		else
			dday += (day[info[1]] - info[2]);
	}

	dday += info[5];

	if (dday >= 365243)
		cout << "gg";
	else
		cout << "D-" << dday;
	return 0;
}