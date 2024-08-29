#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, n, a[800], b[800];
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		for(int i = 0; i < n; i++)
			cin >> b[i];

		sort(a, a + n);
		sort(b, b + n, greater<int>());
		ll ans = 0;
		for(int i = 0; i < n; i++)
			ans += (ll)a[i] * (ll)b[i];

		cout << "Case #" << t << ": " << ans << endl;
	}

	return 0;
}