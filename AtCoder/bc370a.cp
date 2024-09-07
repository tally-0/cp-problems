#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int l, r;
	cin >> l >> r;
	if (l && !r)
		cout << "Yes";
	else if (!l && r)
		cout << "No";
	else
		cout << "Invalid";

	return 0;
}