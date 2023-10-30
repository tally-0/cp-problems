#include <iostream>

using namespace std;

#define endl '\n'
typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, p, tc = 1, tows[20], m;
	pii shared[10];
	while(cin >> n >> p && n + p) {
		for(int i = 0; i < n; i++)
			cin >> tows[i];
		cin >> m;
		for(int i = 0; i < m; i++) {
			int nt, bm = 0;
			cin >> nt;
			for(int j = 0; j < nt; j++) {
				int idx;
				cin >> idx;
				bm |= (1 << --idx);
			}
			shared[i].first = bm;
			cin >> shared[i].second;
		}

		int maxc = 0, maxs = -1;
		for(int i = 0; i < (1 << n); i++) {
			int nt = 0, served = 0;
			for(int j = 0; j < n; j++) {
				if(i & (1 << j)) {
					nt++;
					served += tows[j];
				}
			}
			if(nt != p)
				continue;
			for(int j = 0; j < m; j++) {
				nt = 0;
				int bm = shared[j].first & i;
				for(int k = 0; k < n; k++)
					if(bm & (1 << k))
						nt++;
				if(--nt > 0)
					served -= nt * shared[j].second;
			}
			if(maxs < served) {
				maxc = i;
				maxs = served;
			} else if(maxs == served) {
				for(int j = 0; j < n; j++) {
					int a = i & (1 << j);
					int b = maxc & (1 << j);
					if(a != b) {
						if(a)
							maxc = i;
						break;
					}
				}
			}
		}

		cout << "Case Number  " << tc << endl;
		cout << "Number of Customers: " << maxs << endl;
		cout << "Locations recommended:";
		for(int i = 0; i < n; i++)
			if(maxc & (1 << i))
				cout << " " << i + 1;
		cout << endl << endl;
		tc++;
	}

	return 0;
}