#include<iostream>
#include<algorithm>
#include<numeric>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, M;
	ll k, a[200000];
	cin >> n >> M >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		k -= a[i];
	}

	if (n == M) {
		for(int i = 0; i < n; i++)
			cout << 0 << " ";
		return 0;
	}
	int ord[200000];
	iota(ord, ord + n, 0);
	sort(ord, ord + n, [&](const int& l, const int& r) {
		return a[l] < a[r];
	});
	sort(a, a + n);
	ll s[200001] = { 0 };
	for(int i = 0; i < n; i++)	
		s[i + 1] = a[i] + s[i];
	ll ans[200000];
	for(int i = 0; i < n; i++) {
		int h = n - M - (i >= n - M);
		ll l = -1, r = k + 1;
		while(r - l > 1) {
			ll m = (l + r) / 2;
			int j = lower_bound(a, a + n, a[i] + m + 1) - a;
			ll req = 0;
			if (j > h)
				req = (j - h) * (a[i] + m + 1) - (s[j] - s[h]);
			if (i >= h && i < j)
				req--;
			else
				req += m;
			if (req > k)
				r = m;
			else
				l = m;
		}
		if (l == k)
			ans[ord[i]] = -1;
		else
			ans[ord[i]] = r;
	}

	for(int i = 0; i < n; i++)
		cout << ans[i] << " ";

	return 0;
}