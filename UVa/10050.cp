#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n, p, h[101];
	cin >> t;
	while(t--) {
		cin >> n >> p;
		for(int i = 0; i < p; i++)
			cin >> h[i];
		
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			if ((i % 7) == 6 || (i % 7) == 0)
				continue;
			bool f = false;
			for(int j = 0; j < p && !f; j++)
				if (i % h[j] == 0)
					f = true;
			ans += f;
		}
		
		cout << ans << endl;
	}

	return 0;
}