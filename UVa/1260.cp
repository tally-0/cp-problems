#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, a[1000], n;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> a[i];

		int ans = 0;
		for(int i = 1; i < n; i++)
			for(int j = 0; j < i; j++)
				ans += (a[j] <= a[i]);

		cout << ans << endl;
	}

	return 0;
}