#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define dd pair<double,double>
#define vdd vector<dd>

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	double l, p, r, w;
	while(cin >> n >> l >> w) {
		vdd inters;
		for(int i = 0; i < n; i++) {
			cin >> p >> r;
			if (r * 2 > w) {
				double eddRad = sqrt(r * r - w * w / 4.0);
				inters.push_back(make_pair(p - eddRad, p + eddRad));
			}
		}
	
		sort(inters.begin(), inters.end(), [] (const dd &lhs, const dd &rhs) {
			if (lhs.first == rhs.first) return lhs.second > rhs.second;
			return lhs.first < rhs.first;
		});

		double end = 0, maxr = 0;
		int res = 0, i = 0;
		n = inters.size();
		while(end < l) {
			maxr = end;
			while(i < n && inters[i].first <= end) {
				maxr = max(maxr, inters[i].second);
				i++;
			}
			if (end == maxr) {
				res = -1;
				break;
			}
			res++;
			end = maxr;
		}
		cout << res << endl;
	}
	return 0;
}