#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

#define endl '\n'
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	vector<pii> adj[100000];
	while(m--) {
		char c;
		int u, v; 
		cin >> c >> u >> v;
		u--, v--;
		adj[u].push_back({ v, (c == 'S') });
		adj[v].push_back({ u, (c == 'S') });
	}

	int col[100000], pos = true, ans = 0;
	memset(col, -1, sizeof(col));
	for(int i = 0; i < n && pos; i++) {
		if (col[i] != -1)
			continue;
		ans++;
		queue<pii> q;
		q.push({ i, 1 });
		while(!q.empty() && pos) {
			pii u = q.front();
			q.pop();
			col[u.first] = u.second;
			for(pii v : adj[u.first]) {
				int t = v.second ? u.second : !u.second;
				if (col[v.first] == -1)
					q.push({ v.first, t });
				else if (col[v.first] != t)
					pos = false;
			}
		}
	}
	
	if (pos) {
		cout << 1;
		for(int i = 0; i < ans; i++)
			cout << 0;
		cout << endl;
	} else
		cout << 0 << endl;

	return 0;
}