#include<iostream>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int s[18];
	int n;
	for(int tc = 1; cin >> n; tc++) {
		for(int i = 0; i < n; i++)
			cin >> s[i];

		ll ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j <= n; j++) {
				ll p = 1;
				for(int k = i; k < j; k++)
					p *= (ll)s[k];
				ans = max(p, ans);
			}
		}

		cout << "Case #" << tc << ": The maximum product is " << ans << "." << endl << endl;
	}

	return 0;
}