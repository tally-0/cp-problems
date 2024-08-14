#include<iostream>

using namespace std;

#define endl '\n'
#define ll long long

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, n;
	ll mat[101][101];
	cin >> T;
	for(int t = 1; t <= T; t++) {
		char c;
		cin >> c >> c >> n;
		cerr << n << endl;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> mat[i][j];
		bool ans = true;
		for(int i = 0; i < n && ans; i++)
			for(int j = 0; j < n && ans; j++)
				ans = (mat[i][j] == mat[n - i - 1][n - j - 1] && mat[i][j] >= 0);
		cout << "Test #" << t << ": ";
		if (ans)
			cout << "Symmetric." << endl;
		else
			cout << "Non-symmetric." << endl;
	}
		
	return 0;
}