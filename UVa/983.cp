#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, mat[1001][1001], first = true;
	while(cin >> n >> m) {
		if (!first)
			cout << endl;
		first = false;

		memset(mat, 0, sizeof(mat));
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				cin >> mat[i][j];
				mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
			}
		}

		int s = 0;
		for(int i = 0; i <= n - m; i++) {
			for(int j = 0; j <= n - m; j++) {
				s += mat[m + i][m + j] - mat[i][m + j] - mat[m + i][j] + mat[i][j];
				cout << mat[m + i][m + j] - mat[i][m + j] - mat[m + i][j] + mat[i][j] << endl;
			}
		}
		
		cout << s << endl;
	}

	return 0;
}