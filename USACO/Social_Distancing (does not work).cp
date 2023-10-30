#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

#define endl '\n'
#define ll long long
#define pll pair<ll,ll>
#define vpll vector<pll>

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ifstream cin("socdist.in");
	ofstream cout("socdist.out"); 

	int n, m;
	cin >> n >> m;
	vpll v(m);
	for(pll &i : v) cin >> i.first >> i.second;

	sort(v.begin(), v.end());

	int lo = 1, hi = v[m - 1].second + 1; 
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		
		ll pos = -1;
		int cows = 0;
		for (pll i : v) {
			while(max(pos + mid, i.first) <= i.second) {
				pos = max(pos + mid, i.first);
				cows++;
				if (cows == n) break;
			}
			if (cows == n) break;
		}

		if (cows == n) lo = mid + 1;
		else hi = mid - 1;
	}
	
	cout << lo << endl;

	return 0;
}