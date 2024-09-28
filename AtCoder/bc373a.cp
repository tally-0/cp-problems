#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	int ans = 0;
	for(int i = 1; i <= 12; i++) {
		cin >> s;
		if (s.length() == i)
			ans++;
	}

	cout << ans;

	return 0;
}