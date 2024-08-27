#include<iostream>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	ll ans = 0, start, end, d;
	cin >> start;
	end = start;
	while(--n) {
		cin >> d;
		if (d - end > k) {
			ans += end - start + 1 + k;
			start = d;
		}
		end = d;
	}
	ans += end - start + 1 + k;

	cout << ans;

	return 0;
}