#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, t;
	while(cin >> s >> t) {
		int i = 0;
		for(int j = 0; i < s.length() && j < t.length(); j++)
			if (s[i] == t[j])
				i++;
		cout << (i == s.length() ? "Yes" : "No") << endl;
	}

	return 0;
}