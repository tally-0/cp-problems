/*
Per 2 iterative loops as per Halim's Competitive Programming
#include<iostream>
#include<climits>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, r, s[500];
	cin >> t;
	for(int tc = 1; tc < t; tc++) {
		cin >> r;
		for(int i = 0; i < r; i++)
			cin >> s[i];

		int ans = INT_MAX;
		for(int i = 0; i < 30000; i++) {
			int d = 0;
			for(int j = 0; j < r; j++)
				d += ans(i - s[j]);
			ans = min(d, ans);
		}

		cout << ans << endl;
	}		

	return 0;
}*/
#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, r, s[500];
	cin >> t;
	while(t--) {
		cin >> r;
		for(int i = 0; i < r; i++)
			cin >> s[i];

		sort(s, s + r);
		int x = s[r / 2];

		int ans = 0;
		for(int i = 0; i < r; i++)
			ans += abs(x - s[i]);

		cout << ans << endl;
	}

	return 0;
}