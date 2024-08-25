#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n, q;
	cin >> t;
	while(t--) {
		cin >> n >> q;
		int av[256] = { 0 }, x;
		while(n--) {
			cin >> x;
			av[x & 255] = 1;
		}
		int a;
		while(q--) {
			cin >> a;
			int ans = 0;
			for(int i = 0; i < 256; i++)
				if (av[i])
					ans = max(ans, a & i);
			cout << ans << endl;
		}
	}

	return 0;
}