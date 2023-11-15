#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int t, n, p[1000], w[1000], g;
int mem[1000][31];

int dp(int rw, int i) {
	if (i == n || !rw)
		return 0;
	if (mem[i][rw] == -1) {
		if (w[i] > rw)
			mem[i][rw] = dp(rw, i + 1);
		else
			mem[i][rw] = max(dp(rw, i + 1), p[i] + dp(rw - w[i], i + 1));
	}
	return mem[i][rw];	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> p[i] >> w[i];
		cin >> g;
	
		memset(mem, 0xff, sizeof(mem));
		int ans = 0, mw;
		while(g--) {
			cin >> mw;
			ans += dp(mw, 0);
		}
		
		cout << ans << endl;
	}

	return 0;
}