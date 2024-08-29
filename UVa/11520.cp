#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, n, mat[12][12];
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> n;
		string s;
		memset(mat, -1, sizeof mat);
		for(int i = 1; i <= n; i++) {
			cin >> s;
			for(int j = 1; j <= n; j++)
				if (s[j - 1] == '.')
					mat[i][j] = -1;
				else
					mat[i][j] = s[j - 1] - 'A';
		}

		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if (mat[i][j] == -1)
					for(int k = 0; k < 26 && mat[i][j] == -1; k++)
						if (mat[i + 1][j] != k && mat[i - 1][j] != k && mat[i][j + 1] != k && mat[i][j - 1] != k)
							mat[i][j] = k;

		cout << "Case " << t << ":" << endl;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++)
				cout << (char)(mat[i][j] + 'A');
			cout << endl;
		}
	}

	return 0;
}