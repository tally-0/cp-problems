#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n, m;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		int ans = 0, s = 0, swm = 0, f = false;
		for(int i = 0, a; i < n; i++) {
			cin >> a;
			if (a < m) {
				s = swm = f = 0;
				continue;
			}
			if (a == m) {
				if (f)
					s = swm;
				swm = -m;
				f = true;
			}
			s += a;
			if (f) {
				ans = max(ans, s);
				swm += a;
			}
		}
		cout << ans << endl;
	}

	return 0;
}