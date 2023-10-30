#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'
typedef long long ll;

constexpr long long BIG = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, q, a, b, c;
	cin >> n >> m >> q;
	ll mat[n+1][n+1];
	for(int i = 0; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			mat[i][j] = mat[j][i] = BIG;
	while(m--) {
		cin >> a >> b >> c;
		mat[a][b] = mat[b][a] = min(mat[a][b], (ll)c);
	}

	for(int k = 0; k <= n; k++)
		for(int i = 0; i <= n; i++)
			for(int j = i + 1; j <= n; j++)
				mat[i][j] = mat[j][i] = min(mat[i][j], mat[i][k] + mat[k][j]);

	while(q--) {
		cin >> a >> b;
		if (a == b) cout << 0;
		else if (mat[a][b] == BIG) cout << -1;
		else cout << mat[a][b];
		cout << endl;
	}

	return 0;
}