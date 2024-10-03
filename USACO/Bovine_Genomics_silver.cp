#include<iostream>
#include<fstream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ifstream cin("cownomics.in");
	ofstream cout("cownomics.out");

	int n, m;
	cin >> n >> m;
	string s[500], p[500];
	for(int i = 0; i < n; i++)
 		cin >> s[i];
	for(int i = 0; i < n; i++)
		cin >> p[i];

	int ans = 0;
	for(int i = 0; i < m; i++) {
		for(int j = i + 1; j < m; j++) {
			for(int k = j + 1; k < m; k++) {
				bool m[26][26][26] = { false }, f = true;
				for(int g = 0; g < n; g++)
					m[s[g][i] - 'A'][s[g][j] - 'A'][s[g][k] - 'A'] = true;
				for(int g = 0; g < n && f; g++)
					if (m[p[g][i] - 'A'][p[g][j] - 'A'][p[g][k] - 'A'] == true)
						f = false;
				ans += f;
			}
		}
	}

	cout << ans;

	return 0;
}