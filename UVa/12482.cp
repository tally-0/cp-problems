#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, l, c;
	while(cin >> n >> l >> c) {
		string s;
		int cl = 1, cc = -1;
		for(int i = 0; i < n; i++) {
			cin >> s;
			cc += s.length() + 1;
			if (cc > c) {
				cl++;
				cc = s.length();
			}
		}
		cout << ((cl - 1) / l + 1) << endl;
	}

	return 0;
}