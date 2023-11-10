#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x, h[1000], s[1000];
	cin >> n >> x;
	for(int i = 0; i < n; i++)
		cin >> h[i];
	for(int i = 0; i < n; i++)
		cin >> s[i];

	int mem[1001][100001];
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= x; j++) {
			mem[i][j] = mem[i - 1][j];
			if (j >= h[i - 1])
				mem[i][j] = max(mem[i][j], s[i - 1] + mem[i - 1][j - h[i - 1]]);
		}
	}
	cout << mem[n][x];

	return 0;
}