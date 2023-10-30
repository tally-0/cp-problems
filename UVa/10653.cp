#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r, c, a, b, i, j;
	while(cin >> r >> c && r + c) {
		cin >> a;
	 	bool bombs[r*c] = { false };
		while(a--) {
			cin >> i >> b;
			while(b--) {
				cin >> j;
				bombs[i*c+j] = true;
			}
		}
		cin >> a >> b >> i >> j;
		int dist[r*c] = {};
		dist[a*c+b] = 0;
		queue<int> q;
		q.push(a*c+b);
		while(!q.empty()) {
			int u = q.front(); q.pop();
			if ((u + 1) % c && !dist[u + 1] && !bombs[u + 1]) {
				dist[u + 1] = dist[u] + 1;
				q.push(u + 1);
			}
			if (u % c && !dist[u - 1] && !bombs[u + 1]) {
				dist[u - 1] = dist[u] + 1;
				q.push(u - 1);
			}
			if (u - c >= 0 && !dist[u - c] && !bombs[u - c]) {
				dist[u - c] = dist[u] + 1;
				q.push(u - c);
			}
			if (u + c < r * c && !dist[u + c] && !bombs[u + c]) {
				dist[u + c] = dist[u] + 1;
				q.push(u + c);
			}
		}
		cout << dist[i*c+j] << endl;
	}

	return 0;
}