#include<iostream>
#include <algorithm>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, x[1000], t[1000];
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> x[i] >> t[i];
	for(int i = 0; i < n; i++) {
		if (x[i] > 0) {
			reverse(x + i, x + n);
			reverse(t + i, t + n);
			break;
		}	
	}

	int i = 0;
	ll ans = 0;
	while(i < n) {
		ans += abs(x[i]) * 2;
		int cap = k;
		while(i < n && cap) {
			if (cap > t[i]) {
				cap -= t[i];
				t[i] = 0;
			} else {
				t[i] -= cap;
				cap = 0;
			}
			if (!t[i])
				i++;
			if (i > 0 && x[i - 1] < 0 && x[i] > 0)
				break;
		}
	}

	cout << ans;

	return 0;
}