#include<iostream>
#include<vector>
#include<cstring>
#include<qeueu>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, l;
	vector<int> adj[200];
	while(cin >> n && n) {
		cin >> l;
		memset(adj, 0, sizeof(adj));
		while(l--) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		int col[200] = { 0 };
		queue<int> q;
		q.push(0);
		bool ans = true; 
		while(!q.empty() && ans) {
			int u = q.front();
			q.pop();
			for(int v : adj[u]) {
				if (col[v] == 0) {
					col[v] = (col[u] == 1) + 1;
					q.push(v);
				} else if (col[v] == col[u])
					ans = false;
			}
		}
	
		cout << (ans ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
	}

	return 0;
}