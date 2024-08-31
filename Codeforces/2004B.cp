#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, l1, l2, r1, r2;
	cin >> t;
	while(t--) {
		cin >> l1 >> r1 >> l2 >> r2;

		int ans = min(r1, r2) - max(l1, l2);
		if (ans < 0)
			ans = 1;
		else {
			ans += (l1 != l2);
			ans += (r1 != r2);
		}

		cout << ans << endl;
	}

	return 0;
}