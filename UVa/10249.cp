#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define ii pair<int,int>

int main() {
	int m, n, temp;
	while(cin >> m >> n && m + n > 0) {
		vector<int> teams(m);
		priority_queue<ii> tables;
		for(int &team : teams) cin >> team;
		for (int i = 0; i < n; i++) {
			cin >> temp; 
			tables.push(make_pair(temp, i));
		}

		bool valid = true;
		vector<vector<int>> sol(m);
		for (int i = 0; i < m; i++) {
			if (teams[i] > tables.size()) {
				valid = false;
				break;
			}
			vector<ii> used(teams[i]);
			for (ii &table : used) {
				table = tables.top();
				tables.pop();
				sol[i].push_back(table.second + 1);
				table.first--;
			}
			for (ii table : used) {
				if (table.first) tables.push(table);
			}
		}
		if (valid) {
			cout << 1 << endl;
			for (auto team : sol) {
				cout << team[0];
				for(auto it = team.begin() + 1; it < team.end(); it++) cout << " " << *it;
				cout << endl;
			}
		} else cout << 0 << endl;
	}
	return 0;
}