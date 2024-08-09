#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, p[1002][1002] = { 0 };
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1, a; j <= m; j++) {
			cin >> a;
			p[i][j] = max(p[i - 1][j], p[i][j - 1]) + a;
		}
	}
	for(int i = 1; i <= n; i++)
		cout << p[m][i] << " ";

	return 0;
}