#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ii pair<int,int>
#define vii vector<pair<int,int>>

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cases, M, a, b;
	cin >> cases;

	while(cases--) {
		cin >> M;
		vii segs;
		while(cin >> a >> b && a+b != 0) segs.push_back(make_pair(a, b));

		sort(segs.begin(), segs.end(), [] (ii lhs, ii rhs) {
			if (lhs.first == rhs.first) {
				return lhs.second > rhs.second;
			}
			return lhs.first < rhs.first;
		});

		int end = 0, i = 0;
		vii used;
		while(end < M) {
			int maxi = -1, maxr = end;
			while(segs[i].first <= end && i < segs.size()) {
				if (segs[i].second > maxr) { 
					maxi = i; 
					maxr = segs[i].second;
				}
				i++;
			}
			if (maxi == -1) break;
			used.push_back(segs[maxi]);
			end = segs[maxi].second;
		}
		if (end >= M) {
				cout << used.size() << endl;
				for(auto a : used) cout << a.first << " " << a.second << endl;
		} else cout << 0 << endl;
		if (cases) cout << endl;
	}
	return 0;
}