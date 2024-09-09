#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, n, k;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> n >> k;

		int ans = 1;
		for(int i = 1; i <= n; i++)
			ans = (ans + k) % i;
	
		cout << "Case " << t << ": " << ans + 1 << endl;
	}

	return 0;
}