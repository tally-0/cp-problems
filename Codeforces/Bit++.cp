#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x = 0;
	string s;
	cin >> n;
	while(n--) {
		cin >> s;
		if (s[1] == '+')
			x++;
		else
			x--;
	}
	cout << x;

	return 0;
}