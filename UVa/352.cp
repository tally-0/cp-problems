#include<iostream>

using namespace std;

#define endl '\n'

int n, mat[25][25];
int dirs[8][2] = {
	{ 0, 1 },
	{ 0, -1 },
	{ 1, 0 },
	{ -1, 0 },
	{ 1, 1 },
	{ -1, -1 },
	{ 1, -1 },
	{ -1, 1}
};

void ff(int i, int j) {
	if (i >= n || j >= n || i < 0 || j < 0)
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

	for(int t = 1; cin >> n; t++) {
		cerr << n << endl;
		for(int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for(int j = 0; j < n; j++)
				mat[i][j] = s[j] - '0';
		}

		int ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if (mat[i][j] == 1) {
					ff(i, j);
					ans++;
				}
			}
		}

		cout << "Image number " << t << " contains " << ans << " war eagles." << endl;
	}

	return 0;
}