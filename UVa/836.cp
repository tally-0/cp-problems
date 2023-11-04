#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, mat[26][25];
	cin >> t;
	while(t--) {
		int n = 25;
		for(int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			n = s.length();
			for(int j = 0; j < n; j++) {
				if (s[j] == '1')
					mat[i][j] = 1;
				else
					mat[i][j] = -1 * n * n;
				mat[i][j] += mat[i - 1][j];
			}
		}
		
		int ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j <= n; j++) {
				int s = 0;
				for(int k = 0; k < n; k++) {
					s += mat[j][k] - mat[i][k];
					s = max(s, 0);
					ans = max(ans, s);
				}
			}
		}

		cout << ans << endl;
		if (t)
			cout << endl;
	}

	return 0;
}