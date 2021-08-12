#include <iostream>
#include <time.h>

using namespace std;

int main(void)
{
	time_t tnow = time(NULL);
	struct tm *t = localtime(&tnow);
	if (t->tm_mon + 1 < 10)
		cout << t->tm_year + 1900 << "-0" << t->tm_mon + 1 << '-' << t->tm_mday;
	else
		cout << t->tm_year + 1900 << '-' << t->tm_mon + 1 << '-' << t->tm_mday;
	return 0;
}