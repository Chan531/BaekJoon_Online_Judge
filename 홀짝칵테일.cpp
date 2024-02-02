#include <iostream>

using namespace std;

int a, b, c, ans;

void input()
{
	cin >> a >> b >> c;
}

void solution()
{
	if (ans % 2 == 0 && a % 2)
		ans = a;

	else if (ans % 2 && a % 2 && ans < a)
		ans = a;

	if (ans % 2 == 0 && b % 2)
		ans = b;

	else if (ans % 2 && b % 2 && ans < b)
		ans = b;

	if (ans % 2 == 0 && c % 2)
		ans = c;

	else if (ans % 2 && c % 2 && ans < c)
		ans = c;

	// ans°¡ Â¦¼öÀÌ°í °öÀÌ È¦¼ö¶ó¸é ¹«Á¶°Ç change
	if (ans % 2 == 0 && a * b % 2)
		ans = a * b;

	// ans¿Í °öÀÌ ¸ðµÎ È¦¼öÀÎµ¥ °öÀÌ ´õ Å©´Ù¸é change
	else if (ans % 2 && a * b % 2 && ans < a * b)
		ans = a * b;

	// ans¿Í °öÀÌ ¸ðµÎ Â¦¼öÀÎµ¥ °öÀÌ ´õ Å©´Ù¸é change
	else if (ans % 2 == 0 && a * b % 2 == 0 && ans < a * b)
		ans = a * b;

	// ans°¡ Â¦¼öÀÌ°í °öÀÌ È¦¼ö¶ó¸é ¹«Á¶°Ç change
	if (ans % 2 == 0 && b * c % 2)
		ans = b * c;

	// ans¿Í °öÀÌ ¸ðµÎ È¦¼öÀÎµ¥ °öÀÌ ´õ Å©´Ù¸é change
	else if (ans % 2 && b * c % 2 && ans < b * c)
		ans = b * c;

	// ans¿Í °öÀÌ ¸ðµÎ Â¦¼öÀÎµ¥ °öÀÌ ´õ Å©´Ù¸é change
	else if (ans % 2 == 0 && b * c % 2 == 0 && ans < b * c)
		ans = b * c;

	// ans°¡ Â¦¼öÀÌ°í °öÀÌ È¦¼ö¶ó¸é ¹«Á¶°Ç change
	if (ans % 2 == 0 && a * c % 2)
		ans = a * c;

	// ans¿Í °öÀÌ ¸ðµÎ È¦¼öÀÎµ¥ °öÀÌ ´õ Å©´Ù¸é change
	else if (ans % 2 && a * c % 2 && ans < a * c)
		ans = a * c;

	// ans¿Í °öÀÌ ¸ðµÎ Â¦¼öÀÎµ¥ °öÀÌ ´õ Å©´Ù¸é change
	else if (ans % 2 == 0 && a * b * c % 2 == 0 && ans < a * b * c)
		ans = a * c;

	// ans°¡ Â¦¼öÀÌ°í °öÀÌ È¦¼ö¶ó¸é ¹«Á¶°Ç change
	if (ans % 2 == 0 && a * b * c % 2)
		ans = a * b * c;

	// ans¿Í °öÀÌ ¸ðµÎ È¦¼öÀÎµ¥ °öÀÌ ´õ Å©´Ù¸é change
	else if (ans % 2 && a * b * c % 2 && ans < a * b * c)
		ans = a * b * c;

	// ans¿Í °öÀÌ ¸ðµÎ Â¦¼öÀÎµ¥ °öÀÌ ´õ Å©´Ù¸é change
	else if (ans % 2 == 0 && a * b * c % 2 == 0 && ans < a * b * c)
		ans = a * b * c;

	cout << ans;
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