#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, q;
	long long mat[501][501];
	cin >> n >> m >> q;
	
	memset(mat, -1, sizeof(mat));
	while(m--) {
		int a, b, c;
		cin >> a >> b >> c;
		mat[a][b] = mat[b][a] = (mat[a][b] == -1 ? c : min(mat[a][b], (long long)c));
	}
	
	for(int k = 0; k <= n; k++)
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= n; j++)
				if ((mat[i][j] == -1 || mat[i][j] > mat[i][k] + mat[k][j]) && (mat[i][k] != -1 && mat[k][j] != -1))
					mat[i][j] = mat[j][i] = mat[i][k] + mat[k][j];

	while(q--) {
		int a, b;
		cin >> a >> b;
		if (a == b)
			cout << 0 << endl;
		else cout << mat[a][b] << endl;
	}

	return 0;
}