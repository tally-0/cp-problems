#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int c, n, v[2000], w[2000];
int mem[2001][2001];

int dp(int i, int cw) {
	if (cw == 0 || i == n)
		return 0;
	if (mem[i][cw] == -1) {
		if (w[i] > cw)
			mem[i][cw] = dp(i + 1, cw);
		else
			mem[i][cw] = max(dp(i + 1, cw), v[i] + dp(i + 1, cw - w[i]));
	}
	return mem[i][cw];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	 while(cin >> c >> n) {
		for(int i = 0; i < n; i++)
			cin >> v[i] >> w[i];

		memset(mem, 0xff, sizeof(mem));
		dp(0, c);

		int ans[2000], ansn = 0;
		for(int i = 0, cw = c; i < n; i++) {
			if (mem[i][cw] > (i  + 1 < n ? mem[i + 1][cw] : 0)) {
				ans[ansn++] = i;
				cw -= w[i];
			}
		}
		cout << ansn << endl;
		for(int i = 0; i < ansn; i++)
			cout << ans[i] << " ";
		cout << endl;
	}

	return 0;
}