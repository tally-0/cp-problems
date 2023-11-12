#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

#define endl '\n'

vector<int> adj[27];
bool vis[27];

void dfs(int i) {
	if (vis[i])
		return;
	vis[i] = true;
	for(int j : adj[i])
		dfs(j);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n;
	cin >> t;
	while(t--) {
		char c;
		cin >> c;
		n = c - 'A';
		string str;
		cin.ignore();
		for(int i = 0; i <= n; i++)
			adj[i].clear();
		while(getline(cin, str) && str != "") {
			cerr << str << endl;
			adj[str[0] - 'A'].push_back(str[1] - 'A');
			adj[str[1] - 'A'].push_back(str[0] - 'A');
		}

		memset(vis, false, sizeof(vis));
		int ans = 0;
		for(int i = 0; i <= n; i++) {
			if (!vis[i]) {
				ans++;
				dfs(i);
			}
		}
	
		cout << ans << endl;
		if (t)
			cout << endl;
	}

	return 0;
}