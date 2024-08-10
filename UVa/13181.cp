#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	while(cin >> s) {
		int a = 0, maxa = 0, inbetween = false;
		for(int i = 0; i < s.length(); i++) {
			if (s[i] == 'X') {
				if (inbetween)
					a = (a + 1) / 2;
				maxa = max(a, maxa);
				inbetween = true;
				a = 0;
			} else
				a++;
		}
		if (s[s.length() - 1] == '.')
			maxa = max(a, maxa);
		cout << maxa - 1 << endl;
	}

	return 0;
}