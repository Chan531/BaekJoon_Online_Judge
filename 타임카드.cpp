#include <iostream>

using namespace std;

int main(void)
{
	int gwh, gwm, gws, lwh, lwm, lws;
	for (int i = 0; i < 3; i++)
	{
		cin >> gwh >> gwm >> gws >> lwh >> lwm >> lws;
		lwh -= gwh;
		lwm -= gwm;
		lws -= gws;
		if (lws < 0)
		{
			lws += 60;
			lwm--;
		}
		if (lwm < 0)
		{
			lwm += 60;
			lwh--;
		}
		cout << lwh << ' ' << lwm << ' ' << lws << '\n';
	}
	return 0;
}