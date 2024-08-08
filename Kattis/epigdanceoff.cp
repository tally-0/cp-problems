#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cols[2001] = { 0 }, n, m;
	cin >> n >> m;

	string s;
	for(int i = 0; i < n; i++) {
		cin >> s;
		for(int j = 0; j < m; j++)
			cols[j] += (s[j] == '$');
	}

	int ans = 0;
	for(int i = 0; i < m; i++)
		ans += (cols[i] == 0);
	ans++;

	cout << ans;

	return 0;
}