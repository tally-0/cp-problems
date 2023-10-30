#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int c, n, t, m;
	cin >> c;
	while(c--) {
		cin >> n >> t >> m;

		vector<int> v(m);
		for(int &i : v) cin >> i;

		if (n > m) cout << v[m - 1] + t << " " << 1 << endl;
		else {
			int total = 0;
			for (int i = (m + n - 1) % n; i < m; i += n) total = max(total, v[i]) + 2 * t;
			cout << total - t << " " << (m + n - 1) / n << endl;
		}
	}
	return 0;
}