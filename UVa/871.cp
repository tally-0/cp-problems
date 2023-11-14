#include<iostream>

using namespace std;

#define endl '\n'

int n, m, grid[25][25];

int ff(int i, int j) {
	if (i >= n || j >= m || i < 0 || j < 0)
		return 0;
	if (!grid[i][j])
		return 0;
	grid[i][j] = 0;
	int ans = 1;
	for(int k = -1; k < 2; k++)
		for(int g = -1; g < 2; g++)
			ans += ff(i + k, j + g);
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	cin.ignore();
	cin.ignore();
	while(t--) {
		string str;
		m = n = 0;
		while(getline(cin, str) && str.length() >= m) {
			m = str.length();
			for(int i = 0; i < m; i++)
				grid[n][i] = (str[i] - '0');
			n++;
		}

		int ans = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if (grid[i][j])
					ans = max(ans, ff(i, j));
		cout << ans << endl;
		if (t)
			cout << endl;
	}

	return 0;
}