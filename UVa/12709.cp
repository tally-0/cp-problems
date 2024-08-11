#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	pair<int, int> ants[101];
	while(cin >> t && t) {
		for(int i = 0, l, w, h; i < t; i++) {
			cin >> l >> w >> h;
			ants[i].first = h;
			ants[i].second = l * w * h;
		}
		
		sort(ants, ants + t);

		cout << ants[t - 1].second << endl;
	}

	return 0;
}