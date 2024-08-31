#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	for(int i = s.length() / 2 + 1; i < s.length(); i++) {
		int a = i, b = s.length();
		do {
			a--;
			b--;
		} while (s[a] == s[b]);
		if (a == -1) {
			cout << "YES" << endl << s.substr(0, i);
			return 0;
		}
	}
	cout << "NO";

	return 0;
}