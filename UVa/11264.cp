#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n, c[1000];
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> c[i];
		
		int sum = 0, ans = 0;
		for(int i = 0; i < n - 1; i++) {
			if (sum + c[i] >= c[i + 1])
				continue;
			sum += c[i];
			ans++;
		}

		cout << ans + 1 << endl;
	}

	return 0;
}