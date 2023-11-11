#include<iostream>
#include<climits>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int c, n;
	cin >> c;
	while(c--) {
		cin >> n;

		int ans = INT_MAX;
		for(int a = 1; a <= n; a++) {
			for(int b = 1; b <= n; b++) {
				if (a * b > n)
					break;
				int d = n / (a * b);
				if (a * b * d == n)
					ans = min(ans, 2 * (n / a + n / b + n / d));
			}
		}

		cout << ans << endl;
	}

	return 0;
}