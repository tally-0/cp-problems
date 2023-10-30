#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	int a = 0, b = 0, c = 0;
	for(int i = 0; i < s.length(); i += 2) {
		if (s[i] == '1') a++;
		else if (s[i] == '2') b++;
		else c++;
	}

	s = "";
	while(a--) {
		if (a+b+c) {
			s += "1+";
		} else {
			s += "1";
		}
	}
	a++;
	while(b--) {
		if (a+b+c) {
			s += "2+";
		} else {
			s += "2";
		}
	}
	b++;
	while(c--) {
		if (a+b+c) {
			s += "3+";
		} else {
			s += "3";
		}
	}

	cout << s;

	return 0;
}