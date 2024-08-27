#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'
typedef pair<int,int> ii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	ii pref[105];
	for(int i = 0; i < n; i++)
		cin >> pref[i].second >> pref[i].first;

	sort(pref, pref + n);
	int gaps = 0, r = pref[0].first;
	for(int i = 1; i < n; i++) {
		if (pref[i].second > r) {
			gaps++;
			r = pref[i].first;
		}
	}

	cout << gaps + 1;

	return 0;
}