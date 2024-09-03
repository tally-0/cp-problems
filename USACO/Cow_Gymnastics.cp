#include<iostream>
#include<fstream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ifstream cin("gymnastics.in");
	ofstream cout("gymnastics.out");

	int k, n, p[20], c[21][21] = { 0 };
	cin >> k >> n;
	for(int a = 0; a < k; a++) {
		for(int i = 0; i < n; i++)
			cin >> p[i];
		
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				c[p[i]][p[j]]++;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			ans += c[i][j] == k;

	cout << ans;

	return 0;
}