#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

#define endl '\n'

int t, w, n, d[30], v[30];
int mem[31][1000];

int dp(int i, int rt) {
	if (i == n || !rt)
		return 0;
	if (mem[i][rt] == -1) {
		if (3 * w * d[i] > rt)
			mem[i][rt] = dp(i + 1, rt);
		else
			mem[i][rt] = max(dp(i + 1, rt), v[i] + dp(i + 1, rt - 3 * w * d[i]));
	}
	return mem[i][rt];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	bool first = true;
	while(cin >> t >> w) {
		if (!first)
			cout << endl;
		first = false;
		
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> d[i] >> v[i];

		memset(mem, -1, sizeof(mem));
		cout << dp(0, t) << endl;
		int path[30], pn = 0;
		for(int i = 0; i < n && t >= 0; i++) {
			if (mem[i][t] > (mem[i + 1][t] == -1 ? 0 : mem[i + 1][t])) {
				path[pn++] = i;
				t -= 3 * w * d[i];
			}
		}
		sort(path, path + pn);
		cout << pn << endl;
		for(int i = 0; i < pn; i++)
			cout << d[path[i]] << " " << v[path[i]] << endl;
	}

	return 0;
}