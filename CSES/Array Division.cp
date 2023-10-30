#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'
#define ll long long

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	ll maxsum = 0;
	for(int &i : v) {
		cin >> i;
		maxsum += i;
	}

	auto f = [=] (ll x) -> bool {
		int subs = 1;
		ll sum = 0;
		for (int i : v) {
			if (i > x) return false;
			if (sum + i > x) {
				subs++;
				sum = 0;
				if(subs > k) return false;
			}
			sum += i;
		}
		return true;
	};

	ll lo = 1, hi = maxsum++;
	while (lo < hi) {
		ll mid = lo + (hi - lo) / 2;
		if(f(mid)) hi = mid;
		else lo = mid + 1;
	}
	
	cout << lo << endl;

	return 0;
}