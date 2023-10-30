#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define endl '\n'
#define pb push_back

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, n, t = 1;
	while(cin >> n) {
		vector<int> adj[21] = {};
		for(int i = 1; i <= 19; i++) {
			if(i > 1) cin >> n;
			while(n--) {
				cin >> a;
				adj[i].pb(a);
				adj[a].pb(i);
			}
		}

		cout << "Test Set #" << t++ << endl;
		cin >> n;
		while(n--) {
			cin >> a >> b;
			int dist[21] = {};
			dist[a] = 0;
			queue<int> q;
			q.push(a);
			bool brk = false;
			while(!q.empty()) {
				int v = q.front(); q.pop();
				for(int ne : adj[v]) {
					if (ne == b) {
						dist[ne] = dist[v] + 1;
						brk = true;
						break;
					}
					if (!dist[ne]) {
						dist[ne] = dist[v] + 1;
						q.push(ne);
					}
				}
				if (brk) break;
			}
			if (a >= 10) cout << a;
			else cout << " " << a;
			cout << " to ";
			if (b >= 10) cout << b;
			else cout << " " << b;
			cout << ": " << dist[b] << endl;
		}
		cout << endl;
	} 

	return 0;
}