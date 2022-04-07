#include <iostream>

using namespace std;

int n;

void underbar(int cnt)
{
	for (int i = 0; i < cnt; i++)
		cout << "____";
}

void recur(int cnt)
{
	underbar(cnt);

	cout << "\"����Լ��� ������?\"\n";

	if (cnt == n)
	{
		underbar(cnt);
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";

		underbar(cnt);
		cout << "��� �亯�Ͽ���.\n";

		return;
	}

	underbar(cnt);
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";

	underbar(cnt);
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";

	underbar(cnt);
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";

	recur(cnt + 1);

	underbar(cnt);
	cout << "��� �亯�Ͽ���.\n";
}

void solve()
{
	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	recur(0);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}