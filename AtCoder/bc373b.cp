#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	
	int p, ans = 0;
	for(p = 0; p < 26; p++)
		if (s[p] == 'A')
			break;
	for(int i = 1; i < 26; i++) {
		for(int j = 0; j < 26; j++) {
			if (s[j] == ('A' + i)) {
				ans += abs(p - j);
				p = j;
			}
		}
	}

	cout << ans;

	return 0;
}