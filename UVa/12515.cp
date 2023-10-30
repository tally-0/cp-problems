#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, q;
	cin >> m >> q;
	string db[m], clip;
	for(int i = 0; i < m; i++) cin >> db[i];

	while(q--) {
		cin >> clip;
		int mind = 101, mini = -1;
		for(int k = 0; k < m; k++) {
			if (db[k].length() < clip.length()) continue;
			for(int i = 0; i < db[k].length() - clip.length() + 1; i++) {
				int d = 0;
				for(int j = 0; j < clip.length(); j++) {
					if (clip[j] != db[k][i+j]) d++;
				}
				if (d < mind) {
					mind = d;
					mini = k;
				}
			}
		}
		cout << mini + 1 << endl;
	}

	return 0;
}