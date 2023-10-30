#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, p, votes;
	cin >> t;
	while(t--) {
		cin >> p;
		vector<int> v(p);
		int maj = 0;
		for(int &i : v) {
			cin >> i;
			maj += i;
		}
		maj = (maj + 1) / 2;

		vector<int> pi(p, 0);
		for (int i = 0; i < (1 << p); i++) {
			votes = 0;
			for (int j = 0; j < p; j++) {
				if (i & (1 << j)) {
					votes += v[j];
				}
			}
			if (votes < maj) {
				for (int j = 0; j < p; j++) {
					if (!(i & (1 << j))) {
						if (v[j] + votes >= maj) pi[j]++;
					}
				}
			}
		}

		for(int i = 1; i <= p; i++) cout << "party " << i << " has power index " << pi[i-1] << endl;
		cout << endl;
	}

	return 0;
}