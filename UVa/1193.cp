#include<iostream>
#include<climits>
#include<cmath>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, d;
	pair<double, double> p[1000];
	for(int t = 1; cin >> n >> d && n + d; t++) {
		cout << "Case " << t << ": ";
		bool f = true;
		for(int i = 0, x, y; i < n; i++) {
			cin >> x >> y;
			if (y > d)
				f = false;
			double a = sqrt(d * d - y * y);
			p[i] = { x + a, x - a };
		}

		if (!f) {
			cout << -1 << endl;
			continue;
		}
		sort(p, p + n);
		double last = INT_MAX;
		int ans = 0;
		for(int i = 0; i < n; i++) {
			if (p[i].second <= last && last <= p[i].first)
				continue;
			last = p[i].first;
			ans++;
		}

		cout << ans << endl;
	}

	return 0;
}