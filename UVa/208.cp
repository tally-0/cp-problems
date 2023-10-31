#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int t, mat[25][25], pruned[25], visited[25], path[25], pc;

void prune(int v) {
	pruned[v] = false;
	for(int i = 1; i <= 21; i++)
		if (mat[v][i] && pruned[i])
			prune(i);
}

void backtrack(int prev, int j) {
	if (prev == t) {
		pc++;
		cout << path[0];
		for(int i = 1; i < j; i++)
			cout << " " << path[i];
		cout << endl;
	}
	for(int i = 1; i <= 21; i++) {
		if (mat[prev][i] && !visited[i] && !pruned[i]) {
			visited[i] = true;
			path[j] = i;
			backtrack(i, j + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc = 1;
	while(cin >> t) {
		memset(mat, false, sizeof(mat));
		for(int a, b; cin >> a >> b && a + b;) {
			mat[a][b] = mat[b][a] = true;
		}
		
		memset(pruned, true, sizeof(pruned));
		prune(t);
		memset(visited, false, sizeof(visited));
		visited[1] = true;
		pc = 0;
		path[0] = 1;
		cout << "CASE " << tc << ":\n";
		backtrack(1, 1);
		cout << "There are " << pc << " routes from the firestation to streetcorner " << t << ".\n";
		tc++;
	}

	return 0;
}