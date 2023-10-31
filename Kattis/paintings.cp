#include<iostream>
#include<unordered_map>
#include<vector>
#include<cstring>

using namespace std;

#define endl '\n'

int n, h[12][12], m, best[12], p[12], f;

int backtrack(int used, int j = 0) {
	if (j == n) {
		if (f)
			for(int i = 0; i < n; i++)
				best[i] = p[i];
		f = 0;
		return 1;
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if (j > 0 && !h[p[j-1]][i])
			continue;
		if (used & (1 << i)) {
			p[j] = i;
			ans += backtrack(used & ~(1 << i), j + 1);
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		unordered_map<string, int> cols;
		unordered_map<int, string> revcols;
		for(int i = 0; i < n; i++) {
			cin >> revcols[i];
			cols[revcols[i]] = i;
		}
		cin >> m;
		memset(h, true, sizeof(h));
		for(int i = 0; i < m; i++) {
			string a, b;
			cin >> a >> b;
			h[cols[a]][cols[b]] = h[cols[b]][cols[a]] = false;
		}

		memset(p, 0, sizeof(p));
		f = 1;
		int ans = backtrack((1 << n) - 1);
		cout << ans << endl;
		cout << revcols[best[0]];
		for(int i = 1; i < n; i++)
			cout << " " << revcols[best[i]];
		cout << endl;
	}	

	return 0;
}