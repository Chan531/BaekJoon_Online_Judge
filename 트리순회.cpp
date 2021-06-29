#include <iostream>
#include <map>

using namespace std;

map<char, pair<char, char>> tree;

void ava(char c)
{
	cout << c;
	if (tree[c].first != '.')
		ava(tree[c].first);
	if (tree[c].second != '.')
		ava(tree[c].second);
}

void mid(char c)
{
	if (tree[c].first != '.')
		mid(tree[c].first);
	cout << c;
	if (tree[c].second != '.')
		mid(tree[c].second);
}

void rea(char c)
{
	if (tree[c].first != '.')
		rea(tree[c].first);
	if (tree[c].second != '.')
		rea(tree[c].second);
	cout << c;
}

int main()
{
	int n = 0;
	char a, b, c;
	char root;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		tree[a] = make_pair(b, c);
		if (i == 0)
			root = a;
	}
	ava(root);
	cout << '\n';
	mid(root);
	cout << '\n';
	rea(root);
}