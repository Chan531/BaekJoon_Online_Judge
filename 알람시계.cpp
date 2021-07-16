#include <iostream>

using namespace std;

int main(void)
{
	int h, m, time, alarm, hour, minute;
	cin >> h >> m;
	time = h * 60 + m;

	if (time - 45 < 0)
		alarm = 1440 + (time - 45);

	else
		alarm = time - 45;

	hour = alarm / 60;
	minute = alarm - hour * 60;
	cout << hour << ' ' << minute;
	return 0;
}