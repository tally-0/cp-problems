#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, l, n;
	cin >> t;
	while(t--) {
		cin >> l >> n;

		int a = 0, b = 0, c;
		while(n--) {
			cin >> c;
			a = max(a, min(l - c, c));
			b = max(b, max(l - c, c));
		}
	
		cout << a << " " << b << endl;
	}

	return 0;
}
