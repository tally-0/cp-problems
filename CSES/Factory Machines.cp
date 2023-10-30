#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

#define endl '\n'
#define ll long long

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t;
	cin >> n >> t;
	vector<int> v(n);
	for (int &i : v) cin >> i;

	sort(v.begin(), v.end());

	auto f = [=] (ll x) {
		ll sum = 0;
		for(int i : v) {
			sum += floor(x / i);
			if (sum >= t) break;
		}
 		return sum >= t;
	};

	ll lo = v[0], hi = (ll)v[n - 1] * (ll)t;
	while(lo < hi) {
		ll mid = lo + (hi - lo) / 2;
		if (f(mid)) hi = mid;
		else lo = mid + 1;
	}

	cout << lo << endl;

	return 0;
}