#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int m, n, p[100], f[100];
int mem[100][10200];

int dp(int i, int w) {
	if (w > m && m < 1800)
		return -1000;
	if (w > m + 200)
		return -1000;
	if (i == n) {
		if (w > m && w <= 2000)
			return -1000;
		return 0;
	}
	if (mem[i][w] == -1)
		mem[i][w] = max(dp(i + 1, w), f[i] + dp(i + 1, w + p[i]));
	return mem[i][w];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> m >> n) {
		for(int i = 0; i < n; i++)
			cin >> p[i] >> f[i];

		memset(mem, -1, sizeof(mem));
		cout << dp(0, 0) << endl;
	}

	return 0;
}