#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

#define endl '\n'

int n; 
vector<int> adj[101];
bool vis[101];

void dfs(int i) {
	for(int j : adj[i]) {
		if (!vis[j]) {
			vis[j] = true;
			dfs(j);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n && n) {
		memset(adj, 0, sizeof(adj));
		for(int i; cin >> i && i;)
			for(int j; cin >> j && j;)
				adj[i].push_back(j);
		int i;
		cin >> i;
		while(i--) {
			int j;
			cin >> j;
			memset(vis, false, sizeof(vis));
			dfs(j);
			int ans = 0;
			for(int k = 1; k <= n; k++)
				ans += !vis[k];
			cout << ans;
			for(int k = 1; k <= n; k++)
				if (!vis[k])
					cout << " " << k;
			cout << endl;
		}
	}

	return 0;
}