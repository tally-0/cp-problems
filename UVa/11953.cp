#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int n, mat[100][100];
bool nfb;

void ff(int i, int j) {
	if (i >= n || j >= n || i < 0 || j < 0)
		return;
	if (mat[i][j] < 1)
		return;
	if (mat[i][j] == 1)
		nfb = true;
	mat[i][j] = 0;
	ff(i, j + 1);
	ff(i + 1, j);
	ff(i, j - 1);
	ff(i - 1, j);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for(int tc = 1; tc <= t; tc++) {
		cin >> n;
		memset(mat, 0, sizeof(mat));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				char c;
				cin >> c;
				if (c == 'x')
					mat[i][j] = 1;
				else if (c == '@')
					mat[i][j] = 2;
			}
		}

		int ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if (mat[i][j] > 0) {
					nfb = false;
					ff(i, j);
					ans += nfb;
				}
			}
		}
		
		cout << "Case " << tc << ": " << ans << endl;
	}


	return 0;
}