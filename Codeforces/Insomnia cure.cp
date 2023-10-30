#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k, l, m, n, d;
	cin >> k >> l >> m >> n >> d;

	if (k == 1 || l == 1 || m == 1 || n == 1) cout << d;
	else {
		int ans = 0;
		for (int i = 1; i <= d; i++) {
			if (!(i % k) || !(i % l) || !(i % m) || !(i % n)) ans++;
		}
		cout << ans;
	}

	return 0;
}