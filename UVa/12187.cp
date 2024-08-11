#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, r, c, k, a[102][102], b[102][102];
	memset(a, -1, sizeof a);
	while(cin >> n >> r >> c >> k && n + r + c + k) {
		for(int i = 1; i <= r; i++)
			for(int j = 1; j <= c; j++)
				cin >> a[i][j];

		while(k--) {
			memcpy(b, a, sizeof b);
			for(int i = 1; i <= r; i++) {
				for(int j = 1; j <= c; j++) {
					int t = (a[i][j] + 1) % n;
					if (a[i + 1][j] == t)
						b[i + 1][j] = a[i][j];
					if (a[i - 1][j] == t)
						b[i - 1][j] = a[i][j];
					if (a[i][j + 1] == t)
						b[i][j + 1] = a[i][j];
					if (a[i][j - 1] == t)
						b[i][j - 1] = a[i][j];
				}
			}
			memcpy(a, b, sizeof b);
		}
		for (int i = 1; i <= r; i++) {
			cout << a[i][1];
			for (int j = 2; j <= c; j++)
				cout << " " << a[i][j];
			cout << endl;
		}
	}				

	return 0;
}