#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int l, u, r, b[10], t = 1;
	while(cin >> l >> u >> r && l + u + r) {
		for(int i = 0; i < r; i++) cin >> b[i];
		int dist[10000] = {};
		dist[l] = 0;
		queue<int> q;
		q.push(l);
		while(!q.empty() && !dist[u]) {
			int v = q.front(); q.pop();
			for(int i = 0; i < r; i++) {
				int a = (v + b[i]) % 10000;
				if (!dist[a]) {
					dist[a] = dist[v] + 1;
					q.push(a);
				}
			}
		}
		cout << "Case " << t << ": ";
		if(dist[u]) cout << dist[u];
		else cout << "Permanently Locked";
		cout << endl;
		t++;
	}

	return 0;
}