#include<iostream>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, d[200000];
	cin >> n;
	n--;
	int l;
	cin >> l;
	for(int i = 0, c; i < n; i++) {
		cin >> c;
		d[i] = c - l;
		l = c;
	}

	ll ans = 0;
	for(int i = 0; i < n; i++) {
		int j = i;
		while(j < n && d[i] == d[j])
			j++;
		l = j - i + 1;
		ans += (ll)l * ((ll)l + (ll)1) / (ll)2 - (ll)1;
		i = j - 1;
	}

	cout << ans + 1;

	return 0;
}