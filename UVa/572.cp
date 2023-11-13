#include<iostream>

using namespace std;

#define endl '\n'

int m, n, mat[100][100];

int dirs[8][2] = {
	{ 0, 1 },
	{ 0, -1 },
	{ 1, 0 },
	{ -1, 0 },
	{ 1, 1 },
	{ -1, -1 },
	{ -1, 1 },
	{ 1, -1 }
};

void ff(int i, int j) {
	if (i >= m || j >= n || i < 0 || j < 0)
		return;
	if (mat[i][j] != 1)
		return;
	mat[i][j] = 0;
	for(auto dir : dirs)
		ff(i + dir[0], j + dir[1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> m >> n && m) {
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				char c;	
				cin >> c;
				mat[i][j] = (c == '@');
			}
		}

		int ans = 0;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if (mat[i][j] == 1) {
					ff(i, j);
					ans++;
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}