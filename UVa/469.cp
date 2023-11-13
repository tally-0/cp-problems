#include<iostream>
#include<sstream>
#include<cstring>

using namespace std;

#define endl '\n'

int n, m, mat[99][99];
bool used[99][99];

int ff(int i, int j) {
	if (i >= n || j >= m || i < 0 || j < 0)
		return 0;
	if (used[i][j] || !mat[i][j])
		return 0;
	used[i][j] = true;
	int ans = 1;
	for(int a = -1; a < 2; a++)
		for(int b = -1; b < 2; b++)
			ans += ff(i + a, j + b);
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	int t;
	cin >> t;
	cin.ignore();
	cin.ignore();
	while(t--) {
		getline(cin, s);
		m = s.length(), n = 0;
		do {
			for(int i = 0; i < m; i++)
				mat[n][i] = (s[i] == 'W');
			n++;
		} while(getline(cin, s) && s.length() == m);
		do {
			stringstream ss(s);
			int i, j;
			ss >> i >> j;
			i--; j--;
			memset(used, false, sizeof(used));
			cout << ff(i, j) << endl;
		} while(getline(cin, s) && s != "");
		if (t)
			cout << endl;
	}

	return 0;
}