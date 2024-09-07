#include<iostream>
#include<algorithm>
#include<fstream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ifstream cin("cardgame.in");
	ofstream cout("cardgame.out");

	int n, b[100001] = { false }, o[50000];
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> o[i];
		b[o[i]] = true;
	}

	sort(o, o + n / 2, greater<int>());
	sort(o + n / 2, o + n);

	int j = 2 * n, ans = 0;
	for(int i = 0; i < n / 2 && j > 0; i++) {
		while(j > 1 && b[j])
			j--;
		if (!b[j] && j > o[i]) {
			ans++;
			j--;
		}
	}
	j = 1;
	for(int i = n / 2; i < n && j <= 2 * n; i++) {
		while(j < 2 * n && b[j])
			j++;
		if (!b[j] && j < o[i]) {
			ans++;
			j++;
		}
	}

	cout << ans << endl;

	return 0;
}