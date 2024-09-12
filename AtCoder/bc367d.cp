#include<iostream>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, a[200000];
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i];

	int ps[400002];
	ps[0] = 0;
	for(int i = 0; i < 2 * n; i++) {
		ps[i + 1] = a[i % n] + ps[i];
		ps[i + 1] %= m;
	}
	int c[1000001] = { 0 };
	for(int i = 0; i < n; i++)
		c[ps[i]]++;
	ll ans = 0;
	for(int i = n; i < 2 * n; i++) {
		c[ps[i - n]]--;
		ans += c[ps[i]];
		c[ps[i]]++;
	}

	cout << ans;

	return 0;
}