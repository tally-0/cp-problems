#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, m, n, q, r, c;
	string grid[100];
	cin >> t;
	while(t--) {
		cin >> m >> n >> q;
		for(int i = 0; i < m; i++) cin >> grid[i];

		cout << m << " " << n << " " << q << endl;

		while(q--) {
			cin >> r >> c;
			bool a = false;
			for(int i = 1; i <= min(min(r, m-r), min(c, n-c)); i++) {
				for(int j = 0; j < i * 2 + 1; j++) {
					int x = r-i, y = c-i+j;
					if (x < 0 || x >= m || y < 0 || y >= n || grid[r][c] != grid[x][y]) {
						a = true;
						break;
					}
					x = r+i;
					if (x < 0 || x >= m || y < 0 || y >= n || grid[r][c] != grid[x][y]) {
						a = true;
						break;
					}
					x = r-i+j, y = c-i;
					if (x < 0 || x >= m || y < 0 || y >= n || grid[r][c] != grid[x][y]) {
						a = true;
						break;
					}
					y = c+i;
					if (x < 0 || x >= m || y < 0 || y >= n || grid[r][c] != grid[x][y]) {
						a = true;
						break;
					}
				}
				if (a) {
					cout << (i - 1) * 2 + 1 << endl;
					break;
				}
			}
			if (!a) cout << min(min(r, m-r), min(c, n-c)) * 2 + 1 << endl;
		}
	}

	return 0;
}