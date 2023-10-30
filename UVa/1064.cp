#include<iostream>
#include<algorithm>
#include<set>
#include<climits>

using namespace std;

#define endl '\n'
typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, mes[6], ord[5], pacs[1000][3], first = 1, tc = 1;
	while(cin >> n >> m && n + m) {
		for(int i = 1; i <= n; i++)
			cin >> mes[i];
		for(int i = 0; i < m; i++)
			cin >> pacs[i][0] >> pacs[i][1] >> pacs[i][2];
		
		int minbs = INT_MAX;
		for(int i = 0; i < n; i++)
			ord[i] = i + 1;
		do {
			set<pii> bufs[6];
			int maxbs = 0, bs = 0, nb = 1, mi = 0;
			for(int i = 0; i < m; i++) {
				bs += (pacs[i][2] - pacs[i][1] + 1);
				bufs[pacs[i][0]].insert({ pacs[i][1], pacs[i][2] });
				while(mi < n && !bufs[ord[mi]].empty() && (*bufs[ord[mi]].begin()).first == nb) {
					auto a = bufs[ord[mi]].begin();
					bs -= ((*a).second - (*a).first + 1);
					nb = (*a).second + 1;
					bufs[ord[mi]].erase(a);
					if (nb >= mes[ord[mi]]) {
						mi++;
						nb = 1;
					}
				}
				maxbs = max(bs, maxbs);
			}
			minbs = min(minbs, maxbs);
		} while(next_permutation(ord, ord + n));

		cout << "Case " << tc << ": " << minbs << endl << endl;
		tc++;
	}

	return 0;
}