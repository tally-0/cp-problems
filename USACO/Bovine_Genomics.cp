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
	
	string str;
	int s[100][26] = { 0 }, p[100][26] = { 0 };
	for(int i = 0; i < n; i++) {
		cin >> str;
		for(int j = 0; j < m; j++)
			s[j][str[j] - 'A']++;
	}
	for(int i = 0; i < n; i++) {
		cin >> str;
		for(int j = 0; j < m; j++)
			p[j][str[j] - 'A']++;
	}
	int ans = 0;
	for(int i = 0; i < m; i++) {
		bool f = true;
		for(int j = 0; j < 26 && f; j++)
			if (p[i][j] && s[i][j])
				f = false;
		if (f)
			ans++;
	}

	cout << ans;

	return 0;
}