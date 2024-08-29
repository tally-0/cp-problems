#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, g, s[100000];
	while (cin >> n >> g) {
		for(int i = 0, a, b; i < n; i++) {
			cin >> a >> b;
			s[i] = a - b;
		}

		sort(s, s + n, greater<int>());
		
		int ans = 0;
		for(int i = 0; i < n; i++) {
			if (s[i] <= 0)
				g += s[i] - 1;
			if (s[i] > 0 || g >= 0)
				ans += 3;
			else if (!s[i] || g == -1)
				ans++;
		}

		cout << ans << endl;
	}

	return 0;
}
